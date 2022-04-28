#include <QtWidgets>
#include <QDebug>
#include "codeeditor.h"
//![constructor]

CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
    connect(this,SIGNAL(cursorPositionChanged()),this,SLOT(showCompleteWidget()));

    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
    //set color value
    lineColor.setRgb(139,99,108);
    editorColor.setRgb(255,228,225);//34,39,49

    QPalette p = this->palette();
    p.setColor(QPalette::Active, QPalette::Base,editorColor);
    p.setColor(QPalette::Inactive, QPalette::Base,editorColor);
    p.setColor(QPalette::Text,Qt::black);//wenziyanse
    this->setPalette(p);
    setUpCompleteList();
    completeWidget= new CompleteListWidget(this);
    completeWidget->hide();
    completeWidget->setMaximumHeight(fontMetrics().height()*5);
    completeState=CompleteState::Hide;
}

int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }
    if(digits<3)digits=3;

    int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}

//![extraAreaWidth]
//![slotUpdateExtraAreaWidth]

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}


void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);

}


void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}



void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::red).lighter(160);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

//![cursorPositionChanged]

//![extraAreaPaintEvent_0]

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), lineColor);

//![extraAreaPaintEvent_0]

//![extraAreaPaintEvent_1]
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
//![extraAreaPaintEvent_1]

//![extraAreaPaintEvent_2]
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::white);//hanghaoyanse
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignCenter, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}
//![extraAreaPaintEvent_2]


void CodeEditor::keyPressEvent(QKeyEvent *event){
  if(event->modifiers()==Qt::ShiftModifier&&event->key()==40){
      this->insertPlainText(tr("()"));
      this->moveCursor(QTextCursor::PreviousCharacter);
    }
  else if(event->modifiers()==Qt::ShiftModifier&&event->key()==34){
      this->insertPlainText(tr("\"\""));
      this->moveCursor(QTextCursor::PreviousCharacter);
    }
  else if(event->key()==16777235&&completeState==CompleteState::Showing){
      if(completeWidget->currentRow()>0)
        completeWidget->setCurrentRow(completeWidget->currentRow()-1);
    }
  else if(event->key()==16777237&&(completeState==CompleteState::Showing)){
      if(completeWidget->currentRow()<completeWidget->count()-1)
        completeWidget->setCurrentRow(completeWidget->currentRow()+1);
    }
  else if(event->key()==Qt::Key_Return&&(completeState==CompleteState::Showing)){
      QString insertText=completeWidget->currentItem()->text();
      QString word=this->getWordOfCursor();
      completeState=CompleteState::Ignore;
      for(int i=0;i<word.count();++i)
        this->textCursor().deletePreviousChar();
      this->insertPlainText(insertText);
      if(insertText.contains(tr("#include")))
        this->moveCursor(QTextCursor::PreviousCharacter);
      completeState=CompleteState::Hide;
      completeWidget->hide();
    }//*
  else if(event->key()==Qt::Key_Return){
      QString temp;
      temp =this->document()->findBlockByLineNumber(this->textCursor().blockNumber()).text();
      QPlainTextEdit::keyPressEvent(event);
      if(temp.count()<=0)return;
      foreach(const QChar &c,temp){
          if(c.isSpace())this->insertPlainText(c);
          else break;
        }

      if(temp.at(temp.count()-1)==')'&&(temp.contains(tr("for("))||temp.contains(tr("while("))
                                        ||temp.contains(tr("switch("))||temp.contains(tr("if("))))
          this->insertPlainText(tr("\t"));

      if(temp.at(temp.count()-1)=='{'){
          this->insertPlainText(tr("\t"));
          QTextCursor cursor=this->textCursor();
          int pos=this->textCursor().position();
          this->insertPlainText(tr("\n"));
          foreach(const QChar &c,temp){
              if(c.isSpace())this->insertPlainText(c);
              else break;
            }
          this->insertPlainText(tr("}"));
          cursor.setPosition(pos);
          this->setTextCursor(cursor);
        }
    }
  else if(event->key()==Qt::Key_Backspace){
      switch(this->document()->characterAt(this->textCursor().position()-1).toLatin1()){
        case '(':
          QPlainTextEdit::keyPressEvent(event);
          if(this->document()->characterAt(this->textCursor().position())==')'){
              this->textCursor().deleteChar();
            }break;
        case '\"':
          QPlainTextEdit::keyPressEvent(event);
          if(this->document()->characterAt(this->textCursor().position())=='\"'){
              this->textCursor().deleteChar();
            }break;
        case '<':
          QPlainTextEdit::keyPressEvent(event);
          if(this->document()->characterAt(this->textCursor().position())=='>'){
              this->textCursor().deleteChar();
            }break;
        default:
          QPlainTextEdit::keyPressEvent(event);
        }
    }
  else
    QPlainTextEdit::keyPressEvent(event);

}
void CodeEditor::setUpCompleteList(){
  completeList<< "char" << "class" << "const"
              << "double" << "enum" << "explicit"
              << "friend" << "inline" << "int"
              << "long" << "namespace" << "operator"
              << "private" << "protected" << "public"
              << "short" << "signals" << "signed"
              << "slots" << "static" << "struct"
              << "template" << "typedef" << "typename"
              << "union" << "unsigned" << "virtual"
              << "void" << "volatile" << "bool"<<"using"<<"constexpr"
              <<"sizeof"<<"if"<<"for"<<"foreach"<<"while"<<"do"<<"case"
              <<"break"<<"continue"<<"template"<<"delete"<<"new"
              <<"default"<<"try"<<"return"<<"throw"<<"catch"<<"goto"<<"else"
              <<"extren"<<"this"<<"switch"<<"#include <>"<<"#include \"\""<<"#define"<<"iostream";}

QString CodeEditor::getWordOfCursor(){
  int pos=this->textCursor().position()-1;
  QVector<QChar> words;
  QString result;
  QChar ch=this->document()->characterAt(pos+1);
  if(ch.isDigit()||ch.isLetter()||ch==' ')return result;
  ch=this->document()->characterAt(pos);
  if(ch==' ')return result;
  while(ch.isDigit()||ch.isLetter()||ch=='_'||ch=='#'){
      words.append(ch);
      pos--;
      ch=this->document()->characterAt(pos);
    }
  for(int i=words.size()-1;i>=0;i--)
    result+=words[i];
  return result;
}

void CodeEditor::showCompleteWidget(){
  if(completeState==CompleteState::Ignore)return;
  completeWidget->hide();
  completeState=CompleteState::Hide;
  QString word=this->getWordOfCursor();
  completeWidget->clear();
  if(!word.isEmpty()){
      int maxSize=0;
      QMap<QString,int> distance;
      vector<QString> itemList;
      foreach(const QString &temp,completeList){
          if(temp.contains(word)){

              itemList.push_back(temp);
              distance[temp]=CompleteListWidget::ldistance(temp.toStdString(),word.toStdString());
              if(temp.length()>maxSize)maxSize=temp.length();

            }
        }

      if(itemList.size()>0){
      sort(itemList.begin(),itemList.end(),[&](const QString &s1,const QString &s2)->bool{return distance[s1]<distance[s2]; });
      foreach(const QString& item,itemList){
          completeWidget->addItem(new QListWidgetItem(item));
        }

      int x=this->getCompleteWidgetX();
      int y=this->cursorRect().y()+fontMetrics().height();

      completeWidget->move(x,y);
      if(completeWidget->count()>5)completeWidget->setFixedHeight(fontMetrics().height()*6);
      else completeWidget->setFixedHeight(fontMetrics().height()*(completeWidget->count()+1));
      completeWidget->setFixedWidth((fontMetrics().width(QLatin1Char('9'))+6)*maxSize);
      completeWidget->show();
      completeState=CompleteState::Showing;
      completeWidget->setCurrentRow(0,QItemSelectionModel::Select);
        }
    }

}
int CodeEditor::getCompleteWidgetX(){
  QTextCursor cursor=this->textCursor();
  int pos=cursor.position()-1;
  int origianlPos=pos+1;
  QChar ch;
  ch=this->document()->characterAt(pos);
  while((ch.isDigit()||ch.isLetter()||ch=='_'||ch=='#')&&pos>0){
      pos--;
      ch=this->document()->characterAt(pos);
    }
  pos++;
  completeState=CompleteState::Ignore;
  cursor.setPosition(pos);
  this->setTextCursor(cursor);
  int x=this->cursorRect().x()+2*fontMetrics().width(QLatin1Char('9'));
  cursor.setPosition(origianlPos);
  this->setTextCursor(cursor);
  completeState=CompleteState::Hide;
  return x;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <string.h>
#include <iostream>
#include "cifafinxi.h"
#include "cifa.h"
#include <string>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include "yufa.h"
#include "fourtuper.h"
#include "jieshi.h"

using namespace std;
#pragma execution_character_set("utf-8")


char fileread2[]="D:/YY's-Editor-master/YY's-Editor-master/CIFA.txt";
char filewrite2[]="D:/YY's-Editor-master/YY's-Editor-master/FOUR.txt";



MainWindow::MainWindow(QWidget *parent):
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  firstLoad=true;
  ui->setupUi(this);
  setUpHighlighter();
  //init status bar
  ui->outputText->parentWindow=this;
  ui->statusBar->showMessage(tr("Ready"));
  //--------init toolbar------------
  //ui->statusBar->setStyleSheet("QStatusBar{background:rgb(139,71,93);}");//50,50,50
  ui->mainToolBar->setMovable(false);
  ui->mainToolBar->setStyleSheet("QToolButton:hover {background-color:darkgray} QToolBar {background: rgb(139,58,98);border: none;}");//82,82,82
  //--------------------------------

  runIcon.addPixmap(QPixmap(":/image/Run.png"));
  stopIcon.addPixmap(QPixmap(":/image/stop.png"));

  //---------background-------------
  QPalette windowPalette=this->palette();
  windowPalette.setColor(QPalette::Active,QPalette::Window,QColor(139,58,98));//82,82,82
  windowPalette.setColor(QPalette::Inactive,QPalette::Window,QColor(139,58,98));//82,82,82
  this->setPalette(windowPalette);
  //--------------------------------
  initFileData();
  connect(ui->actionNewFile,SIGNAL(triggered(bool)),this,SLOT(newFile()));
  connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openFile()));
  connect(ui->actionSave_File,SIGNAL(triggered(bool)),this,SLOT(saveFile()));
  connect(ui->actionUndo,SIGNAL(triggered(bool)),this,SLOT(undo()));
  connect(ui->actionRedo,SIGNAL(triggered(bool)),this,SLOT(redo()));
  connect(ui->editor,SIGNAL(textChanged()),this,SLOT(changeSaveState()));
  connect(ui->actionRun,SIGNAL(triggered(bool)),this,SLOT(run()));
  connect(&process,SIGNAL(finished(int)),this,SLOT(runFinished(int)));
  connect(&process,SIGNAL(readyReadStandardOutput()),this,SLOT(updateOutput()));
  connect(&process,SIGNAL(readyReadStandardError()),this,SLOT(updateError()));
  connect(ui->actionAbout,SIGNAL(triggered(bool)),this,SLOT(about()));
  fileSaved=true;
}


MainWindow::~MainWindow()
{
  delete ui;
}
void MainWindow::setUpHighlighter(){
  QFont font;
  font.setFamily("Courier");
  font.setFixedPitch(true);
  //font.setPointSize(20);
  ui->editor->setFont(font);
  ui->editor->setTabStopWidth(fontMetrics().width(QLatin1Char('9'))*4);
  highlighter=new Highlighter(ui->editor->document());
}

void MainWindow::resizeEvent(QResizeEvent *event){
  QMainWindow::resizeEvent(event);
  ui->editor->setGeometry(10,0,width()-20,height()-ui->statusBar->height()-ui->mainToolBar->height()-350-15);
  ui->outputText->setGeometry(10,ui->editor->height()+10,this->width()-20,350);//窗口大小
}
void MainWindow::initFileData(){
  fileName=tr("Untitled.cpp");
  filePath=tr("~/Desktop/Untitled.cpp");
  fileSaved=true;
  isRunning=false;
}
void MainWindow::undo(){
  ui->editor->undo();
}
void MainWindow::redo(){
  ui->editor->redo();
}
void MainWindow::saveFile(){
  QString savePath=QFileDialog::getSaveFileName(this,tr("选择保存路径与文件名"),fileName,tr("Cpp File(*.cpp *.c *.h)"));
  if(!savePath.isEmpty()){
      QFile out(savePath);
      out.open(QIODevice::WriteOnly|QIODevice::Text);
      QTextStream str(&out);
      str<<ui->editor->toPlainText();
      out.close();
      fileSaved=true;
      QRegularExpression re(tr("(?<=\\/)\\w+\\.cpp|(?<=\\/)\\w+\\.c|(?<=\\/)\\w+\\.h"));
      fileName=re.match(savePath).captured();
      filePath=savePath;
      this->setWindowTitle(tr("YY's Editor - ")+fileName);
    }
}
//xinjiancppfile
void MainWindow::newFile(){
  MainWindow *newWindow=new MainWindow();
  QRect newPos=this->geometry();
  newWindow->setGeometry(newPos.x()+10,newPos.y()+10,newPos.width(),newPos.height());
  newWindow->show();
}
void MainWindow::openFile(){
  if(!fileSaved){
      if(QMessageBox::Save==QMessageBox::question(this,tr("file not save"),tr("save or not"),QMessageBox::Save,QMessageBox::Cancel))
        saveFile();
    }
  QString openPath=QFileDialog::getOpenFileName(this,tr("choose file to open"),filePath,tr("Cpp File(*.cpp *.c *.txt)"));
  if(!openPath.isEmpty()){
      QFile in(openPath);
      in.open(QIODevice::ReadOnly|QIODevice::Text);
      QTextStream str(&in);
      ui->editor->setPlainText(str.readAll());
      QRegularExpression re(tr("(?<=\\/)\\w+\\.cpp|(?<=\\/)\\w+\\.c|(?<=\\/)\\w+\\.txt"));
      fileName=re.match(openPath).captured();
      this->setWindowTitle(tr("YY's Editor - ")+fileName);
      filePath=openPath;
      fileSaved=true;
      QByteArray ba=filePath.toLatin1();
      fileread=ba.data();
      cout<<fileread<<endl;
      strcpy(fileread1,fileread);
    }
}
void MainWindow::run(){
  if(isRunning){
      process.terminate();
      ui->actionRun->setIcon(runIcon);
      return;
    }
  if(!fileSaved){
      if(QMessageBox::Save==QMessageBox::question(this,tr("file not save"),tr("save or not"),QMessageBox::Save,QMessageBox::Cancel))
        saveFile();
    }
  if(fileSaved){
    //if(process!=nullptr)delete process;
    isRunning=true;
    ui->statusBar->showMessage(tr("code loading"));
    ui->outputText->clear();
    output.clear();
    error.clear();
    QString buildPath;
    QRegularExpression re(tr(".*(?=\\.cpp)|.*(?=\\.c)|.*(?=\\.h)"));
    buildPath=re.match(filePath).captured();
    //qDebug()<<buildPath;
    process.start("bash", QStringList() << "-c" << QString(tr("g++ ")+filePath+tr(" -o ")+buildPath+tr(";")+buildPath));
    process.waitForStarted();
    ui->outputText->setFocus();
    ui->actionRun->setIcon(stopIcon);
    }
}
void MainWindow::runFinished(int code){
  ui->actionRun->setIcon(runIcon);
  isRunning=false;
  qDebug()<<tr("exit code=")<<code;
  ui->statusBar->showMessage(tr("Ready"));
}
void MainWindow::updateOutput(){
  output=QString::fromLocal8Bit(process.readAllStandardOutput());
  //ui->outputText->setPlainText(output+tr("\n")+error);
  ui->outputText->setPlainText(ui->outputText->toPlainText()+output);//+tr("\n"));
}
void MainWindow::updateError(){
  error=QString::fromLocal8Bit(process.readAllStandardError());
  //ui->outputText->setPlainText(output+tr("\n")+error);
  ui->outputText->setPlainText(ui->outputText->toPlainText()+error);//+tr("\n"));
  process.terminate();
  isRunning=false;
}
void MainWindow::inputData(QString data){
  if(isRunning)process.write(data.toLocal8Bit());
}
void MainWindow::closeEvent(QCloseEvent *event){
  if(!fileSaved){
      if(QMessageBox::Save==QMessageBox::question(this,tr("not save,end or not"),tr("please save"),QMessageBox::Save,QMessageBox::Cancel))
        saveFile();
      fileSaved=true;
    }
}
void MainWindow::about(){
  QMessageBox::information(this,tr("about"),tr(" YY's-Editor v1.0\n for more huajihome.cn"),QMessageBox::Ok);
}

void MainWindow::on_actionDocument_triggered()//readme
{

}

void MainWindow::on_actionlexical_analysis_triggered()
{
    this->close();
    Cifa->show();
    Cifa->exec();
    this->show();
}

string num_str(int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

void MainWindow::on_actionRun_triggered()//yunxinganniu
{
    FILE *fp1 = fopen(fileread1, "r");
    FILE *fp2 = fopen(filewrite, "w");
    lexical LEX;
    syntactic SYN;
    quater QUA;
    FILE *fp3,*fp4;
    if(fp1 == NULL)
    {
        cout << "open the fileread failed!" << endl;
        exit(0);
    }
    if(fp2 == NULL)
    {
        cout << "open the filewrite failed!" << endl;
        exit(0);
    }

    cout << "source program" << endl;
    while((ch = fgetc(fp1)) != EOF)
        cout << ch;

    cout << endl << endl;
    cout << "____________" << endl;
    fseek(fp1, 0L, SEEK_SET);

    scan(fp1);
    while(syn != 0)
    {
        switch(syn)
        {
            case 22: cout << syn << " " << sum_int <<endl;
                     fprintf(fp2, "%d %d\n", syn, sum_int);
                     break;
            case 23: cout <<syn << " " << sum_float <<endl;
                     fprintf(fp2, "%d %f\n", syn, sum_float);
                     break;
            case -1: cout << "Error in row " << row << "!" << endl;
                     fprintf(fp2, "Error in row %d!\n", row);
                     break;
            case -2: row++;
                     break;
            case -3: break;
            case 0:  break;
            default: cout << syn << " " << token << endl;
                     fprintf(fp2, "%d %s\n", syn, token);
                     break;
        }
        scan(fp1);
    }
    fclose(fp1);
    fclose(fp2);
    if((fp3=fopen(fileread2, "r"))==NULL)
    {
        cout << "Open the file failed!" << endl;
        exit(0);
    }
    LEX.save(fp3);
    fclose(fp3);

    SYN.sym = LEX.getsym();
    cout << "yufafenxi:" << endl;
    SYN.A();

    if((fp4=fopen(filewrite2, "w"))==NULL)
    {
        cout << "Open the file failed!" << endl;
        exit(0);
    }
    cout <<endl<<"four tuper:"<<endl;
    QUA.disp(fp4);
    fclose(fp4);



//jieshi
    transform1 TRAA;
    lexical1 LEXX;
    jieshi INT;
    output1 OUTT;

    FILE* fp5;
    if((fp5=fopen(fileread3, "r")) == NULL)
    {
        cout << "Open the file failed!" << endl;
        exit(0);
    }
    LEXX.save(fp5);
    fclose(fp5);

    INT.sym = LEXX.getsym();
    cout << "YUFAFENXI:" << endl;
    INT.A();

    fp5 = fopen(filewrite3, "w");
    OUTT.define(fp5);
    OUTT.middle(fp5);
    OUTT.answer(fp5);
    fclose(fp5);

    QFile inputFile2(tr("D:/YY's-Editor-master/YY's-Editor-master/JIESHI.txt"));
    inputFile2.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile2);
    QString line = in.readAll();
    inputFile2.close();
    ui->outputText->setPlainText(tr(line.toStdString().c_str()));
}

void MainWindow::on_actionFour_Tuple_triggered()
{
    this->close();
    Fourtuper->show();
    Fourtuper->exec();
    this->show();
}

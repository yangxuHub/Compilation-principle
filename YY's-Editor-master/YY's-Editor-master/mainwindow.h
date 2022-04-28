#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "highlighter.h"
#include "cifa.h"
#include "fourtuper.h"
#include <QRegularExpression>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include <iostream>
#include <stdio.h>
using namespace std;
#include <string.h>
#include <math.h>


void scan(FILE *fp);



namespace Ui{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
private:
  QIcon runIcon;
  QIcon stopIcon;
  Ui::MainWindow *ui;
  Highlighter *highlighter;
  cifa *Cifa=new cifa;
  fourtuper *Fourtuper=new fourtuper;
  QProcess process;
  void setUpHighlighter();

  QString fileName;
  QString filePath;
  bool fileSaved;
  bool isRunning;
  //bool fileEdited;
  void initFileData();
  bool firstLoad;
  //-----------------------------


  //---------code running data---
  QString output;
  QString error;
  //-----------------------------
public slots:
  void changeSaveState(){
    //qDebug()<<"changed";
    if(firstLoad&&fileSaved){
        this->setWindowTitle(tr("YY's Editor - ")+fileName);
        firstLoad=false;
        return;
      }
    fileSaved=false;
    this->setWindowTitle(tr("YY's Editor - ")+fileName+tr("*"));
  }

  //---------工具栏响应函数---------
  void newFile();
  void saveFile();
  void openFile();
  void undo();
  void redo();
  void run();
  //------------------------------
  void runFinished(int code);
  void updateOutput();
  void updateError();
  void about();
public:
  void inputData(QString data);
protected:
  void resizeEvent(QResizeEvent* event)override;
  void closeEvent(QCloseEvent* event)override;
//private slots:
 // void on_editor_blockCountChanged(int newBlockCount);
private slots:
  void on_actionRun_triggered();
  void on_actionDocument_triggered();
  void on_actionlexical_analysis_triggered();
  void on_actionFour_Tuple_triggered();
};

#endif // MAINWINDOW_H

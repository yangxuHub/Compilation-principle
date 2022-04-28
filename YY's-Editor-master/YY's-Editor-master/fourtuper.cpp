#include "fourtuper.h"
#include "ui_fourtuper.h"
#include "qfile.h"
#include "qdebug.h"
#pragma execution_character_set("utf-8")

fourtuper::fourtuper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fourtuper)
{
    ui->setupUi(this);
    QFile inputFile(tr("D:/YY's-Editor-master/YY's-Editor-master/FOUR.txt"));
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();
    ui->four->setPlainText(tr(line.toStdString().c_str()));
}

fourtuper::~fourtuper()
{
    delete ui;
}

void fourtuper::on_pushButton_clicked()
{
     this->close();
}

#include "cifa.h"
#include "ui_cifa.h"
#include "qfile.h"
#include "qdebug.h"
#pragma execution_character_set("utf-8")

cifa::cifa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cifa)
{
    ui->setupUi(this);
    QFile inputFile(tr("D:/YY's-Editor-master/YY's-Editor-master/CIFA.txt"));
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();
    ui->cifareault->setPlainText(tr(line.toStdString().c_str()));
}

cifa::~cifa()
{
    delete ui;
}


void cifa::on_pushButton_clicked()
{
    this->close();
}

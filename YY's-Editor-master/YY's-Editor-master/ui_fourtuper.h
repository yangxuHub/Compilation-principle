/********************************************************************************
** Form generated from reading UI file 'fourtuper.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOURTUPER_H
#define UI_FOURTUPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_fourtuper
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QTextBrowser *four;

    void setupUi(QDialog *fourtuper)
    {
        if (fourtuper->objectName().isEmpty())
            fourtuper->setObjectName(QString::fromUtf8("fourtuper"));
        fourtuper->resize(512, 455);
        pushButton = new QPushButton(fourtuper);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 350, 131, 51));
        label = new QLabel(fourtuper);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 111, 21));
        four = new QTextBrowser(fourtuper);
        four->setObjectName(QString::fromUtf8("four"));
        four->setGeometry(QRect(40, 40, 401, 281));

        retranslateUi(fourtuper);

        QMetaObject::connectSlotsByName(fourtuper);
    } // setupUi

    void retranslateUi(QDialog *fourtuper)
    {
        fourtuper->setWindowTitle(QCoreApplication::translate("fourtuper", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("fourtuper", "\350\277\224\345\233\236Editor", nullptr));
        label->setText(QCoreApplication::translate("fourtuper", "\345\233\233\345\205\203\347\273\204\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fourtuper: public Ui_fourtuper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOURTUPER_H

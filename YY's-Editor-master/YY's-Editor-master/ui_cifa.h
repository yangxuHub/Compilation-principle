/********************************************************************************
** Form generated from reading UI file 'cifa.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIFA_H
#define UI_CIFA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_cifa
{
public:
    QPushButton *pushButton;
    QTextBrowser *cifareault;
    QLabel *label;

    void setupUi(QDialog *cifa)
    {
        if (cifa->objectName().isEmpty())
            cifa->setObjectName(QString::fromUtf8("cifa"));
        cifa->resize(520, 396);
        pushButton = new QPushButton(cifa);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 340, 131, 41));
        cifareault = new QTextBrowser(cifa);
        cifareault->setObjectName(QString::fromUtf8("cifareault"));
        cifareault->setGeometry(QRect(40, 40, 391, 261));
        label = new QLabel(cifa);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 0, 121, 31));
        label->setMinimumSize(QSize(111, 31));

        retranslateUi(cifa);

        QMetaObject::connectSlotsByName(cifa);
    } // setupUi

    void retranslateUi(QDialog *cifa)
    {
        cifa->setWindowTitle(QCoreApplication::translate("cifa", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("cifa", "\350\277\224\345\233\236Editor", nullptr));
        label->setText(QCoreApplication::translate("cifa", "\350\257\215\346\263\225\345\210\206\346\236\220\347\273\223\346\236\234\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cifa: public Ui_cifa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIFA_H

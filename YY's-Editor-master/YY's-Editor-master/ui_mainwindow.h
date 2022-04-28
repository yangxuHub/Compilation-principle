/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <codeeditor.h>
#include <console.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewFile;
    QAction *actionOpen;
    QAction *actionSelectAll;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionAbout;
    QAction *actionDocument;
    QAction *actionSave_File;
    QAction *actionRun;
    QAction *actionSetting;
    QAction *actionlexical_analysis;
    QAction *actionFour_Tuple;
    QWidget *centralWidget;
    CodeEditor *editor;
    Console *outputText;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuEdit_O;
    QMenu *menuHelp_H;
    QMenu *menuadd;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(630, 508);
        actionNewFile = new QAction(MainWindow);
        actionNewFile->setObjectName(QString::fromUtf8("actionNewFile"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/New.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewFile->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        QFont font;
        font.setPointSize(9);
        actionOpen->setFont(font);
        actionSelectAll = new QAction(MainWindow);
        actionSelectAll->setObjectName(QString::fromUtf8("actionSelectAll"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/Undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon2);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/Redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon3);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionDocument = new QAction(MainWindow);
        actionDocument->setObjectName(QString::fromUtf8("actionDocument"));
        actionSave_File = new QAction(MainWindow);
        actionSave_File->setObjectName(QString::fromUtf8("actionSave_File"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_File->setIcon(icon4);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/Run.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon5);
        actionSetting = new QAction(MainWindow);
        actionSetting->setObjectName(QString::fromUtf8("actionSetting"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/Setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetting->setIcon(icon6);
        actionSetting->setVisible(false);
        actionlexical_analysis = new QAction(MainWindow);
        actionlexical_analysis->setObjectName(QString::fromUtf8("actionlexical_analysis"));
        actionFour_Tuple = new QAction(MainWindow);
        actionFour_Tuple->setObjectName(QString::fromUtf8("actionFour_Tuple"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        editor = new CodeEditor(centralWidget);
        editor->setObjectName(QString::fromUtf8("editor"));
        editor->setGeometry(QRect(10, 0, 611, 241));
        outputText = new Console(centralWidget);
        outputText->setObjectName(QString::fromUtf8("outputText"));
        outputText->setGeometry(QRect(10, 250, 611, 401));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 630, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuEdit_O = new QMenu(menuBar);
        menuEdit_O->setObjectName(QString::fromUtf8("menuEdit_O"));
        menuHelp_H = new QMenu(menuBar);
        menuHelp_H->setObjectName(QString::fromUtf8("menuHelp_H"));
        menuadd = new QMenu(menuBar);
        menuadd->setObjectName(QString::fromUtf8("menuadd"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setIconSize(QSize(24, 24));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuEdit_O->menuAction());
        menuBar->addAction(menuHelp_H->menuAction());
        menuBar->addAction(menuadd->menuAction());
        menu->addAction(actionNewFile);
        menu->addAction(actionOpen);
        menu->addAction(actionSave_File);
        menuEdit_O->addAction(actionSelectAll);
        menuEdit_O->addAction(actionUndo);
        menuEdit_O->addAction(actionRedo);
        menuHelp_H->addAction(actionAbout);
        menuHelp_H->addAction(actionDocument);
        menuadd->addAction(actionlexical_analysis);
        menuadd->addAction(actionFour_Tuple);
        mainToolBar->addAction(actionNewFile);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave_File);
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);
        mainToolBar->addAction(actionSetting);
        mainToolBar->addAction(actionRun);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "HJ Editor", nullptr));
        actionNewFile->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(tooltip)
        actionNewFile->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\344\270\200\344\270\252C++\344\273\243\347\240\201\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNewFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200...", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266...", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelectAll->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
#if QT_CONFIG(tooltip)
        actionSelectAll->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\205\250\351\203\250\346\226\207\346\234\254", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSelectAll->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\201\232", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216 YY's Editor", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216 HJ Editor", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDocument->setText(QCoreApplication::translate("MainWindow", "Readme", nullptr));
#if QT_CONFIG(tooltip)
        actionDocument->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>YY's Editor \346\223\215\344\275\234\350\257\264\346\230\216:</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSave_File->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        actionSave_File->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave_File->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRun->setText(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\214", nullptr));
#if QT_CONFIG(tooltip)
        actionRun->setToolTip(QCoreApplication::translate("MainWindow", "\347\274\226\350\257\221\345\271\266\350\277\220\350\241\214\344\273\243\347\240\201", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionRun->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSetting->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        actionSetting->setToolTip(QCoreApplication::translate("MainWindow", "\346\233\264\346\224\271\347\274\226\350\276\221\345\231\250\347\232\204\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        actionlexical_analysis->setText(QCoreApplication::translate("MainWindow", "Lexical Analysis", nullptr));
        actionFour_Tuple->setText(QCoreApplication::translate("MainWindow", "Four Tuple\n"
"\n"
"", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuEdit_O->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menuHelp_H->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        menuadd->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

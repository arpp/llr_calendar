/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 22. Jan 18:57:40 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuick_Connect;
    QAction *actionReconnect;
    QAction *actionLogin;
    QAction *actionSignUp;
    QAction *actionExit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        actionQuick_Connect = new QAction(MainWindow);
        actionQuick_Connect->setObjectName(QString::fromUtf8("actionQuick_Connect"));
        actionReconnect = new QAction(MainWindow);
        actionReconnect->setObjectName(QString::fromUtf8("actionReconnect"));
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionSignUp = new QAction(MainWindow);
        actionSignUp->setObjectName(QString::fromUtf8("actionSignUp"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuick_Connect);
        menuFile->addAction(actionReconnect);
        menuFile->addSeparator();
        menuFile->addAction(actionLogin);
        menuFile->addAction(actionSignUp);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuick_Connect->setText(QApplication::translate("MainWindow", "Quick Connect", 0, QApplication::UnicodeUTF8));
        actionReconnect->setText(QApplication::translate("MainWindow", "Reconnect", 0, QApplication::UnicodeUTF8));
        actionLogin->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        actionSignUp->setText(QApplication::translate("MainWindow", "SignUp", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

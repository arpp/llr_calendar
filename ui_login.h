/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Wed 6. Feb 21:51:00 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *usernameLabel;
    QLabel *passerwordLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *username;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *login;
    QPushButton *cancel;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(184, 101);
        horizontalLayout_3 = new QHBoxLayout(Login);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        usernameLabel = new QLabel(Login);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        QFont font;
        font.setPointSize(10);
        usernameLabel->setFont(font);

        verticalLayout->addWidget(usernameLabel);

        passerwordLabel = new QLabel(Login);
        passerwordLabel->setObjectName(QString::fromUtf8("passerwordLabel"));
        passerwordLabel->setFont(font);

        verticalLayout->addWidget(passerwordLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        username = new QLineEdit(Login);
        username->setObjectName(QString::fromUtf8("username"));

        verticalLayout_2->addWidget(username);

        password = new QLineEdit(Login);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(password);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        login = new QPushButton(Login);
        login->setObjectName(QString::fromUtf8("login"));

        horizontalLayout_2->addWidget(login);

        cancel = new QPushButton(Login);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout_2->addWidget(cancel);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);


        retranslateUi(Login);
        QObject::connect(cancel, SIGNAL(clicked()), Login, SLOT(close()));
        QObject::connect(login, SIGNAL(clicked()), Login, SLOT(accept()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", 0, QApplication::UnicodeUTF8));
        usernameLabel->setText(QApplication::translate("Login", "Username", 0, QApplication::UnicodeUTF8));
        passerwordLabel->setText(QApplication::translate("Login", "Password", 0, QApplication::UnicodeUTF8));
        login->setText(QApplication::translate("Login", "Login", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("Login", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

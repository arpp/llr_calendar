/********************************************************************************
** Form generated from reading UI file 'networksetup.ui'
**
** Created: Wed 6. Feb 21:51:00 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKSETUP_H
#define UI_NETWORKSETUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NetworkSetup
{
public:
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelServerAddress;
    QLineEdit *address;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelServerPort;
    QSpacerItem *horizontalSpacer;
    QLineEdit *port;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NetworkSetup)
    {
        if (NetworkSetup->objectName().isEmpty())
            NetworkSetup->setObjectName(QString::fromUtf8("NetworkSetup"));
        NetworkSetup->resize(313, 72);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NetworkSetup->sizePolicy().hasHeightForWidth());
        NetworkSetup->setSizePolicy(sizePolicy);
        horizontalLayout_6 = new QHBoxLayout(NetworkSetup);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelServerAddress = new QLabel(NetworkSetup);
        labelServerAddress->setObjectName(QString::fromUtf8("labelServerAddress"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        labelServerAddress->setFont(font);

        horizontalLayout->addWidget(labelServerAddress);

        address = new QLineEdit(NetworkSetup);
        address->setObjectName(QString::fromUtf8("address"));
        sizePolicy.setHeightForWidth(address->sizePolicy().hasHeightForWidth());
        address->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(address);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelServerPort = new QLabel(NetworkSetup);
        labelServerPort->setObjectName(QString::fromUtf8("labelServerPort"));
        labelServerPort->setFont(font);

        horizontalLayout_4->addWidget(labelServerPort);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        port = new QLineEdit(NetworkSetup);
        port->setObjectName(QString::fromUtf8("port"));

        horizontalLayout_4->addWidget(port);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(NetworkSetup);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_5->addWidget(buttonBox);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        retranslateUi(NetworkSetup);
        QObject::connect(buttonBox, SIGNAL(accepted()), NetworkSetup, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NetworkSetup, SLOT(reject()));

        QMetaObject::connectSlotsByName(NetworkSetup);
    } // setupUi

    void retranslateUi(QDialog *NetworkSetup)
    {
        NetworkSetup->setWindowTitle(QApplication::translate("NetworkSetup", "Dialog", 0, QApplication::UnicodeUTF8));
        labelServerAddress->setText(QApplication::translate("NetworkSetup", "Address", 0, QApplication::UnicodeUTF8));
        labelServerPort->setText(QApplication::translate("NetworkSetup", "Port", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NetworkSetup: public Ui_NetworkSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKSETUP_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    networkStatus(0),
    loginStatus(0),
    signUpStatus(0)
{
    ui->setupUi(this);



 /*   newNetworkSetup = new NetworkSetup();
    newNetworkSetup->setModal(true);
    newNetworkSetup->show();
    newNetworkSetup->exec();
    serverAddress = newNetworkSetup->serverAddress;
    serverPort = newNetworkSetup->serverPort;
    QMessageBox::information(this,"Title",serverAddress);
    */

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuick_Connect_triggered()
{
        bool ok;
        newNetworkSetup = new NetworkSetup();
        newNetworkSetup->setModal(true);
        newNetworkSetup->show();
        newNetworkSetup->exec();
        serverAddress = newNetworkSetup->serverAddress;
        serverPort = newNetworkSetup->serverPort;
        port = serverPort.toInt(&ok,10);
        if(ok==false)
            QMessageBox::information(this,"Error","Wrong port format");
        else
        {
            newTCPConnect = new TCPConnect(this,serverAddress,port);
            networkStatus=newTCPConnect->signal;
        }
        delete newNetworkSetup;
}

void MainWindow::on_actionLogin_triggered()
{
    newLogin = new Login();
    newLogin->setModal(true);
    newLogin->show();
    newLogin->exec();
    username = newLogin->userName;
    password = newLogin->password;
    if(networkStatus==1)
    {
        loginStatus=newTCPConnect->SignIN(username,password);
    }
    else
        QMessageBox::information(this,"Error","Connect First!!!");
}

void MainWindow::on_actionReconnect_triggered()
{
    //Free previous tcpconnect class and then login with new
}

void MainWindow::on_actionSignUp_triggered()
{
    newLogin = new Login();
    newLogin->setModal(true);
    newLogin->show();
    newLogin->exec();
    username = newLogin->userName;
    password = newLogin->password;
    if(networkStatus==1)
    {
        signUpStatus=newTCPConnect->SignUP(username,password);
    }
    else
        QMessageBox::information(this,"Error","Connect First!!!");
}

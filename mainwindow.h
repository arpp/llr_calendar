#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <networksetup.h>
#include <QMessageBox>
#include <tcpconnect.h>
#include <login.h>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString serverAddress, serverPort, username, password;
    int port;
    
private slots:

    void on_actionQuick_Connect_triggered();

    void on_actionLogin_triggered();

    void on_actionReconnect_triggered();

    void on_actionSignUp_triggered();


private:
    Ui::MainWindow *ui;
    NetworkSetup *newNetworkSetup;
    Login *newLogin;
    TCPConnect *newTCPConnect;
    int networkStatus;
    int loginStatus;
    int signUpStatus;
};

#endif // MAINWINDOW_H

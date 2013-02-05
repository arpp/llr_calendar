#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <networksetup.h>
#include <QMessageBox>
#include <tcpconnect.h>
#include <login.h>
#include <QtGui>

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


    void on_actionSignUp_triggered();


    void on_actionLogout_triggered();

    void on_actionClose_Connection_triggered();

    //
    void setMonth(int month);
    void setYear(QDate date);
    void taskdone();
    void undone();

private:
    Ui::MainWindow *ui;
    NetworkSetup *newNetworkSetup;
    Login *newLogin;
    TCPConnect *newTCPConnect;
    int networkStatus;
    int loginStatus;
    int signUpStatus;

    //
    void insertCalendar(int *t, int n);
    void insertCalendar();
    int task;
    int fontSize;
    QDate selectedDate;
    QTextBrowser *editor;
    int *t ;
    QWidget *centralWidget;
    QLabel *dateLabel;
    QLabel *yearLabel;
    QComboBox *monthCombo;
    QDateTimeEdit *yearEdit;
    QHBoxLayout *controlsLayout;
    QPushButton* button1,*button2;
    QLabel *label;
    QHBoxLayout *bottomLayout;
    QVBoxLayout *centralLayout;
};

#endif // MAINWINDOW_H

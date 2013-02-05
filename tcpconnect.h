#ifndef TCPCONNECT_H
#define TCPCONNECT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QMessageBox>
#include <QDate>
#include <QByteArray>

class TCPConnect : public QWidget
{
    Q_OBJECT
public:
    explicit TCPConnect(QWidget *parent, QString add, int pt);
    ~TCPConnect();
    int SignUP(QString userName, QString password);
    int SignIN(QString, QString);
    void mark();
    int fetchDateStatus(QDate *d);
    int* fetchMonthStatus(QDate *d);
    int signal;
    void closeConnection();
    int LogOut();

    
signals:
    
public slots:

private:
    QTcpSocket *socket;
    QString regString, logString, dayMark, date, monthString, errMsg;
    int *mon;
    
};

#endif // TCPCONNECT_H

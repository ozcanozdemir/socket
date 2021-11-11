#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>
#include <iostream>
#include <QRandomGenerator>
#include<QTimer>
using namespace std;
#include <QUuid>
#include <QAbstractSocket>
#include <QThread>
#include<QFile>
#include "configjson.h"
class cclient : public QObject
{
    Q_OBJECT
public:
    explicit cclient (const QUrl &url, QObject *parent = nullptr);
    ~cclient();
    void startConnection(QUrl url);

    QString GetRandomString(int length) ;
    void islemler();
    void readFile();
    void printFile(QString fileContent);


public slots:
    void onConnected();
    void onTextMessageReceived(QString message);
    void closed();
    void ReeConnection();
    void onErrorOccured(QAbstractSocket::SocketError error);


private:
    QWebSocket *m_websocket;
    QUrl m_url;
    QTimer *timer = new QTimer();
    int NameLength;
    bool isConnected = false;
    char islem_yaniti;
    int islem;
    configjson config;
    string message1;


};

#endif // CLIENT_H

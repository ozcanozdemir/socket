#ifndef SERVER_H
#define SERVER_H
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QObject>
#include<QWebSocket>
#include<QWebSocketServer>
#include<QDebug>
#include<qwebsocketserver.h>
#include<qwebsocket.h>
#include<QWebSocket>
#include<QWebSocketServer>
#include <QVector>
#include <QUuid>
#include <iostream>
#include <string>
using namespace std;

class Server : public QObject

{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
    QWebSocketServer *server;
    QWebSocket *socket;
    list<string> vector;
//    vector<string> vectorKar;
//    vector<string> vectorFark;


public slots:
    void newConnection();
    void ClientdisConnection();
    void RecievedMessage(QString message);

private:
    QString m_message;
    QList<QWebSocket *> m_clients;


};

#endif // SERVER_H

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
class cclient : public QObject
{
    Q_OBJECT
public:
    explicit cclient (const QUrl &url, QObject *parent = nullptr);
    ~cclient();
    void startConnection(QUrl url);


private Q_SLOTS :
    void onConnected();
    void onTextMessageReceived(QString message);
    void closed();
    QString GetRandomString(int length) ;
    void ReeConnection();


private:
    QWebSocket *m_websocket;
    QUrl m_url;
    QTimer *timer = new QTimer();
    int NameLength;
    bool isConnected = false;
};

#endif // CLIENT_H

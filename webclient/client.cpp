#include "client.h"
#include <QRandomGenerator>
#include<time.h>
#include<QTimer>
using namespace std;

cclient::cclient(const QUrl &url, QObject *parent) : QObject(parent), m_url(url)
{

    startConnection(url);

}

cclient::~cclient()
{
    m_websocket->deleteLater();
}

void cclient::startConnection(QUrl url)
{
    qDebug() << "Connecting to webSocket server: " << url;
    m_websocket = new QWebSocket;
    connect(m_websocket, &QWebSocket::connected, this, &cclient::onConnected);
    connect(m_websocket, &QWebSocket::disconnected, this, &cclient::closed);
    m_websocket->open(url);
}
void cclient::closed()
{
    qDebug()<< "Server Connection Lost";
    m_websocket->close();
    m_websocket->abort();

   connect(timer, &QTimer::timeout, this, &cclient::ReeConnection);
   timer->start(3000);
}

QString cclient::GetRandomString(int length)
{
    srand(time(NULL));
       const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
       const int NameLength = length; // assuming you want random strings of 4 characters

       QString Name;
       for(int i=0; i<NameLength; ++i)
       {
           int index = qrand() % possibleCharacters.length();
           QChar nextChar = possibleCharacters.at(index);
           Name.append(nextChar);
       }
       return Name;
}

void cclient::onConnected()
{
    isConnected=true;
        qDebug() << "WebSocket connected";
    connect(m_websocket, &QWebSocket::textMessageReceived,this, &cclient::onTextMessageReceived);
     m_websocket->sendTextMessage(GetRandomString(5));
}

void cclient::onTextMessageReceived(QString message)
{
        qDebug() << "Message received:" << message;
}

void cclient::ReeConnection()
{
timer->stop();
    qDebug() << "reconnection....";
    startConnection(QUrl(QStringLiteral("ws://172.16.50.159:1234")));


}



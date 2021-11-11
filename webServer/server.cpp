#include "server.h"


Server::Server(QObject *parent) : QObject(parent)
{
    socket = new QWebSocket();
    server= new QWebSocketServer(QStringLiteral("server"), QWebSocketServer::NonSecureMode,this);
    connect(server,&QWebSocketServer::newConnection,this,&Server::newConnection);

    if(!server->listen(QHostAddress("172.16.50.159"),1234))
    {
        qDebug()<<"server could not start";
    }
    else
    {
        qDebug()<<"server started";
    }

}

Server::~Server()
{
    server->close();
}



void Server::newConnection()
{
    qDebug()<<"newConnection";
    socket = server->nextPendingConnection();
    socket->sendTextMessage("baglandim");
    socket->setObjectName(QUuid::createUuid().toString());

    connect(socket,&QWebSocket::textMessageReceived,this,&Server::RecievedMessage);
     connect(socket,&QWebSocket::disconnected,this, &Server::ClientdisConnection);

     m_clients<<socket;

}
template<typename T>
void print(QList<T>&v){
    typename QList<T>::iterator i=v.begin();
    while (i!=v.end())
        qDebug()<<*i++<<" "<<endl;
}

void Server::RecievedMessage(QString message)
{
    socket = qobject_cast<QWebSocket *>(sender());
    qDebug() << "Message from client: " << socket->objectName() << " : " << message;

}

void Server::ClientdisConnection()
{
    socket = qobject_cast<QWebSocket *>(sender());
    qDebug() << "Disconnected client: " << socket->objectName();
    m_clients.removeOne(socket);

    print(m_clients);

}









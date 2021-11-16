#include "client.h"
#include <QRandomGenerator>
#include<time.h>
#include<QTimer>


using namespace std;

cclient::cclient(const QUrl &url, QObject *parent) : QObject(parent), m_url(url)
{
    config.jsonOp();
    startConnection(config.ipadres);

}
cclient::~cclient()
{
    delete m_websocket;
}

void cclient::startConnection(QUrl url)
{
    qDebug() << "Connecting to webSocket server: " << config.ipadres;
    m_websocket = new QWebSocket;
    connect(m_websocket, &QWebSocket::connected, this, &cclient::onConnected);
    connect(m_websocket, &QWebSocket::disconnected, this, &cclient::closed);
     m_websocket->open(config.ipadres);
     if(!connect(m_websocket,SIGNAL(error(const QAbstractSocket::SocketError&)),this,SLOT(onErrorOccured(QAbstractSocket::SocketError))))
     {
         qDebug() << "error!";
     }
     else
     {
         isConnected=true;
         connect(m_websocket, &QWebSocket::textMessageReceived,this, &cclient::onTextMessageReceived);


     }
     qDebug()<<"start connection";
//    qDebug()<< "cclient class ından gelen flag değeri: " << config.flag;
}
void cclient::closed()
{
    //isConnected=false;
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
    m_websocket->sendTextMessage("my name "+GetRandomString(5));
        qDebug() << "WebSocket connected";
        xx=false;

}
void cclient::onTextMessageReceived(QString message)
{       if(xx==false){
        qDebug() << "Message received:" << message;
        xx=true;
    }
    islemler();

 }
void cclient::islemler()
{
    if (xx==true) {
    cout<<"client icin islem yapmak ister misin  (Y/N)"<<endl;
    cin>>islem_yaniti;

if(islem_yaniti=='Y')
 {
    cout<<"yapmak istediginiz islem nedir"<<endl;
    cout<<"1 client kapat"<<endl<<"2 mesaj yaz"<<endl;
    cin>>islem;
    if(islem==1)
        m_websocket->close();
    if(islem==2){
            cout<< "mesajınızı yazınız"<<endl;
            cin>>message1;
            //cout<< "cikmak icin x e basın"<<endl;
            if(message1!="x"){
                m_websocket->sendTextMessage(QString::fromStdString( message1));
                //dummy();

            }

}
}
}
//        while( getline(in,str,':')
//        {
//        getline(str,'\n');
//        int var = atoi(str.c_str());
    //        }
}

void cclient::dummy()
{
    string a;
    do
    {
        cout << "göndermek istediğiniz mesajı yaziniz" << endl;
        cin>>a;
        m_websocket->sendTextMessage(QString::fromStdString(a));
    }while(&QWebSocket::textMessageReceived);
}


void cclient::ReeConnection()
{
    if(islem!=1){
    qDebug() << "reconnection...." ;
    startConnection(QUrl(config.ipadres));


    if(!isConnected&&islem!=1)
    {
        qDebug() << m_websocket->errorString();
    }
    else
    {
        timer->stop();
    }
    }
}

void cclient::onErrorOccured(QAbstractSocket::SocketError error)
{
    qDebug() << "message: "  << error;
    m_websocket->close();
    QThread::msleep(3000);
    ReeConnection();
}

void cclient::messageOp()
{

}



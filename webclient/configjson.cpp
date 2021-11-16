#include "configjson.h"

configjson::configjson(QObject *parent) : QObject(parent)
{

}
//qApp->applicationDirPath()
void configjson::fileRead(QString filePath)
{
QFile jsonFile(filePath);

if(!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)){
    qDebug()<<"Error, jsonFile cannot open.";
    return;
}

byteArray = jsonFile.readAll();
}

void configjson::jsonOp()
{
fileRead("config.txt");
//qDebug()<<byteArray+"\n";

QJsonDocument jsonDoc=QJsonDocument::fromJson(byteArray);
QJsonObject obj = jsonDoc.object();

//qDebug()<<"";
//    qDebug()<<"json value: "+ QString::number( jsonDoc.object().value("number").toInt());

int number=  obj.value("number").toInt();
    flag= jsonDoc.object().value("reconnectionFlag").toBool();
//    qDebug()<< "configjson class ından dan gelen flag değeri: " << flag;
    ip=jsonDoc.object().value("ip").toString();
    port=jsonDoc.object().value("port").toInt();
    ipadres="ws://"+ip+":"+QString::number(port);
//    qDebug()<<"ipadresimiz"<<ipadres;


}

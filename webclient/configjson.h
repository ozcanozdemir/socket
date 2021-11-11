#ifndef CONFIGJSON_H
#define CONFIGJSON_H
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QCoreApplication>

class configjson : public QObject
{
    Q_OBJECT
public:
    explicit configjson(QObject *parent = nullptr);

    void fileRead(QString filePath);
    void jsonOp();
    QByteArray fileContent;
    bool flag;
    QString ip;
    int port;
    QString ipadres;
    QByteArray byteArray;


signals:

};

#endif // CONFIGJSON_H

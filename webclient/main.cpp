#include <QCoreApplication>
#include"client.h"
#include"configjson.h"
#include"QDebug"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    configjson json;

    cclient client(QUrl(json.ipadres));
   // client.islemler();



//"ws://172.16.50.159:1234"
  return a.exec();

}

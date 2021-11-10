#include <QCoreApplication>
#include"client.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


  cclient client(QUrl(QStringLiteral("ws://172.16.50.159:1234")));



  return a.exec();

}

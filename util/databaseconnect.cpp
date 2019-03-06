#include "databaseconnect.h"
#include <QDebug>
#pragma execution_character_set("utf-8")
DataBaseConnect::DataBaseConnect()
{

}

 QSqlQuery* DataBaseConnect::getConnect(){

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    //db.setHostName("134.175.66.22");
    db.setHostName("127.0.0.1");  //连接数据库主机名，这里需要注意（127.0.0.1或localhost)
    //db.setPort(3306);                 //连接数据库端口号
    db.setDatabaseName("orderSystem");      //连接数据库名
    db.setUserName("root");          //数据库用户名
    db.setPassword("ZIB12584884");    //数据库密码
    db.open();
    if(!db.open())
    {
        qDebug()<<"连接失败！"<<db.lastError().text();
        return NULL;
    }
    else
    {
         qDebug()<<"mysql数据库连接成功";
    }
    QSqlQuery *query = new QSqlQuery(db);
    return query;
//    query.exec("select * from userWaiter");
//    while(query.next()){
//        qDebug()<<query.value("account").toString();
//    }
}

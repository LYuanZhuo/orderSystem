#include "shop_dao.h"
#include "QSqlQuery"
#include "global_variable.h"
#include <QVariant>
#include <QDebug>

Shop_dao::Shop_dao()
{

}

QString Shop_dao::getShopName(int id){

    QSqlQuery *query = Global_variable::query;
    QString sql = "select shopName from shop where id = "+QString::number(id);
    query->exec(sql);
    if(query->next()){
        return query->value("shopName").toString();
    }
    return NULL;
}

User_entity* Shop_dao::getShop(QString account, QString password){

    QSqlQuery *query = Global_variable::query;
    QString sql = "select * from shop where account="+account+" and password = "+password;
    query->exec(sql);
    if(!query->next()){
        return NULL;
    }else{
        User_entity* user = new User_entity;
        //user->setAccount(query->value("account").toString());
        //user->setPassword(query->value("password").toString());
        user->setName(query->value("shopName").toString());
        user->setShopId(query->value("id").toInt());
        return user;
    }
}

bool Shop_dao::addShop(User_entity user){
    QSqlQuery *query = Global_variable::query;
    QString sql = "insert into shop (shopName,account,password) values(?,?,?)";
    query->prepare(sql);
    query->bindValue(0,user.getName());
    query->bindValue(1,user.getAccount());
    query->bindValue(2,user.getPassword());
    return query->exec();
}



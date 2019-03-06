#include "user_waiter_dao.h"
#include "util/databaseconnect.h"
#include <iostream>
#include <QVariant>
#include <QDebug>
#include "global_variable.h"
User_waiter_dao::User_waiter_dao()
{

}

User_entity* User_waiter_dao::getWaiterUser(QString account, QString password){

    //QSqlQuery *query = DataBaseConnect::getConnect();
    QSqlQuery *query = Global_variable::query;
    QString sql = "select * from userWaiter where account="+account+" and password = "+password;
    query->exec(sql);
    if(!query->next()){
        return NULL;
    }else{
        User_entity* user = new User_entity;
        user->setAccount(query->value("account").toString());
        user->setShopId(query->value("shopId").toInt());
        user->setName(query->value("name").toString());
        user->setId(query->value("id").toInt());
        return user;
    }
}

QList<User_entity> User_waiter_dao::getAll(int shopId){
    QSqlQuery *query = Global_variable::query;
    QString sql = "select * from userWaiter where shopId=?";
    query->prepare(sql);
    query->bindValue(0,shopId);
    query->exec();
    QList<User_entity> list;
    while(query->next()){
        User_entity user;
        user.setAccount(query->value("account").toString());
        user.setPassword(query->value("password").toString());
        user.setShopId(query->value("shopId").toInt());
        user.setName(query->value("name").toString());
        user.setId(query->value("id").toInt());
        list.append(user);
    }
    return list;
}

User_entity User_waiter_dao::getUser(int id){
    QSqlQuery *query = Global_variable::query;
    QString sql = "select * from userWaiter where id = ?";
    query->prepare(sql);
    query->bindValue(0,id);
    query->exec();
    User_entity user;
    user.setId(-1);
    if(query->next()){
        user.setAccount(query->value("account").toString());
        user.setPassword(query->value("password").toString());
        user.setName(query->value("name").toString());
        user.setShopId(query->value("shopId").toInt());
        user.setId(query->value("id").toInt());
    }
        return user;
}


bool User_waiter_dao::addUser(User_entity user){
    QSqlQuery *query = Global_variable::query;
    QString sql = "insert into userWaiter (name,account,password,shopId) values(?,?,?,?)";
    query->prepare(sql);
    query->bindValue(0,user.getName());
    query->bindValue(1,user.getAccount());
    query->bindValue(2,user.getPassword());
    query->bindValue(3,user.getShopId());
    return query->exec();
}

bool User_waiter_dao::deleteUser(int id){
    QSqlQuery *query = Global_variable::query;
    QString sql = "delete from userWaiter where id=?";
    query->prepare(sql);
    query->bindValue(0,id);
    return query->exec();
}

bool User_waiter_dao::updateUser(User_entity user){
    QSqlQuery *query = Global_variable::query;
    QString sql = "update userWaiter set name = ?,account = ?,password=? where id=?";
    query->prepare(sql);
    query->bindValue(0,user.getName());
    query->bindValue(1,user.getAccount());
    query->bindValue(2,user.getPassword());
    query->bindValue(3,user.getId());
    return query->exec();
}

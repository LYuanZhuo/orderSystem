#include "order_dao.h"
#include <QDebug>
Order_dao::Order_dao()
{

}

QList<Order_entity> getOrders(QString sql){
    QSqlQuery* query = Global_variable::query;
    query->exec(sql);
    QList<Order_entity> list;
    while(query->next()){
    Order_entity order;
    order.setId(query->value("id").toInt());
    order.setIsPay(query->value("isPay").toBool());
    order.setOrderNum(query->value("orderNum").toString());
    order.setPersonNum(query->value("personNum").toInt());
    order.setPrice(query->value("price").toDouble());
    order.setShopId(query->value("shopId").toInt());
    order.setTableId(query->value("tableId").toInt());
    order.setTableName(query->value("tableName").toString());
    order.setTime(query->value("time").toString());
    order.setPayTime(query->value("payTime").toString());
    list.append(order);
    }
    return list;
}
bool Order_dao::addOrder(Order_entity order){
    QSqlQuery *query = Global_variable::query;
    QString sql = "insert into order1 (tableId,personNum,shopId,isPay,price,orderNum,time,payTime,tableName) values(?,?,?,?,?,?,?,?,?)";
    query->prepare(sql);
    query->bindValue(0, order.getTableId());
    query->bindValue(1,order.getPersonNum());
    query->bindValue(2, order.getShopId());
    query->bindValue(3, order.getIsPay());
    query->bindValue(4, order.getPrice());
    query->bindValue(5, order.getOrderNum());
    query->bindValue(6, order.getTime());
    query->bindValue(7,order.getPayTime());
    query->bindValue(8,order.getTableName());
    return query->exec();
}

QList<Order_entity> Order_dao::getAll(int shopId){

    QString sql = "select * from order1 where shopId = "+QString::number(shopId);
    return getOrders(sql);
}

QList<Order_entity> Order_dao::getOk(int shopId){
    QString sql = "select * from order1 where isPay = true and shopId = "+QString::number(shopId);
    return getOrders(sql);
}

QList<Order_entity> Order_dao::getUnOk(int shopId){
    QString sql = "select * from order1 where isPay = false and shopId = "+QString::number(shopId);
    return getOrders(sql);
}

QList<Order_entity> Order_dao::getAll(int shopId, int kind, QString date){
    QString sql;
    if(kind==1){
        sql="select* from order1 where shopId = "+QString::number(shopId)+" and time like '"+date+"%'";
    }else if(kind==2){
        sql="select* from order1 where isPay = false and shopId = "+QString::number(shopId)+" and time like '"+date+"%'";
    }else if(kind=3){
        sql="select* from order1 where isPay = true and shopId = "+QString::number(shopId)+" and time like '"+date+"%'";
    }
    return getOrders(sql);
}

Order_entity Order_dao::getOrder(int id){
    QString sql = "select * from order1 where id = "+QString::number(id);
    if(getOrders(sql).size()>0) return getOrders(sql)[0];
    else {
        Order_entity order;
        order.setId(-1);
        return order;
    }
}

Order_entity Order_dao::getOrderByTableId(int tableId){
    QString sql = "select * from order1 where isPay = false and tableId = "+QString::number(tableId);
    if(getOrders(sql).size()>0) return getOrders(sql)[0];
    else {
        Order_entity order;
        order.setId(-1);
        return order;
    }
}

bool Order_dao::pay(int orderId,bool isPay,double totalPrice,QString payTime){
    QString sql = "update order1 set isPay = ? ,price = ?,payTime = ? where id = ?";
    QSqlQuery *query = Global_variable::query;
    query->prepare(sql);
    query->bindValue(0,isPay);
    query->bindValue(1,totalPrice);
    query->bindValue(2,payTime);
    query->bindValue(3,orderId);
    return query->exec();
}

bool Order_dao::updatePrice(int orderId, double price){
    QString sql = "update order1 set price = price+? where id = ?";
    QSqlQuery *query = Global_variable::query;
    query->prepare(sql);
    query->bindValue(0,price);
    query->bindValue(1,orderId);
    return query->exec();
}

bool Order_dao::deleteOrder(int id){
    qDebug()<<id;
    QString sql = "delete from order1 where id = ?";
    QSqlQuery *query = Global_variable::query;
    query->prepare(sql);
    query->bindValue(0,id);
    return query->exec();
}

bool Order_dao::updateOrder(Order_entity order){
    QSqlQuery *query = Global_variable::query;
    QString sql = "update order1 set tableName=?,tableId=?,personNum=?,isPay=?,price=? where id =?";
    query->prepare(sql);
    query->bindValue(0, order.getTableName());
    query->bindValue(1, order.getTableId());
    query->bindValue(2, order.getPersonNum());
    query->bindValue(3, order.getIsPay());
    query->bindValue(4, order.getPrice());
    query->bindValue(5, order.getId());
    return query->exec();
}

QList<Sales_entity> Order_dao::getSales(int shopId){
    QSqlQuery *query = Global_variable::query;
    QString sql = "select DATE(time) AS date, count(*) as num,sum(price) as sum from order1 where shopId = ? and isPay=true  GROUP BY DATE(time) desc";
    query->prepare(sql);
    query->bindValue(0, shopId);
    query->exec();
    QList<Sales_entity> list;
    while(query->next()){
        Sales_entity entity;
        entity.setDate(query->value("date").toString());
        entity.setNum(query->value("num").toInt());
        entity.setSum(query->value("sum").toDouble());
        list.append(entity);
    }
    return list;
}


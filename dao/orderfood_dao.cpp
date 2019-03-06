#include "orderfood_dao.h"
#include <qvariant.h>
#include <qdebug.h>
OrderFood_dao::OrderFood_dao()
{

}
QList<OrderFood_entity> OrderFood_dao::getOrderFoods(int orderId){

    QSqlQuery* query = Global_variable::query;
    QString sql = "select * from order_food where orderId = "+QString::number(orderId);
    query->exec(sql);
    QList<OrderFood_entity> list;
    while(query->next()){
        OrderFood_entity entity;
        entity.setFoodName(query->value("foodName").toString());
        entity.setNum(query->value("num").toInt());
        entity.setPrice(query->value("price").toDouble());
        entity.setTotalPrice(query->value("totalPrice").toDouble());
        entity.setFoodId(query->value("foodId").toInt());
        list.append(entity);
    }
    return list;
}

bool OrderFood_dao::isExist(OrderFood_entity orderFood){
    QSqlQuery* query = Global_variable::query;
    QString sql = "select orderId,foodId from order_food where orderId=? and foodId = ?";
    query->prepare(sql);
    query->bindValue(0,orderFood.getOrderId());
    query->bindValue(1,orderFood.getFoodId());
    query->exec();
    return query->next();
}

bool OrderFood_dao::addFoodOrder(OrderFood_entity orderFood){

    QSqlQuery* query = Global_variable::query;
    QString sql = "insert into order_food (orderId,foodId,num,price,foodName,totalPrice) values(?,?,?,?,?,?)";
    query->prepare(sql);
    query->bindValue(0,orderFood.getOrderId());
    query->bindValue(1,orderFood.getFoodId());
    query->bindValue(2,orderFood.getNum());
    query->bindValue(3,orderFood.getPrice());
    query->bindValue(4,orderFood.getFoodName());
    query->bindValue(5,orderFood.getTotalPrice());
    return query->exec();
}

bool OrderFood_dao::updateFoodOrder(OrderFood_entity orderFood){
    //注意：这里无论能否找到相应更新成功或失败返回值都为true；

    QSqlQuery* query = Global_variable::query;
    QString sql = "update order_food set num = num+?,totalPrice = totalPrice+? where orderId = ? and foodId=?";
    query->prepare(sql);
    query->bindValue(0,orderFood.getNum());
    query->bindValue(1,orderFood.getTotalPrice());
    query->bindValue(2,orderFood.getOrderId());
    query->bindValue(3,orderFood.getFoodId());
    return query->exec();;

}

bool OrderFood_dao::deleteFoodOrder(int orderId, int foodId){
    qDebug()<<orderId;
    qDebug()<<foodId;
    QSqlQuery* query = Global_variable::query;
    QString sql = "delete from order_food where orderId = ? and foodId = ?";
    query->prepare(sql);
    query->bindValue(0,orderId);
    query->bindValue(1,foodId);
    return query->exec();
}

bool OrderFood_dao::deleteByOrderId(int orderId){
    QSqlQuery* query = Global_variable::query;
    QString sql = "delete from order_food where orderId = ?";
    query->prepare(sql);
    query->bindValue(0,orderId);
    return query->exec();
}



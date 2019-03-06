#include "foodneed_dao.h"
#include "global_variable.h"
#include <QVariant>
#include <qdebug.h>
FoodNeed_dao::FoodNeed_dao()
{

}

QList<FoodNeed_entity> FoodNeed_dao::getUnOK(int shopId){

    QSqlQuery* query = Global_variable::query;
    QString sql = "select *from foodNeed where isOk = false and shopId = ? order by time asc";
    query->prepare(sql);
    query->bindValue(0,shopId);
    query->exec();
    QList<FoodNeed_entity> list;
    while(query->next()){
          FoodNeed_entity entity;
          entity.setId(query->value("id").toInt());
          entity.setFoodName(query->value("foodName").toString());
          entity.setTableName(query->value("tableName").toString());
          entity.setIsOk(query->value("isOk").toBool());
          entity.setNum(query->value("num").toInt());
          entity.setShopId(query->value("shopId").toInt());
          entity.setTime(query->value("time").toString());
          entity.setOrderNum(query->value("orderNum").toString());
          entity.setFoodId(query->value("foodId").toInt());
          list.append(entity);
    }
    return list;
}

QList<FoodNeed_entity> FoodNeed_dao::getCombineUnOK(int shopId){

    QSqlQuery* query = Global_variable::query;
    QString sql = "select foodId,foodName,sum(num) as 'nums' from foodNeed where isOk = false and shopId = ?  group by foodId";
    query->prepare(sql);
    query->bindValue(0,shopId);
    query->exec();
    QList<FoodNeed_entity> list;
    while(query->next()){
          FoodNeed_entity entity;
          entity.setFoodId(query->value("foodId").toInt());
          entity.setFoodName(query->value("foodName").toString());
          entity.setNum(query->value("nums").toInt());
          list.append(entity);
    }
    return list;
}

bool FoodNeed_dao::addFoodNeed(FoodNeed_entity entity){

    QSqlQuery* query = Global_variable::query;
    QString sql = "insert into foodNeed (tableName,foodName,num,isOk,time,shopId,orderNum,foodId) values(?,?,?,?,?,?,?,?)";
    query->prepare(sql);
    query->bindValue(0,entity.getTableName());
    query->bindValue(1,entity.getFoodName());
    query->bindValue(2,entity.getNum());
    query->bindValue(3,entity.getIsOk());
    query->bindValue(4,entity.getTime());
    query->bindValue(5,entity.getShopId());
    query->bindValue(6,entity.getOrderNum());
    query->bindValue(7,entity.getFoodId());

    return query->exec();
}

bool FoodNeed_dao::setIsOk(int id, bool isOk){
    QSqlQuery* query = Global_variable::query;
    QString sql = "update foodNeed set isOk = ? where id = ?";
    query->prepare(sql);
    query->bindValue(0,isOk);
    query->bindValue(1,id);
    return query->exec();
}

bool FoodNeed_dao::setCombineIsOK(int foodId, bool isOk){
    QSqlQuery* query = Global_variable::query;
    QString sql = "update foodNeed set isOk = ? where foodId = ?";
    query->prepare(sql);
    query->bindValue(0,isOk);
    query->bindValue(1,foodId);
    return query->exec();
}

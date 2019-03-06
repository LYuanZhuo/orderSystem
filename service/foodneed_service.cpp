#include "foodneed_service.h"
#include "dao/foodneed_dao.h"
#include "dao/order_dao.h"
#include "dao/table_dao.h"
#include <qdatetime.h>

FoodNeed_service::FoodNeed_service()
{

}
QList<FoodNeed_entity> FoodNeed_service::getUnOK(int shopId){
    FoodNeed_dao dao;
    return dao.getUnOK(shopId);
}

QList<FoodNeed_entity> FoodNeed_service::getCombineUnOK(int shopId){
    FoodNeed_dao dao;
    return dao.getCombineUnOK(shopId);
}

bool FoodNeed_service::addFoodNeed(OrderFood_entity entity){
    FoodNeed_entity entity1;
    Order_dao order_dao;
    Table_dao table_dao;
    int orderId = entity.getOrderId();
    entity1.setFoodName(entity.getFoodName());
    entity1.setIsOk(false);
    entity1.setNum(entity.getNum());
    entity1.setShopId(order_dao.getOrder(orderId).getShopId());
    entity1.setOrderNum(order_dao.getOrder(orderId).getOrderNum());
    entity1.setTableName(table_dao.getTable(order_dao.getOrder(orderId).getTableId())->getName());
    entity1.setFoodId(entity.getFoodId());
    QDateTime time = QDateTime::currentDateTime();
    QString timeStr = time.toString("yyyy-MM-dd hh:mm:ss");
    entity1.setTime(timeStr);
    FoodNeed_dao dao;
    return dao.addFoodNeed(entity1);
}

bool FoodNeed_service::setIsOk(int id, bool isOk){
    FoodNeed_dao dao;
    return dao.setIsOk(id,isOk);
}
bool FoodNeed_service::setCombineIsOK(int foodId, bool isOk){
    FoodNeed_dao dao;
    return dao.setCombineIsOK(foodId,isOk);
}

#include "orderfood_service.h"

OrderFood_service::OrderFood_service()
{

}
QList<OrderFood_entity> OrderFood_service::getOrderFoods(int orderId){
    OrderFood_dao dao;
    return dao.getOrderFoods(orderId);
}
bool OrderFood_service::addFoodToOrder(OrderFood_entity orderFood){
    //这里用到了两次查询，效率不高，后期可以考虑使用复杂sql解决
    OrderFood_dao dao;
    if(!dao.isExist(orderFood)){
        return dao.addFoodOrder(orderFood);
    }else{
        return dao.updateFoodOrder(orderFood);
    }
}
bool OrderFood_service::deleteFoodOrder(int orderId, int foodId){
    OrderFood_dao dao;
    return dao.deleteFoodOrder(orderId,foodId);
}

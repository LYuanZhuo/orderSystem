#ifndef ORDERFOOD_SERVICE_H
#define ORDERFOOD_SERVICE_H
#include "entity/orderfood_entity.h"
#include "dao/orderfood_dao.h"

class OrderFood_service
{
public:
    OrderFood_service();
    QList<OrderFood_entity> getOrderFoods(int orderId);
    bool addFoodToOrder(OrderFood_entity orderFood);
    bool deleteFoodOrder(int orderId, int foodId);
};

#endif // ORDERFOOD_SERVICE_H

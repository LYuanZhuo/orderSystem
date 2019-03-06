#ifndef ORDERFOOD_DAO_H
#define ORDERFOOD_DAO_H
#include "entity/orderfood_entity.h"
#include <qlist.h>
#include "global_variable.h"

class OrderFood_dao
{
public:
    OrderFood_dao();
    QList<OrderFood_entity> getOrderFoods(int orderId);
    bool isExist(OrderFood_entity orderFood);
    bool addFoodOrder(OrderFood_entity orderFood);
    bool updateFoodOrder(OrderFood_entity orderFood);
    bool deleteFoodOrder(int orderId,int foodId);
    bool deleteByOrderId(int orderId);
};

#endif // ORDERFOOD_DAO_H

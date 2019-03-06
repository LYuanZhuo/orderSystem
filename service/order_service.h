#ifndef ORDER_SERVICE_H
#define ORDER_SERVICE_H
#include "entity/order_entity.h"
#include "dao/order_dao.h"
class Order_service
{
public:
    Order_service();
    bool addOrder(Order_entity order);
    QList<Order_entity> getAll(int shopId,int kind);
    QList<Order_entity> getAll(int shopId, int kind, QString date);
    Order_entity getOrder(int id);
    Order_entity getOrderByTableId(int tableId);
    bool pay(int orderId,double totalPrice,QString payTime);
    bool updatePrice(int orderId, double price);
    bool updateOrder(Order_entity order);
    bool deleteOrder(int id);
};

#endif // ORDER_SERVICE_H

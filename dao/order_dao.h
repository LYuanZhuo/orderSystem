#ifndef ORDER_DAO_H
#define ORDER_DAO_H
#include "entity/order_entity.h"
#include <qlist.h>
#include "global_variable.h"
#include "entity/sales_entity.h"
class Order_dao
{
public:
    Order_dao();
    bool addOrder(Order_entity order);
    QList<Order_entity> getAll(int shopId);
    QList<Order_entity> getOk(int shopId);
    QList<Order_entity> getUnOk(int shopId);
    QList<Order_entity> getAll(int shopId,int kind,QString date);
    Order_entity getOrder(int id);
    Order_entity getOrderByTableId(int tableId);
    bool pay(int order,bool isPay,double totalPrice,QString payTime);
    bool updatePrice(int orderId,double price);

    bool updateOrder(Order_entity order);
    bool deleteOrder(int id);

    QList<Sales_entity> getSales(int shopId);


};

#endif // ORDER_DAO_H

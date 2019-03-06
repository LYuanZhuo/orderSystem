#include "order_service.h"
#include "dao/table_dao.h"
#include "dao/orderfood_dao.h"
Order_service::Order_service()
{

}
bool Order_service::addOrder(Order_entity order){
    Order_dao dao;
    return dao.addOrder(order);

}

QList<Order_entity> Order_service::getAll(int shopId,int kind){
     Order_dao dao;
     if(kind==1){
         return dao.getAll(shopId);
     }else if(kind==2){
         return dao.getUnOk(shopId);
     }else{
         return dao.getOk(shopId);
     }

}
QList<Order_entity> Order_service::getAll(int shopId, int kind, QString date){
    Order_dao dao;
    return dao.getAll(shopId,kind,date);
}

Order_entity Order_service::getOrder(int id){
    Order_dao dao;
    return dao.getOrder(id);
}
Order_entity Order_service::getOrderByTableId(int tableId){
    Order_dao dao;
    return dao.getOrderByTableId(tableId);
}

bool Order_service::pay(int orderId,double totalPrice,QString payTime){
    Order_dao order_dao;
    Table_dao table_dao;
    int tableId = order_dao.getOrder(orderId).getTableId();
    if(table_dao.setStatus(tableId,true)&&order_dao.pay(orderId,true,totalPrice,payTime)){
        return true;
    }
    return false;
}

bool Order_service::updatePrice(int orderId, double price){
    Order_dao dao;
    return dao.updatePrice(orderId,price);
}

bool Order_service::deleteOrder(int id){
    OrderFood_dao dao1;
    dao1.deleteByOrderId(id);
    Order_dao dao;
    return dao.deleteOrder(id);
}
bool Order_service::updateOrder(Order_entity order){
    Order_dao dao;
    return dao.updateOrder(order);
}

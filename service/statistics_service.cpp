#include "statistics_service.h"
#include "dao/order_dao.h"
#include "dao/table_dao.h"
#include <qdebug.h>
Statistics_service::Statistics_service()
{

}

QList<Sales_entity> Statistics_service::getSales(int shopId){
    Order_dao dao;
    return dao.getSales(shopId);
}


QList<int> Statistics_service::getTables(int shopId){
    Table_dao dao;
    QList<int> list;
    list.append(dao.getFreeTables(shopId).size());
    list.append(dao.getUsingTables(shopId).size());
    return list;
}

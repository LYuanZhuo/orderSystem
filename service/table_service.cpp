#include "table_service.h"
#include "dao/table_dao.h"
#include <QDebug>
Table_service::Table_service()
{

}
QList<Table_entity> Table_service::getAllTables(int shopId){
    Table_dao dao;
    return dao.getAllTables(shopId);
}
QList<Table_entity> Table_service::getAllTables(int shopId, int n, int kind){
    Table_dao dao;
    QList<Table_entity> list = dao.getAllTables(shopId,n);
    if(kind==1) {
        return list;
    }
    QList<Table_entity> list1;
    for(int i=0;i<list.size();i++){
        if(list[i].getIsFree()&&kind==2){
           list1.append(list[i]);
        }
        if(!list[i].getIsFree()&&kind==3){
           list1.append(list[i]);
        }
    }
    return list1;
}
QList<Table_entity> Table_service::getFreeTables(int shopId){
    Table_dao dao;
    return dao.getFreeTables(shopId);
}
QList<Table_entity> Table_service::getUsingTables(int shopId){
    Table_dao dao;
    return dao.getUsingTables(shopId);
}
Table_entity* Table_service::getTable(int id){
    Table_dao dao;
    return dao.getTable(id);
}
bool Table_service::setStatus(int tableId,bool isFree){
    Table_dao dao;
    return dao.setStatus(tableId,isFree);
}
bool Table_service::changeTable(Table_entity table){
    Table_dao dao;
    return dao.changeTable(table);
}
bool Table_service::deleteTable(int id){
    Table_dao dao;
    return dao.deleteTable(id);
}
bool Table_service::addTable(Table_entity table){
    Table_dao dao;
    return dao.addTable(table);
}

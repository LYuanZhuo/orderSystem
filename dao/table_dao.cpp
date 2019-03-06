#include "table_dao.h"
#include <QDebug>
Table_dao::Table_dao()
{

}

QList<Table_entity> getTables(QString sql){
    QSqlQuery *query = Global_variable::query;
    query->exec(sql);
    QList<Table_entity> list;
    while(query->next()){
    Table_entity table;
    table.setId(query->value("id").toInt());
    table.setDescribe(query->value("describe1").toString());
    table.setIsFree(query->value("isFree").toBool());
    table.setName(query->value("name").toString());
    table.setShopId(query->value("shopId").toInt());
    table.setSize(query->value("size").toInt());
    list.append(table);
    }
    return list;
}

Table_entity* Table_dao::getTable(int id){
    QSqlQuery *query = Global_variable::query;
    QString sql = "select * from table1 where id = "+QString::number(id);
    query->exec(sql);
    if(query->next()){
        Table_entity *table = new Table_entity;
        table->setId(query->value("id").toInt());
        table->setDescribe(query->value("describe1").toString());
        table->setIsFree(query->value("isFree").toBool());
        table->setName(query->value("name").toString());
        table->setShopId(query->value("shopId").toInt());
        table->setSize(query->value("size").toInt());
        return table;
    }
    return NULL;
}

QList<Table_entity> Table_dao::getAllTables(int shopId){

    QString sql = "select * from table1 where shopId = "+QString::number(shopId);
    return getTables(sql);
}

QList<Table_entity> Table_dao::getAllTables(int shopId, int n){
    QString sql = "select * from table1 where shopId = "+QString::number(shopId)+" and size = "+QString::number(n);
    return getTables(sql);
}

QList<Table_entity> Table_dao::getUsingTables(int shopId){
    QString sql = "select * from table1 where shopId = "+QString::number(shopId)+" and isFree = false";
    return getTables(sql);
}

QList<Table_entity> Table_dao::getFreeTables(int shopId){
    QString sql = "select * from table1 where shopId = "+QString::number(shopId)+" and isFree = true";
    return getTables(sql);
}

bool Table_dao::setStatus(int tableId,bool isFree){
     QString sql = "update table1 set isFree = "+QString::number(isFree)+" where id = "+QString::number(tableId);
     QSqlQuery *query = Global_variable::query;
     return query->exec(sql);
}

bool Table_dao::changeTable(Table_entity table){
    QString sql = "update table1 set name = ?,describe1 = ?,size = ? where id = ?";
    QSqlQuery *query = Global_variable::query;
    query->prepare(sql);
    query->bindValue(0,table.getName());
    query->bindValue(1,table.getDescribe());
    query->bindValue(2,table.getSize());
    query->bindValue(3,table.getId());
    return query->exec();
}

bool Table_dao::deleteTable(int id){

    QSqlQuery *query = Global_variable::query;
    QString sql = "delete from table1 where id = ?";
    query->prepare(sql);
    query->bindValue(0,id);
    return query->exec();
}

bool Table_dao::addTable(Table_entity table){
    QString sql = "insert into table1 (name,size,shopId,describe1,isFree) values(?,?,?,?,?)";
    QSqlQuery *query = Global_variable::query;
    query->prepare(sql);
    query->bindValue(0,table.getName());
    query->bindValue(1,table.getSize());
    query->bindValue(2,table.getShopId());
    query->bindValue(3,table.getDescribe());
    query->bindValue(4,table.getIsFree());
    return query->exec();
}

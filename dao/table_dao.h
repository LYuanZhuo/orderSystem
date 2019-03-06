#ifndef TABLE_DAO_H
#define TABLE_DAO_H
#include <QList>
#include "global_variable.h"
#include <entity/table_entity.h>
class Table_dao
{
public:
    Table_dao();
    Table_entity* getTable(int id);
    bool changeTable(Table_entity table);
    bool deleteTable(int id);
    bool addTable(Table_entity table);
    QList<Table_entity> getAllTables(int shopId);
    QList<Table_entity> getAllTables(int shopId,int n);
    QList<Table_entity> getFreeTables(int shopId);
    QList<Table_entity> getUsingTables(int shopId);
    bool setStatus(int tableId,bool isFree);
};

#endif // TABLE_DAO_H

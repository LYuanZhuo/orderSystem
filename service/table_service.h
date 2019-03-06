#ifndef TABLE_SERVICE_H
#define TABLE_SERVICE_H
#include <QList>
#include <entity/table_entity.h>

class Table_service
{
public:
    Table_service();
    Table_entity* getTable(int id);
    bool changeTable(Table_entity table);
    bool deleteTable(int id);
    bool addTable(Table_entity table);
    QList<Table_entity> getAllTables(int shopId);
    QList<Table_entity> getAllTables(int shopId,int n,int kind);
    QList<Table_entity> getFreeTables(int shopId);
    QList<Table_entity> getUsingTables(int shopId);
    bool setStatus(int tableId,bool isFree);

};

#endif // TABLE_SERVICE_H

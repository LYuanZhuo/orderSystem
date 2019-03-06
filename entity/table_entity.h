#ifndef TABLE_ENTITY_H
#define TABLE_ENTITY_H
#include <QString>

class Table_entity
{
public:
    Table_entity();

private:
    QString name;
    QString describe;
    int id;
    int size;
    int shopId;
    bool isFree;
public:
    QString getName();
    void setName(QString name);

    QString getDescribe();
    void setDescribe(QString describe);

    int getId();
    void setId(int id);

    int getSize();
    void setSize(int size);

    int getShopId();
    void setShopId(int shopId);

    bool getIsFree();
    void setIsFree(bool isFree);
};

#endif // TABLE_ENTITY_H

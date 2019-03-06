#ifndef CATEGORY_ENTITY_H
#define CATEGORY_ENTITY_H
#include <QString>

class Category_entity
{
public:
    Category_entity();
    int getId();
    void setId(int id);

    QString getName();
    void setName(QString name);

    int getShopId();
    void setShopId(int shopId);
private:
    int id;
    QString name;
    int shopId;
};

#endif // CATEGORY_ENTITY_H

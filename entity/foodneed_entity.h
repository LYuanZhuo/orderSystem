#ifndef FOODNEED_ENTITY_H
#define FOODNEED_ENTITY_H
#include <QString>

class FoodNeed_entity
{
public:
    FoodNeed_entity();

    int getId();
    void setId(int id);

    int getShopId();
    void setShopId(int shopId);

    int getNum();
    void setNum(int num);

    bool getIsOk();
    void setIsOk(bool isOk);

    QString getFoodName();
    void setFoodName(QString foodName);

    QString getTime();
    void setTime(QString time);

    QString getTableName();
    void setTableName(QString tableName);

    QString getOrderNum();
    void setOrderNum(QString orderNum);

    int getFoodId();
    void setFoodId(int foodId);

private:
    int id;
    int num;
    int shopId;
    int foodId;
    bool isOk;
    QString tableName;
    QString foodName;
    QString time;
    QString orderNum;
};

#endif // FOODNEED_ENTITY_H

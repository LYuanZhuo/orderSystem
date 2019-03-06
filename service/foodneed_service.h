#ifndef FOODNEED_SERVICE_H
#define FOODNEED_SERVICE_H
#include <QList>
#include <entity/foodneed_entity.h>
#include <entity/orderfood_entity.h>
class FoodNeed_service
{
public:
    FoodNeed_service();
    QList<FoodNeed_entity> getUnOK(int shopId);
    bool addFoodNeed(OrderFood_entity entity);
    bool setIsOk(int id, bool isOk);
    bool setCombineIsOK(int foodId, bool isOk);
    QList<FoodNeed_entity> getCombineUnOK(int shopId);

};

#endif // FOODNEED_SERVICE_H

#ifndef FOODNEED_DAO_H
#define FOODNEED_DAO_H
#include "entity/foodneed_entity.h"
#include <qlist.h>
class FoodNeed_dao
{
public:
    FoodNeed_dao();
    QList<FoodNeed_entity> getUnOK(int shopId);
    QList<FoodNeed_entity> getCombineUnOK(int shopId);
    bool addFoodNeed(FoodNeed_entity entity);
    bool setIsOk(int id,bool isOk);
    bool setCombineIsOK(int foodId,bool isOk);
};

#endif // FOODNEED_DAO_H

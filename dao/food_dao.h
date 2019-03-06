#ifndef FOOD_DAO_H
#define FOOD_DAO_H
#include "qlist.h"
#include "entity/food_entity.h"
#include "global_variable.h"
class Food_dao
{
public:
    Food_dao();
    QList<Food_entity> getAll(int shopId);
    QList<Food_entity> getCategoryFoods(int id);
    QList<Food_entity> search(QString keyword);
    Food_entity getFood(int id);
    bool addFood(Food_entity food);
    bool updateFood(Food_entity food);
    bool deleteFood(int id);
};

#endif // FOOD_DAO_H

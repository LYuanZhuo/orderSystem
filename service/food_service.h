#ifndef FOOD_SERVICE_H
#define FOOD_SERVICE_H
#include <qlist.h>
#include "dao/food_dao.h"
#include <entity/food_entity.h>


class Food_service
{
public:
    Food_service();
    QList<Food_entity> getAll(int shopId);
    QList<Food_entity> getCategoryFoods(int id);
    QList<Food_entity> search(QString keyword);
    QList<Food_entity> onlyOnSale(QList<Food_entity> list,bool isOnSale);

    QList<Food_entity> getCategoryFoods(QList<Food_entity> list,int id);

    Food_entity getFood(int id);
    bool addFood(Food_entity food);
    bool deleteFood(int id);
    bool updateFood(Food_entity food);

};

#endif // FOOD_SERVICE_H

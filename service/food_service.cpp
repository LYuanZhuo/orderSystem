#include "food_service.h"

Food_service::Food_service()
{

}

QList<Food_entity> Food_service::getAll(int shopId){
    Food_dao dao;
    return dao.getAll(shopId);
}

QList<Food_entity> Food_service::getCategoryFoods(int id){
    Food_dao dao;
    if(id==0){
        return dao.getAll(Global_variable::shopId);
    }
    return dao.getCategoryFoods(id);
}
QList<Food_entity> Food_service::search(QString keyword){
    Food_dao dao;
    return dao.search(keyword);
}

QList<Food_entity> Food_service::onlyOnSale(QList<Food_entity> list,bool isOnSale){
    if(!isOnSale) return list;
    QList<Food_entity> list1;
    for(int i=0;i<list.size();i++){
        if(list[i].getIsOnSale()){
            list1.append(list[i]);
        }
    }
    return list1;
}

Food_entity Food_service::getFood(int id){
    Food_dao dao;
    return dao.getFood(id);
}

bool Food_service::addFood(Food_entity food){
    Food_dao dao;
    return dao.addFood(food);
}
bool Food_service::deleteFood(int id){
    Food_dao dao;
    return dao.deleteFood(id);
}
bool Food_service::updateFood(Food_entity food){
    Food_dao dao;
    return dao.updateFood(food);
}

QList<Food_entity> Food_service::getCategoryFoods(QList<Food_entity> list,int id){
    QList<Food_entity> list1;
    if(id==0){
        return list;
    }
    for(int i=0;i<list.size();i++){
        if(list[i].getCategoryId()==id){
            list1.append(list[i]);
        }
    }
    return list1;
}

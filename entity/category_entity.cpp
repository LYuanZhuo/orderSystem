#include "category_entity.h"

Category_entity::Category_entity()
{

}

int Category_entity::getId(){
    return this->id;
}

void Category_entity::setId(int id){
    this->id = id;
}

QString Category_entity::getName(){
    return this->name;
}

void Category_entity::setName(QString name){
    this->name = name;
}

int Category_entity::getShopId(){
    return this->shopId;
}

void Category_entity::setShopId(int shopId){
    this->shopId = shopId;
}

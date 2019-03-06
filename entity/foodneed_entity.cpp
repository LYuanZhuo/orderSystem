#include "foodneed_entity.h"

FoodNeed_entity::FoodNeed_entity()
{

}
int FoodNeed_entity::getId(){
    return this->id;
}

void FoodNeed_entity::setId(int id){
    this->id = id;
}

int FoodNeed_entity::getShopId(){
    return this->shopId;
}

void FoodNeed_entity::setShopId(int shopId){
    this->shopId = shopId;
}

int FoodNeed_entity::getNum(){
    return this->num;
}

void FoodNeed_entity::setNum(int num){
    this->num = num;
}

bool FoodNeed_entity::getIsOk(){
    return this->isOk;
}

void FoodNeed_entity::setIsOk(bool isOk){
    this->isOk = isOk;
}

QString FoodNeed_entity::getFoodName(){
    return this->foodName;
}

void FoodNeed_entity::setFoodName(QString foodName){
    this->foodName = foodName;
}

QString FoodNeed_entity::getTime(){
    return this->time;
}

void FoodNeed_entity::setTime(QString time){
    this->time = time;
}

QString FoodNeed_entity::getTableName(){
    return this->tableName;
}

void FoodNeed_entity::setTableName(QString tableName){
    this->tableName = tableName;
}

QString FoodNeed_entity::getOrderNum(){
    return this->orderNum;
}

void FoodNeed_entity::setOrderNum(QString orderNum){
    this->orderNum = orderNum;
}

int FoodNeed_entity::getFoodId(){
    return this->foodId;
}

void FoodNeed_entity::setFoodId(int foodId){
    this->foodId = foodId;
}

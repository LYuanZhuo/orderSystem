#include "orderfood_entity.h"

OrderFood_entity::OrderFood_entity()
{

}

int OrderFood_entity::getFoodId(){
    return this->foodId;
}

void OrderFood_entity::setFoodId(int foodId){
    this->foodId = foodId;
}

int OrderFood_entity::getOrderId(){
    return this->orderId;
}

void OrderFood_entity::setOrderId(int orderId){
    this->orderId = orderId;
}

QString OrderFood_entity::getFoodName(){
    return this->foodName;
}

void OrderFood_entity::setFoodName(QString foodName){
    this->foodName = foodName;
}

int OrderFood_entity::getNum(){
    return this->num;
}

void OrderFood_entity::setNum(int num){
    this->num = num;
}

double OrderFood_entity::getPrice(){
    return this->price;
}

void OrderFood_entity::setPrice(double price){
    this->price = price;
}

double OrderFood_entity::getTotalPrice(){
    return this->totalPrice;
}

void OrderFood_entity::setTotalPrice(double totalPrice){
    this->totalPrice = totalPrice;
}

#include "order_entity.h"

Order_entity::Order_entity()
{

}

int Order_entity::getId(){
    return this->id;
}

void Order_entity::setId(int id){
    this->id = id;
}

int Order_entity::getTableId(){
    return this->tableId;
}

void Order_entity::setTableId(int tableId){
    this->tableId = tableId;
}

int Order_entity::getShopId(){
    return this->shopId;
}

void Order_entity::setShopId(int shopId){
    this->shopId = shopId;
}

int Order_entity::getPersonNum(){
    return this->personNum;
}

void Order_entity::setPersonNum(int personNum){
    this->personNum = personNum;
}

QString Order_entity::getOrderNum(){
    return this->orderNum;
}

void Order_entity::setOrderNum(QString orderNum){
    this->orderNum = orderNum;
}

bool Order_entity::getIsPay(){
    return this->isPay;
}

void Order_entity::setIsPay(bool isPay){
    this->isPay = isPay;
}

double Order_entity::getPrice(){
    return this->price;
}

void Order_entity::setPrice(double price){
    this->price = price;
}

QString Order_entity::getTime(){
    return this->time;
}

void Order_entity::setTime(QString time){
    this->time = time;
}

QString Order_entity::getPayTime(){
    return this->payTime;
}

void Order_entity::setPayTime(QString payTime){
    this->payTime = payTime;
}

QString Order_entity::getTableName(){
    return this->tableName;
}
void Order_entity::setTableName(QString tableName){
    this->tableName = tableName;
}


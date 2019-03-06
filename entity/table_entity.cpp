#include "table_entity.h"

Table_entity::Table_entity()
{

}
QString Table_entity::getName(){
    return this->name;
}

void Table_entity::setName(QString name){
    this->name = name;
}

QString Table_entity::getDescribe(){
    return this->describe;
}

void Table_entity::setDescribe(QString describe){
    this->describe = describe;
}

int Table_entity::getId(){
    return this->id;
}

void Table_entity::setId(int id){
    this->id = id;
}

int Table_entity::getSize(){
    return this->size;
}

void Table_entity::setSize(int size){
    this->size = size;
}

int Table_entity::getShopId(){
    return this->shopId;
}

void Table_entity::setShopId(int shopId){
    this->shopId = shopId;
}

bool Table_entity::getIsFree(){
    return this->isFree;
}

void Table_entity::setIsFree(bool isFree){
    this->isFree = isFree;
}

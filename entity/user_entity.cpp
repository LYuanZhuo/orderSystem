#include "user_entity.h"

User_entity::User_entity()
{

}
QString User_entity::getName(){
   return this->name;
}

void User_entity::setName(QString name){
    this->name = name;
}

QString User_entity::getAccount(){
   return this->account;
}

void User_entity::setAccount(QString account){
    this->account = account;
}

QString User_entity::getPassword(){
   return this->password;
}

void User_entity::setPassword(QString password){
    this->password = password;
}

int User_entity::getId(){
   return this->id;
}

void User_entity::setId(int id){
    this->id = id;
}

int User_entity::getShopId(){
   return this->shopId;
}

void User_entity::setShopId(int shopId){
    this->shopId = shopId;
}

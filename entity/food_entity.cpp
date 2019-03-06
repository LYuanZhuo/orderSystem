#include "food_entity.h"

Food_entity::Food_entity()
{

    this->imageAddress="";
    this->name="";
    this->price=0;
}

QString Food_entity::getImageAddress(){
    return this->imageAddress;
}
void Food_entity::setImageAddress(QString imageAddress){
    this->imageAddress = imageAddress;
}

QString Food_entity::getName(){
    return this->name;
}
void Food_entity::setName(QString name){
    this->name = name;
}

double Food_entity::getPrice(){
    return this->price;
}
void Food_entity::setPrice(double price){
    this->price = price;
}

int Food_entity::getId(){
    return this->id;
}
void Food_entity::setId(int id){
    this->id = id;
}

bool Food_entity::getIsOnSale(){
    return this->isOnSale;
}
void Food_entity::setOnSale(bool onSale){
    this->isOnSale = onSale;
}

double Food_entity::getSaleRate(){
    return this->saleRate;
}
void Food_entity::setSaleRate(double saleRate){
    this->saleRate = saleRate;
}

int Food_entity::getCategoryId(){
    return this->categoryId;
}
void Food_entity::setCategoryId(int categoryId){
    this->categoryId = categoryId;
}

int Food_entity::getShopId(){
    return this->shopId;
}
void Food_entity::setShopId(int shopId){
    this->shopId = shopId;
}

double Food_entity::getSalePrice(){
    return this->salePrice;
}
void Food_entity::setSalePrice(double salePrice){
    this->salePrice = salePrice;
}
QByteArray Food_entity::getImage(){
    return this->imageByte;
}
void Food_entity::setImage(QByteArray imageByte){
    this->imageByte = imageByte;
}

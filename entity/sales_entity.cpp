#include "sales_entity.h"

Sales_entity::Sales_entity()
{

}

QString Sales_entity::getDate(){
    return this->date;
}

void Sales_entity::setDate(QString date){
    this->date = date;
}

int Sales_entity::getNum(){
    return this->num;
}

void Sales_entity::setNum(int num){
    this->num = num;
}

double Sales_entity::getSum(){
    return this->sum;
}

void Sales_entity::setSum(double sum){
    this->sum = sum;
}

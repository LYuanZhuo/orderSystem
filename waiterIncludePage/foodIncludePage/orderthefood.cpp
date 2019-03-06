#include "orderthefood.h"
#include "ui_orderthefood.h"
#include "service/orderfood_service.h"
#include "service/food_service.h"
#include "service/order_service.h"
#include "service/foodneed_service.h"
#include "qmessagebox.h"
#include <qdebug.h>
#pragma execution_character_set("utf-8")
OrderTheFood::OrderTheFood(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderTheFood)
{
    ui->setupUi(this);
    this->ui->label_foodImage->setScaledContents(true);
}


OrderTheFood::~OrderTheFood()
{
    delete ui;
}

void OrderTheFood::init(int foodId, int tableId){

    Food_service food_service;
    Order_service order_service;
    this->food = food_service.getFood(foodId);
    this->order = order_service.getOrderByTableId(tableId);

    QPixmap pix;
    pix.loadFromData(this->food.getImage(),"jpg");
    this->ui->label_foodImage->setPixmap(pix);
    this->ui->label_name1->setText(this->food.getName());
    this->ui->label_price1->setText(this->food.getIsOnSale()?QString::number(this->food.getSalePrice()):QString::number(this->food.getPrice(),10,2));
    this->ui->label_totalPrice1->setText(this->food.getIsOnSale()?QString::number(this->food.getSalePrice()):QString::number(this->food.getPrice(),10,2));
}

void OrderTheFood::on_spinBox_valueChanged(int arg1)
{
    double price = ui->label_price1->text().toDouble();
    double totalPrice = price*arg1;
    this->ui->label_totalPrice1->setText(QString::number(totalPrice,10,2));
}

void OrderTheFood::on_pushButton_clicked()
{   OrderFood_entity orderFood;
    orderFood.setFoodId(this->food.getId());
    orderFood.setFoodName(this->food.getName());
    int n = ui->spinBox->value();
    orderFood.setNum(n);
    orderFood.setPrice(this->food.getIsOnSale()?this->food.getSalePrice():this->food.getPrice());
    double totalPrice = ui->spinBox->value()*orderFood.getPrice();
    orderFood.setTotalPrice(totalPrice);
    orderFood.setOrderId(this->order.getId());
    OrderFood_service orderFood_service;
    Order_service order_service;
    FoodNeed_service foodNeed_service;
    bool b = orderFood_service.addFoodToOrder(orderFood);
    bool b1 = order_service.updatePrice(this->order.getId(),totalPrice);
    bool b2 = foodNeed_service.addFoodNeed(orderFood);

    if(b&&b1&&b2){
        QMessageBox::information(this,"成功",this->food.getName()+"*"+QString::number(n),"确定");
        this->close();
    }else{
        QMessageBox::warning(this,"错误","数据库异常，点餐失败","确定");
    }
}

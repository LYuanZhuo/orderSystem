#include "waiter.h"
#include "ui_waiter.h"
#include <QMessageBox>
#include <QPushButton>
#include "login.h"
#include "global_variable.h"
#include "service/shop_service.h"
#include <QDebug>
#pragma execution_character_set("utf-8")
Waiter::Waiter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Waiter)
{
    ui->setupUi(this);
    setStyleSheet(
                "QPushButton:hover{"
                "color:white;"
                "}"

                "QPushButton{"
                "color:rgb(44 , 137 , 255);"
                "border: none;"


                "}"
                );


}

Waiter::~Waiter()
{
    delete ui;

}

void Waiter::init(){
    this->tablePage = new table;
    this->foodPage = new Food;
    this->orderPage = new Order;
    connect(this,SIGNAL(signalUpdateTable()),this->tablePage,SLOT(init()));
    connect(this,SIGNAL(signalUpdateFood()),this->foodPage,SLOT(init()));
    connect(this,SIGNAL(signalUpdateOrder()),this->orderPage,SLOT(init()));
    this->ui->stackedWidget->addWidget(this->tablePage);
    this->ui->stackedWidget->addWidget(this->foodPage);
    this->ui->stackedWidget->addWidget(this->orderPage);

    this->user = Global_variable::user;
    Shop_service shop_service;
    QString shopName = shop_service.getShopName(Global_variable::shopId);//获取商店名
    ui->label_shopName1->setText(shopName);//设置商店名
    ui->label_waiterName1->setText(this->user->getName());//设置用户名
    emit ui->pushButton_food->click();

}

void Waiter::deleteAll(){
    delete this->foodPage;
    delete this->tablePage;
    delete this->orderPage;
}
void Waiter::on_pushButton_table_clicked()
{
     setSelectStyle(1);
     emit signalUpdateTable();
     this->ui->stackedWidget->setCurrentWidget(this->tablePage);
}

void Waiter::on_pushButton_food_clicked()
{
     setSelectStyle(2);
     emit signalUpdateFood();
     this->ui->stackedWidget->setCurrentWidget(this->foodPage);
}

void Waiter::on_pushButton_order_clicked()
{
     setSelectStyle(3);
     emit signalUpdateOrder();
     this->ui->stackedWidget->setCurrentWidget(this->orderPage);
}

void Waiter::on_pushButton_exitLogin_clicked()
{
    int choice = QMessageBox::question(this,"退出登陆？","确定退出当前登录？","确定","取消");
    if(choice==0){
        this->close();
        emit waiterSignalShowMainWindow();
    }
}

void Waiter::setSelectStyle(int i){
    ui->pushButton_table->setStyleSheet("");
    ui->pushButton_food->setStyleSheet("");
    ui->pushButton_order->setStyleSheet("");
    QString style = "border-bottom: 2px solid rgb(44 , 137 , 255);color:white";
    switch(i){
    case 1: ui->pushButton_table->setStyleSheet(style);
    break;
    case 2: ui->pushButton_food->setStyleSheet(style);
    break;
    case 3: ui->pushButton_order->setStyleSheet(style);
    break;
    }
}

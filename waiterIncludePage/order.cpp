#include "order.h"
#include "ui_order.h"
#include <qdebug.h>

#pragma execution_character_set("utf-8")
Order::Order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Order)
{
    ui->setupUi(this);
    setStyleSheet(
    "QPushButton:hover{"
    "color:rgb(44 , 137 , 255);"
    "}"

    "QPushButton{"
    "color:rgb(50 , 50 , 50);"

    "border: none;"
    "}"
    );

    ui->tableWidget->setStyleSheet("color:white;background:transparent;");
    ui->tableWidget->horizontalHeader()->setStyleSheet("color:#666666;background:transparent;");
    ui->tableWidget->verticalHeader()->setHidden(true);
    //tableWidget设置列宽
    this->ui->tableWidget->setColumnWidth(0,70);
    this->ui->tableWidget->setColumnWidth(1,150);
    this->ui->tableWidget->setColumnWidth(2,40);
    this->ui->tableWidget->setColumnWidth(3,60);
    this->ui->tableWidget->setColumnWidth(4,170);
    this->ui->tableWidget->setColumnWidth(5,170);
    this->ui->tableWidget->setColumnWidth(6,80);
    this->ui->tableWidget->setColumnWidth(7,80);


    this->date = QDate::currentDate().toString("yyyy-MM-dd");
    ui->label_date ->setText(this->date);
    emit ui->pushButton_unOkOrder->click();//发出点击未完成订单按钮
}

Order::~Order()
{
    delete ui;
}

void Order::init(){
    emit ui->pushButton_unOkOrder->click();//发出点击未完成订单按钮
}

void Order::setSelectStyle(int i){
    ui->pushButton_allOrder->setStyleSheet("");
    ui->pushButton_unOkOrder->setStyleSheet("");
    ui->pushButton_okOrder->setStyleSheet("");
    QString style = "border-bottom:2px solid rgb(44 , 137 , 255);color:rgb(44 , 137 , 255)";
    switch(i){
    case 1: ui->pushButton_allOrder->setStyleSheet(style);
    break;
    case 2: ui->pushButton_unOkOrder->setStyleSheet(style);
    break;
    case 3: ui->pushButton_okOrder->setStyleSheet(style);
    break;
    }
}
void Order::setOrder(){

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    for(int i=0;i<this->order_list.size();i++){
         ui->tableWidget->insertRow(i);
         ui->tableWidget->setItem(i,0,new QTableWidgetItem(this->order_list[i].getTableName()));
         ui->tableWidget->setItem(i,1,new QTableWidgetItem(this->order_list[i].getOrderNum()));
         ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(this->order_list[i].getPersonNum())));
         ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(this->order_list[i].getPrice())));
         ui->tableWidget->setItem(i,4,new QTableWidgetItem(this->order_list[i].getTime()));
         ui->tableWidget->setItem(i,5,new QTableWidgetItem(this->order_list[i].getPayTime()));
         ui->tableWidget->setItem(i,6,new QTableWidgetItem(this->order_list[i].getIsPay()?"已结账":"未结账"));
         QTableWidgetItem* item = new QTableWidgetItem;
         item->setData(1,order_list[i].getId());
         item->setText("查看详情");
         ui->tableWidget->setItem(i,7,item);
    }
}
void Order::on_pushButton_allOrder_clicked()
{   setSelectStyle(1);
    Order_service order_service;
    this->orderType=1;
    this->order_list = order_service.getAll(Global_variable::shopId,this->orderType,this->date);
    setOrder();
}

void Order::on_pushButton_unOkOrder_clicked()
{
    setSelectStyle(2);
    Order_service order_service;
    this->orderType=2;
    this->order_list = order_service.getAll(Global_variable::shopId,this->orderType,this->date);
    setOrder();
}

void Order::on_pushButton_okOrder_clicked()
{
    setSelectStyle(3);
    Order_service order_service;
    this->orderType=3;
    this->order_list = order_service.getAll(Global_variable::shopId,this->orderType,this->date);
    setOrder();
}
void Order::setDate(QString date){
    this->date = date;
    ui->label_date->setText(this->date);
    Order_service order_service;
    this->order_list = order_service.getAll(Global_variable::shopId,this->orderType,this->date);
    setOrder();
}
void Order::on_pushButton_clicked()
{
    DateSelect *date = new DateSelect;
    connect(date,SIGNAL(signalDate(QString)),this,SLOT(setDate(QString)));
    date->exec();
}
void Order::update(){
    emit ui->pushButton_unOkOrder->click();
}
void Order::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    int orderId = item->data(1).toInt();
    if(orderId==0) return;
    OrderDetail *o = new OrderDetail;
    o->init(orderId);
    o->exec();
    update();
}

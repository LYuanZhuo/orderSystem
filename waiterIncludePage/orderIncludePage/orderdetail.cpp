#include "orderdetail.h"
#include "ui_orderdetail.h"
#include "service/order_service.h"
#include "service/table_service.h"
#include "service/orderfood_service.h"
#include <QTableWidgetItem>
#include <QDebug>
#include <qmessagebox.h>
#include <qdatetime.h>
#include "AdministratorInclude/order/editorder.h"
#pragma execution_character_set("utf-8")
OrderDetail::OrderDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderDetail)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStyleSheet("color:#666666;background:transparent;");
    ui->tableWidget->verticalHeader()->setHidden(true);
    ui->tableWidget->setColumnWidth(0,120);
    ui->tableWidget->setColumnWidth(1,60);
    ui->tableWidget->setColumnWidth(2,34);
    ui->tableWidget->setColumnWidth(3,80);
    if(Global_variable::loginType<3){
        ui->pushButton_edit->setEnabled(false);
    }
}

OrderDetail::~OrderDetail()
{
    delete ui;
}
void OrderDetail::init(int orderId){
    this->orderId = orderId;
    Order_service order_service;
    Table_service table_service;
    OrderFood_service orderFood_service;
    this->order = order_service.getOrder(this->orderId);
    if(order.getIsPay()){
        ui->pushButton_pay->setText("已结账");
        ui->pushButton_pay->setEnabled(false);
    }
    this->tableName = table_service.getTable(this->order.getTableId())->getName();
    ui->label_orderNum->setText(this->order.getOrderNum());
    ui->label_tableName->setText(this->tableName);
    ui->label_time->setText(this->order.getTime());
    this->orderFood_list = orderFood_service.getOrderFoods(this->orderId);
    setOrderFoods();
}

void OrderDetail::setOrderFoods(){
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    this->totalPrice = 0;
    for(int i=0;i<this->orderFood_list.size();i++){
    this->totalPrice+=this->orderFood_list[i].getTotalPrice();
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setItem(i,0,new QTableWidgetItem(this->orderFood_list[i].getFoodName()));
    ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(this->orderFood_list[i].getPrice())));
    ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(this->orderFood_list[i].getNum())));
    ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(this->orderFood_list[i].getTotalPrice())));
    }
    ui->label_totalPrice->setText(QString::number(this->totalPrice,10,2));
}


void OrderDetail::on_pushButton_pay_clicked()
{   int i = QMessageBox::question(this,"确认付款","确定桌号"+this->tableName+"已付款？","确认","取消");
    if(i==1) {
        return;
    }
    Order_service order_service;
    QDateTime time = QDateTime::currentDateTime();
    QString timeStr = time.toString("yyyy-MM-dd hh:mm:ss");
    if(order_service.pay(this->orderId,this->totalPrice,timeStr)){
        QMessageBox::information(this,"完成","结账成功！","确定");
        this->close();
    }else{
        QMessageBox::warning(this,"错误","数据库异常，结账失败！","确定");
    }

}


void OrderDetail::on_pushButton_edit_clicked()
{
    EditOrder e;
    e.init(this->orderId);
    e.exec();
    init(this->orderId);
}

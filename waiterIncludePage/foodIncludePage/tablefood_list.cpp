#include "tablefood_list.h"
#include "ui_tablefood_list.h"
#include "service/order_service.h"
#include "service/orderfood_service.h"
#include "QTableWidgetItem"
#include "service/table_service.h"
#include <QString>
#include <qdebug.h>
#include <qmessagebox.h>
#pragma execution_character_set("utf-8")
TableFood_list::TableFood_list(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableFood_list)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStyleSheet("color:#666666;background:transparent;");
    ui->tableWidget->verticalHeader()->setHidden(true);
    ui->tableWidget->setColumnWidth(0,120);
    ui->tableWidget->setColumnWidth(1,60);
    ui->tableWidget->setColumnWidth(2,34);
    ui->tableWidget->setColumnWidth(3,80);
}

TableFood_list::~TableFood_list()
{
    delete ui;
}
void TableFood_list::setList(QList<OrderFood_entity> list){
    this->totalPrice=0;
    this->totalNum = 0;
    this->foodNum = list.size();
    for(int i=0;i<list.size();i++){
        this->totalPrice+=list[i].getTotalPrice();
        this->totalNum+=list[i].getNum();
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(list[i].getFoodName()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(list[i].getPrice(),10,2)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(list[i].getNum())));
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText("删除");
        item->setData(Qt::UserRole,list[i].getFoodId());
        ui->tableWidget->setItem(i,3,item);
    }
    ui->label_totalPrice->setText(QString::number(this->totalPrice,10,2));
    ui->label_totalNum->setText(QString::number(this->totalNum));
    ui->label_foodNum->setText(QString::number(this->foodNum));
}
void TableFood_list::init(int tableId){
     this->tableId = tableId;
     Table_service table_service;
     Order_service order_service;
     OrderFood_service orderFood_service;
     QString tableName = "桌号："+table_service.getTable(tableId)->getName();
     setWindowTitle(tableName);
     this->order = order_service.getOrderByTableId(tableId);
     this->list = orderFood_service.getOrderFoods(this->order.getId());
     setList(this->list);
}



void TableFood_list::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    OrderFood_service service;
    int foodId = item->data(Qt::UserRole).toInt();
    qDebug()<<"orderId:"<<this->order.getId();
    qDebug()<<"foodid:"<<foodId;
    if(!service.deleteFoodOrder(this->order.getId(),foodId)){
            QMessageBox::warning(this,"错误","删除失败！","确定");
}
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    OrderFood_service orderFood_service;
    this->list = orderFood_service.getOrderFoods(this->order.getId());
    setList(this->list);

}

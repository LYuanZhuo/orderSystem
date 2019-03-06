#include "kitchen.h"
#include "ui_kitchen.h"
#include <service/foodneed_service.h>
#include <service/shop_service.h>
#include <global_variable.h>
#include <qdebug.h>
#include <qmessagebox.h>

#pragma execution_character_set("utf-8")
Kitchen::Kitchen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kitchen)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStyleSheet("color:#666666;background:transparent;");


    Shop_service service;
    QString shopName = service.getShopName(Global_variable::shopId);
    ui->label_shopName->setText(shopName);
    setWindowTitle(shopName+"的厨房");
    this->qTimer = new QTimer;
    connect(qTimer,SIGNAL(timeout()),this,SLOT(flash()));
    qTimer->start(this->flashSec*1000);
    update(1);
}

Kitchen::~Kitchen()
{
    delete ui;
}

void Kitchen::update(int status){
    if(status==1){
        QStringList headers;
        headers << "菜名" << "数量" << "桌号"<<
                   "订单号"<< "时间"<<"操作";
        ui->tableWidget->setColumnCount(6);
        ui->tableWidget->clear();
        ui->tableWidget->setHorizontalHeaderLabels(headers);
        ui->tableWidget->setColumnWidth(0,160);
        ui->tableWidget->setColumnWidth(2,100);
        ui->tableWidget->setColumnWidth(3,250);
        ui->tableWidget->setColumnWidth(4,250);
        FoodNeed_service service;
        this->list = service.getUnOK(Global_variable::shopId);
        setList(this->list);
    }else if(status==2){
        QStringList headers;
        ui->tableWidget->setColumnCount(3);
        headers << "菜名" << "数量" << "操作";
        ui->tableWidget->clear();
        ui->tableWidget->setHorizontalHeaderLabels(headers);
        ui->tableWidget->setColumnWidth(0,400);
        ui->tableWidget->setColumnWidth(1,300);
        ui->tableWidget->setColumnWidth(2,100);
        FoodNeed_service service;
        this->list = service.getCombineUnOK(Global_variable::shopId);
        setList1(this->list);
    }
}

void Kitchen::setList(QList<FoodNeed_entity> list){
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    for(int i=0;i<list.size();i++){
          ui->tableWidget->insertRow(i);
          ui->tableWidget->setItem(i,0,new QTableWidgetItem(list[i].getFoodName()));
          ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(list[i].getNum())));
          ui->tableWidget->setItem(i,2,new QTableWidgetItem(list[i].getTableName()));
          ui->tableWidget->setItem(i,3,new QTableWidgetItem(list[i].getOrderNum()));
          ui->tableWidget->setItem(i,4,new QTableWidgetItem(list[i].getTime()));
          QTableWidgetItem *item = new QTableWidgetItem;
          item->setData(1,list[i].getId());
          item->setText("完成");
          ui->tableWidget->setItem(i,5,item);
    }
}

void Kitchen::setList1(QList<FoodNeed_entity> list){
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    for(int i=0;i<list.size();i++){
          ui->tableWidget->insertRow(i);
          ui->tableWidget->setItem(i,0,new QTableWidgetItem(list[i].getFoodName()));
          ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(list[i].getNum())));
          QTableWidgetItem *item = new QTableWidgetItem;
          item->setData(1,list[i].getFoodId());
          item->setText("完成");
          ui->tableWidget->setItem(i,2,item);
    }
}
void Kitchen::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    bool ok = false;
    if(this->status==1){
        int id = item->data(1).toInt();
        if(id==0) return;
        FoodNeed_service service;
        ok = service.setIsOk(id,true);
    }else if(this->status==2){
        int foodId = item->data(1).toInt();
        if(foodId==0) return;
        FoodNeed_service service;
        ok = service.setCombineIsOK(foodId,true);
    }
    if(ok){
        QMessageBox::information(this,"成功","已完成！","确定");
    }else{
        QMessageBox::warning(this,"失败","系统异常，请求未完成","确定");
    }
    update(this->status);
}

void Kitchen::on_pushButton_flash_clicked()
{
     update(this->status);
}

void Kitchen::on_checkBox_stateChanged(int arg1)
{
    if(arg1==0) {
        this->status = 1;
        update(this->status);
    }else{
        this->status = 2;
        update(this->status);
    }
}

void Kitchen::on_pushButton_quitLogin_clicked()
{
    int b = QMessageBox::question(this,"退出","确认退出登陆?","确定","取消");
    if(b==1) return;
    this->close();
    emit signalShowMainWindow();
}

void Kitchen::flash(){
    update(this->status);
}
void Kitchen::on_spinBox_valueChanged(int arg1)
{

    this->flashSec = arg1;
    qTimer->start(this->flashSec*1000);
}

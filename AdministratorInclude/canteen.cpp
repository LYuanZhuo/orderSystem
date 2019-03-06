#include "canteen.h"
#include "ui_canteen.h"
#include "global_variable.h"
#include "service/shop_service.h"
#include <QDate>
#include <qdatetime.h>
#include <QTableWidgetItem>

Canteen::Canteen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canteen)
{
    ui->setupUi(this);
    ui->tableWidget->setStyleSheet("color:white;background:transparent;");
    ui->tableWidget->horizontalHeader()->setStyleSheet("color:#666666;background:transparent;");
    ui->tableWidget->setColumnWidth(0,140);
    ui->tableWidget->setColumnWidth(1,140);
    ui->tableWidget->setColumnWidth(2,140);


    ui->tableWidget->verticalHeader()->setHidden(true);
    this->sale.setNum(0);
    this->sale.setSum(0);
    updateShop();
    this->qtimer = new QTimer;
    connect(this->qtimer,SIGNAL(timeout()),this,SLOT(updateShop()));
    this->qtimer->start(10000);
}

Canteen::~Canteen()
{
    delete ui;
}

void Canteen::updateShop(){

    QString date1 = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->label_date->setText(date1);

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    this->list = service.getSales(Global_variable::shopId);
    this->tableInfo = service.getTables(Global_variable::shopId);
    if(this->list.size()>0){
    if(QString::compare(list[0].getDate(),date)==0){
        this->sale = list[0];
    }
    }
    Shop_service shop_service;
    ui->label_name->setText(shop_service.getShopName(Global_variable::shopId));
    ui->label_tableFree->setText(QString::number(this->tableInfo[0]));
    ui->label_tableUse->setText(QString::number(this->tableInfo[1]));
    ui->label_orderNum->setText(QString::number(this->sale.getNum()));
    ui->label_sum->setText(QString::number(this->sale.getSum()));
    setList();
}

void Canteen::setList(){
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    for(int i=0;i<this->list.size();i++){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(this->list[i].getDate()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(this->list[i].getNum())));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(this->list[i].getSum())));
    }
}

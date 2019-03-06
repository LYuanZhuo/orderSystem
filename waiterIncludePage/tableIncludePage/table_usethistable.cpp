#include "table_usethistable.h"
#include "ui_table_usethistable.h"
#include "service/table_service.h"
#include <QDateTime>
#include "entity/order_entity.h"
#include "global_variable.h"
#include "service/order_service.h"
#include "service/table_service.h"
#include <QDebug>
#include <QMessageBox>
#pragma execution_character_set("utf-8")
table_usethistable::table_usethistable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_usethistable)
{
    ui->setupUi(this);

}

table_usethistable::~table_usethistable()
{
    delete ui;
}
void table_usethistable::init(int tableId){
    this->tableId = tableId;
    Table_service table_service;
    this->table = table_service.getTable(this->tableId);
    ui->label_tableName->setText(this->table->getName());
}

void table_usethistable::on_pushButton_clicked()
{
    Order_entity order;
    QDateTime time = QDateTime::currentDateTime();
    order.setTime(time.toString("yyyy-MM-dd hh:mm:ss"));
    order.setIsPay(false);
    order.setOrderNum(time.toString("yyyyMMddhhmmsszzz"));
    order.setPersonNum(ui->spinBox->value());
    order.setPrice(0);
    order.setShopId(Global_variable::shopId);
    order.setTableId(this->table->getId());
    order.setTableName(this->table->getName());
    Order_service order_service;
    Table_service table_service;
    if(order_service.addOrder(order)&&table_service.setStatus(this->table->getId(),false)){
        QMessageBox::warning(this,"成功","开桌成功","确定");
    }else{
        QMessageBox::warning(this,"异常","服务器异常！开桌失败","确定");
    }
    this->close();
    emit signalUpdate();//发出让table界面更新信号
    delete this->table;
}

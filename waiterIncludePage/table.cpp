#include "table.h"
#include "ui_table.h"
#include <QPushButton>
#include <QLabel>
#include "tableIncludePage/table_usethistable.h"
#include "service/table_service.h"
#include "global_variable.h"
#include "entity/table_entity.h"
#include <qdebug.h>
#include <qmessagebox.h>
#pragma execution_character_set("utf-8")
table::table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::table)
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
    this->ui->tableWidget->setColumnWidth(0,160);
    this->ui->tableWidget->setColumnWidth(1,160);
    this->ui->tableWidget->setColumnWidth(2,160);
    this->ui->tableWidget->setColumnWidth(3,160);
    this->ui->tableWidget->setColumnWidth(4,160);
    emit ui->pushButton_freeTable->click();//发出 点击查看空闲的桌子按钮 信号
}

table::~table()
{
    delete ui;
}

void table::init(){
    emit ui->pushButton_freeTable->click();//发出 点击查看空闲的桌子按钮 信号
}

void table::on_pushButton_allTable_clicked()
{
    ui->spinBox->setValue(0);
    this->tableKind=1;
    Table_service service;
    this->table_list = service.getAllTables(Global_variable::shopId);
    setTableList();
    setSelectStyle(1);


}

void table::on_pushButton_freeTable_clicked()
{
    ui->spinBox->setValue(0);
    this->tableKind=2;
    Table_service service;
    this->table_list = service.getFreeTables(Global_variable::shopId);
    setTableList();
    setSelectStyle(2);


}

void table::on_pushButton_UsingTable_clicked()
{
    ui->spinBox->setValue(0);
    this->tableKind=3;
    Table_service service;
    this->table_list = service.getUsingTables(Global_variable::shopId);
    setTableList();
    setSelectStyle(3);

}

void table::on_pushButton_certain_clicked()
{
       int personNum = ui->spinBox->value();
       Table_service service;
       this->table_list = service.getAllTables(Global_variable::shopId,personNum,this->tableKind);
       setTableList();

}
void table::setTableList(){
       ui->tableWidget->clearContents();
       ui->tableWidget->setRowCount(0);
       for(int i=0;i<this->table_list.size();i++){
       ui->tableWidget->insertRow(i);
       ui->tableWidget->setItem(i,0,new QTableWidgetItem(this->table_list[i].getName()));
       ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(this->table_list[i].getSize())));
       ui->tableWidget->setItem(i,2,new QTableWidgetItem(this->table_list[i].getDescribe()));
       ui->tableWidget->setItem(i,3,new QTableWidgetItem(this->table_list[i].getIsFree()?"是":"否"));
       QTableWidgetItem *item = new QTableWidgetItem;
       item->setData(1,this->table_list[i].getId());
       item->setText("使用此桌");
       item->setTextColor(QColor(255,255,255));
       ui->tableWidget->setItem(i,4,item);

    }
}

void table::setSelectStyle(int i){
    ui->pushButton_allTable->setStyleSheet("");
    ui->pushButton_freeTable->setStyleSheet("");
    ui->pushButton_UsingTable->setStyleSheet("");
    QString style = "border-bottom:2px solid rgb(44 , 137 , 255);color:rgb(44 , 137 , 255)";
    switch(i){
    case 1: ui->pushButton_allTable->setStyleSheet(style);
    break;
    case 2: ui->pushButton_freeTable->setStyleSheet(style);
    break;
    case 3: ui->pushButton_UsingTable->setStyleSheet(style);
    break;
    }
}

void table::on_spinBox_valueChanged(int arg1)
{
    ui->pushButton_certain->click();
}

void table::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    if(item->data(1).toInt()==0) return;
    int tableId = item->data(1).toInt();
    Table_service service;
    if(!service.getTable(tableId)->getIsFree()){
        QMessageBox::warning(this,"正在使用","此桌还未结账，暂无法使用","确定");
        return;
    }
    table_usethistable *t = new table_usethistable;
    connect(t,SIGNAL(signalUpdate()),this,SLOT(init()));
    t->init(tableId);
    t->exec();
}

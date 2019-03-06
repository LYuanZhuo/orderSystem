#include "table_a.h"
#include "ui_table_a.h"
#include "global_variable.h"
#include "service/table_service.h"
#include <QMessageBox>
#include "table/changetable.h"
#include <qdebug.h>
#pragma execution_character_set("utf-8")
Table_a::Table_a(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table_a)
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
    this->ui->tableWidget->setColumnWidth(0,140);
    this->ui->tableWidget->setColumnWidth(1,140);
    this->ui->tableWidget->setColumnWidth(2,180);
    this->ui->tableWidget->setColumnWidth(3,170);
    this->ui->tableWidget->setColumnWidth(4,170);


    ui->tableWidget->verticalHeader()->setHidden(true);
    init();
}

Table_a::~Table_a()
{
    delete ui;
}
void Table_a::init(){
    Table_service service;
    this->table_list = service.getAllTables(Global_variable::shopId);
    setTableList();
}

void Table_a::setTableList(){
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    for(int i=0;i<this->table_list.size();i++){
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setItem(i,0,new QTableWidgetItem(this->table_list[i].getName()));
    ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(this->table_list[i].getSize())));
    ui->tableWidget->setItem(i,2,new QTableWidgetItem(this->table_list[i].getDescribe()));
    QTableWidgetItem *item1 = new QTableWidgetItem;
    item1->setData(Qt::UserRole,this->table_list[i].getId());
    item1->setText("编辑");
    ui->tableWidget->setItem(i,3,item1);

    QTableWidgetItem *item2 = new QTableWidgetItem;
    item2->setData(Qt::UserRole+1,this->table_list[i].getId());
    item2->setText("删除");
    item2->setTextColor(QColor(139,0,0));
    ui->tableWidget->setItem(i,4,item2);
 }
}

void Table_a::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    if(item->data(Qt::UserRole).toInt()==0&&item->data(Qt::UserRole+1).toInt()==0) return;
    qDebug()<<item->data(Qt::UserRole).toInt();
    qDebug()<<item->data(Qt::UserRole+1).toInt();
    if(item->data(Qt::UserRole).toInt()!=0){
        int tableId = item->data(Qt::UserRole).toInt();
        ChangeTable t;
        t.init(tableId);
        t.exec();
        init();
    }else if(item->data(Qt::UserRole+1).toInt()!=0){
        int i = QMessageBox::warning(this,"确认","确认删除此桌？","确认","取消");
        if(i==0){
            Table_service service;
            if(service.deleteTable(item->data(Qt::UserRole+1).toInt())){
                QMessageBox::information(this,"成功","删除成功","确认");
                init();
            }else{
                QMessageBox::warning(this,"失败","删除失败","确认");
            }
        }
    }
}

void Table_a::on_pushButton_clicked()
{
    ChangeTable t;
    t.init(0);
    t.exec();
    init();
}

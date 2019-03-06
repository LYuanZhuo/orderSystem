#include "employee.h"
#include "ui_employee.h"
#include "global_variable.h"
#include <QTableWidgetItem>
#include <qdebug.h>
#include "employee/editemployee.h"
#include <qmessagebox.h>
#pragma execution_character_set("utf-8")
Employee::Employee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Employee)
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

    ui->tableWidget_kitchen->setStyleSheet("color:white;background:transparent;");
    ui->tableWidget_kitchen->horizontalHeader()->setStyleSheet("color:#666666;background:transparent;");
    ui->tableWidget_waiter->setStyleSheet("color:white;background:transparent;");
    ui->tableWidget_waiter->horizontalHeader()->setStyleSheet("color:#666666;background:transparent;");
    ui->tableWidget_kitchen->verticalHeader()->setHidden(true);
    ui->tableWidget_waiter->verticalHeader()->setHidden(true);
    ui->tableWidget_kitchen->setColumnWidth(0,81);
    ui->tableWidget_kitchen->setColumnWidth(1,81);
    ui->tableWidget_kitchen->setColumnWidth(2,81);
    ui->tableWidget_kitchen->setColumnWidth(3,81);
    ui->tableWidget_kitchen->setColumnWidth(4,81);
    ui->tableWidget_waiter->setColumnWidth(0,81);
    ui->tableWidget_waiter->setColumnWidth(1,81);
    ui->tableWidget_waiter->setColumnWidth(2,81);
    ui->tableWidget_waiter->setColumnWidth(3,81);
    ui->tableWidget_waiter->setColumnWidth(4,81);

    update_k();
    update_w();

}

Employee::~Employee()
{
    delete ui;
}

void Employee::update_k(){
    this->list_k = this->service.getKitchenUsers(Global_variable::shopId);
    qDebug()<<list_k.size();
    setKitchen();
}
void Employee::update_w(){
    this->list_w = this->service.getWaiterUsers(Global_variable::shopId);
    setWaiter();
}
void Employee::setKitchen(){
    ui->tableWidget_kitchen->clearContents();
    ui->tableWidget_kitchen->setRowCount(0);
    for(int i=0;i<list_k.size();i++){
        ui->tableWidget_kitchen->insertRow(i);
        ui->tableWidget_kitchen->setItem(i,0,new QTableWidgetItem(list_k[i].getName()));
        ui->tableWidget_kitchen->setItem(i,1,new QTableWidgetItem(list_k[i].getAccount()));
        ui->tableWidget_kitchen->setItem(i,2,new QTableWidgetItem(list_k[i].getPassword()));
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText("编辑");
        item->setData(Qt::UserRole,list_k[i].getId());
        ui->tableWidget_kitchen->setItem(i,3,item);

        QTableWidgetItem* item1 = new QTableWidgetItem;
        item1->setText("删除");
        item1->setData(Qt::UserRole+1,list_k[i].getId());
        item1->setTextColor(QColor(139,0,0));
        ui->tableWidget_kitchen->setItem(i,4,item1);
    }
}
void Employee::setWaiter(){
    ui->tableWidget_waiter->clearContents();
    ui->tableWidget_waiter->setRowCount(0);

    for(int i=0;i<list_w.size();i++){
        ui->tableWidget_waiter->insertRow(i);
        ui->tableWidget_waiter->setItem(i,0,new QTableWidgetItem(list_w[i].getName()));
        ui->tableWidget_waiter->setItem(i,1,new QTableWidgetItem(list_w[i].getAccount()));
        ui->tableWidget_waiter->setItem(i,2,new QTableWidgetItem(list_w[i].getPassword()));
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText("编辑");
        item->setData(Qt::UserRole,list_w[i].getId());
        ui->tableWidget_waiter->setItem(i,3,item);

        QTableWidgetItem* item1 = new QTableWidgetItem;
        item1->setText("删除");
        item1->setData(Qt::UserRole+1,list_w[i].getId());
        item1->setTextColor(QColor(139,0,0));
        ui->tableWidget_waiter->setItem(i,4,item1);
    }
}

void Employee::on_tableWidget_waiter_itemClicked(QTableWidgetItem *item)
{
    int data1 = item->data(Qt::UserRole).toInt();
    int data2 = item->data(Qt::UserRole+1).toInt();
    if(data1==0&&data2==0) return;
    if(data1!=0){
        EditEmployee e;
        e.init(data1,1);
        e.exec();
        update_w();
    }else if(data2!=0){
        int i = QMessageBox::warning(this,"确认删除","是否要删除此账号","确认","取消");
        if(i==0){
            User_service service;
            if(service.deleteUser_w(data2)){
                QMessageBox::information(this,"成功","已删除此账号","确认");
                update_w();
            }else{
                QMessageBox::warning(this,"失败","删除失败","确认");
            }
        }
    }
}

void Employee::on_tableWidget_kitchen_itemClicked(QTableWidgetItem *item)
{
    int data1 = item->data(Qt::UserRole).toInt();
    int data2 = item->data(Qt::UserRole+1).toInt();
    if(data1==0&&data2==0) return;
    if(data1!=0){
        EditEmployee e;
        e.init(data1,2);
        e.exec();
        update_k();
    }else if(data2!=0){
        int i = QMessageBox::warning(this,"确认删除","是否要删除此账号","确认","取消");
        if(i==0){
            User_service service;
            if(service.deleteUser_k(data2)){
                QMessageBox::information(this,"成功","已删除此账号","确认");
                update_k();
            }else{
                QMessageBox::warning(this,"失败","删除失败","确认");
            }
        }
    }
}

void Employee::on_pushButton_waiter_clicked()
{
    EditEmployee e;
    e.init(-1,1);
    e.exec();
    update_w();
}

void Employee::on_pushButton_kitchen_clicked()
{
    EditEmployee e;
    e.init(-1,2);
    e.exec();
    update_k();
}





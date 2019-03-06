#include "administrator.h"
#include "ui_administrator.h"
#include <qmessagebox.h>
#pragma execution_character_set("utf-8")
Administrator::Administrator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Administrator)
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



    this->canteen = new Canteen;
    this->food = new Food_a;
    this->table = new Table_a;
    this->order = new Order_a;
    this->employee = new Employee;
    ui->stackedWidget->addWidget(this->canteen);
    ui->stackedWidget->addWidget(this->employee);
    ui->stackedWidget->addWidget(this->table);
    ui->stackedWidget->addWidget(this->order);
    ui->stackedWidget->addWidget(this->food);
    emit ui->pushButton_canteen->click();
}

Administrator::~Administrator()
{
    delete ui;
}

void Administrator::setSelectStyle(int i){
    ui->pushButton_table->setStyleSheet("");
    ui->pushButton_food->setStyleSheet("");
    ui->pushButton_order->setStyleSheet("");
    ui->pushButton_canteen->setStyleSheet("");
    ui->pushButton_employee->setStyleSheet("");
    QString style = "border-bottom:2px solid rgb(44 , 137 , 255);color:white;";
    switch(i){
    case 1: ui->pushButton_canteen->setStyleSheet(style);
    break;
    case 2: ui->pushButton_table->setStyleSheet(style);
    break;
    case 3: ui->pushButton_food->setStyleSheet(style);
    break;
    case 4: ui->pushButton_order->setStyleSheet(style);
    break;
    case 5: ui->pushButton_employee->setStyleSheet(style);
    break;

    }
}
void Administrator::on_pushButton_canteen_clicked()
{
    setSelectStyle(1);
    ui->stackedWidget->setCurrentWidget(this->canteen);
}

void Administrator::on_pushButton_table_clicked()
{
    setSelectStyle(2);
    ui->stackedWidget->setCurrentWidget(this->table);
}

void Administrator::on_pushButton_food_clicked()
{
    setSelectStyle(3);
    ui->stackedWidget->setCurrentWidget(this->food);
}

void Administrator::on_pushButton_order_clicked()
{
    setSelectStyle(4);
    ui->stackedWidget->setCurrentWidget(this->order);
}

void Administrator::on_pushButton_employee_clicked()
{
    setSelectStyle(5);
    ui->stackedWidget->setCurrentWidget(this->employee);
}

void Administrator::deleteAll(){
    delete this->food;
    delete this->order;
    delete this->employee;
    delete this->table;
    delete this->canteen;
}
void Administrator::on_pushButton_exit_clicked()
{
    int i = QMessageBox::warning(this,"确认退出","是否退出当前登录","确定","取消");
    if(i==0){
        emit signalShowMainWindow();
        deleteAll();
        this->close();
    }
}

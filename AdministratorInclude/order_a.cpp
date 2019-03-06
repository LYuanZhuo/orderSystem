#include "order_a.h"
#include "ui_order_a.h"
#include <qmessagebox.h>
Order_a::Order_a(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Order_a)
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
    this->ui->tableWidget->setColumnWidth(0,60);
    this->ui->tableWidget->setColumnWidth(1,140);
    this->ui->tableWidget->setColumnWidth(2,40);
    this->ui->tableWidget->setColumnWidth(3,60);
    this->ui->tableWidget->setColumnWidth(4,165);
    this->ui->tableWidget->setColumnWidth(5,165);
    this->ui->tableWidget->setColumnWidth(6,80);
    this->ui->tableWidget->setColumnWidth(7,80);
    this->ui->tableWidget->setColumnWidth(8,60);


    this->date = QDate::currentDate().toString("yyyy-MM-dd");
    ui->label_date ->setText(this->date);
    emit ui->pushButton_allOrder->click();//发出点击未完成订单按钮
}

Order_a::~Order_a()
{
    delete ui;
}

void Order_a::init(){
    emit ui->pushButton_allOrder->click();//发出点击未完成订单按钮
}

void Order_a::setSelectStyle(int i){
    ui->pushButton_allOrder->setStyleSheet("");
    ui->pushButton_unOkOrder->setStyleSheet("");
    ui->pushButton_okOrder->setStyleSheet("");
    switch(i){
    case 1: ui->pushButton_allOrder->setStyleSheet("border-bottom:2px solid rgb(44 , 137 , 255);color:rgb(44 , 137 , 255)");
    break;
    case 2: ui->pushButton_unOkOrder->setStyleSheet("border-bottom:2px solid rgb(44 , 137 , 255);color:rgb(44 , 137 , 255)");
    break;
    case 3: ui->pushButton_okOrder->setStyleSheet("border-bottom:2px solid rgb(44 , 137 , 255);color:rgb(44 , 137 , 255)");
    break;
    }
}
void Order_a::setOrder(){

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
         item->setData(Qt::UserRole,order_list[i].getId());
         item->setText("查看详情");
         ui->tableWidget->setItem(i,7,item);

         QTableWidgetItem* item1 = new QTableWidgetItem;
         item1->setData(Qt::UserRole+1,order_list[i].getId());
         item1->setText("删除");
         item1->setTextColor(QColor(139,0,0));
         ui->tableWidget->setItem(i,8,item1);
    }
}
void Order_a::on_pushButton_allOrder_clicked()
{   setSelectStyle(1);
    Order_service order_service;
    this->orderType=1;
    this->order_list = order_service.getAll(Global_variable::shopId,this->orderType,this->date);
    setOrder();
}

void Order_a::on_pushButton_unOkOrder_clicked()
{
    setSelectStyle(2);
    Order_service order_service;
    this->orderType=2;
    this->order_list = order_service.getAll(Global_variable::shopId,this->orderType,this->date);
    setOrder();
}

void Order_a::on_pushButton_okOrder_clicked()
{
    setSelectStyle(3);
    Order_service order_service;
    this->orderType=3;
    this->order_list = order_service.getAll(Global_variable::shopId,this->orderType,this->date);
    setOrder();
}
void Order_a::setDate(QString date){
    this->date = date;
    ui->label_date->setText(this->date);
    Order_service order_service;
    this->order_list = order_service.getAll(Global_variable::shopId,this->orderType,this->date);
    setOrder();
}
void Order_a::on_pushButton_clicked()
{
    DateSelect *date = new DateSelect;
    connect(date,SIGNAL(signalDate(QString)),this,SLOT(setDate(QString)));
    date->exec();
}
void Order_a::update(){
    emit ui->pushButton_allOrder->click();
}
void Order_a::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    if(item->data(Qt::UserRole).toInt()==0&&item->data(Qt::UserRole+1).toInt()==0) return;
    if(item->data(Qt::UserRole).toInt()!=0){
    int orderId = item->data(Qt::UserRole).toInt();
    OrderDetail *o = new OrderDetail;
    o->init(orderId);
    o->exec();
    update();
    }else if(item->data(Qt::UserRole+1).toInt()!=0){
        int id = item->data(Qt::UserRole+1).toInt();
        Order_service service;
        if(!service.getOrder(id).getIsPay()){
            QMessageBox::warning(this,"错误","请先为此订单结账再进行删除操作！","确定");
            return;
        }
        int i = QMessageBox::warning(this,"确认删除","确定删除此订单?此操作不可逆","确定","取消");
        if(i==0){
            if(service.deleteOrder(id)){
                QMessageBox::information(this,"成功","订单已删除","确认");
                        init();
                    }else{
                        QMessageBox::warning(this,"失败","删除失败","确认");
                    }

            }
        }
    }

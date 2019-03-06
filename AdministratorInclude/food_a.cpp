#include "food_a.h"
#include "ui_food_a.h"
#include "service/food_service.h"
#include "service/category_service.h"
#include "food/fooddetail.h"
#include "food/categorydetail.h"
#include <QDebug>
#pragma execution_character_set("utf-8")
Food_a::Food_a(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Food_a)
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

    ui->listWidget_category->setStyleSheet("color:white;background:transparent;");
    ui->tableWidget_food->setStyleSheet("color:white;background:transparent;");
    ui->tableWidget_food->horizontalHeader()->setStyleSheet("color:#666666;background:transparent;");
    ui->tableWidget_food->setShowGrid(false);
    ui->tableWidget_food->setStyleSheet(
    "QTableWidget::Item{"
    "border-bottom:1px solid rgb(200,200,200);}"
    );

    ui->tableWidget_food->verticalHeader()->setHidden(true);
    ui->tableWidget_food->setColumnWidth(0,140);
    ui->tableWidget_food->setColumnWidth(1,85);
    ui->tableWidget_food->setColumnWidth(2,85);
    ui->tableWidget_food->setColumnWidth(3,85);
    ui->tableWidget_food->setColumnWidth(4,85);
    ui->tableWidget_food->setColumnWidth(5,83);

    Food_service food_service;
    this->food_list = food_service.getAll(Global_variable::shopId);
    setFoods(this->food_list);
    Category_service category_service;
    this->category_list = category_service.getAll(Global_variable::shopId);
    setCategorys(this->category_list);
}

void Food_a::init(){

}
void Food_a::updateCategory(){
    Category_service category_service;
    this->category_list = category_service.getAll(Global_variable::shopId);
    setCategorys(this->category_list);
}
void Food_a::updateFood(){
    Food_service food_service;
    this->food_list = food_service.getAll(Global_variable::shopId);
    setFoods(this->food_list);
}
void Food_a::setFoods(QList<Food_entity> food_list){
    ui->tableWidget_food->clearContents();
    ui->tableWidget_food->setRowCount(0);
    for(int i=0;i<food_list.size();i++){
    ui->tableWidget_food->insertRow(i);
    QPixmap pix;
    pix.loadFromData(food_list[i].getImage(),"jpg");
    QIcon icon;
    icon.addPixmap(pix);
    ui->tableWidget_food->setRowHeight(i,100);
    ui->tableWidget_food->setItem(i,0,new QTableWidgetItem(icon,""));
    ui->tableWidget_food->setItem(i,1,new QTableWidgetItem(food_list[i].getName()));
    ui->tableWidget_food->setItem(i,2,new QTableWidgetItem(QString::number(food_list[i].getPrice())));

    Category_service service;
    QString category = service.getCategoty(food_list[i].getCategoryId()).getName();
    ui->tableWidget_food->setItem(i,3,new QTableWidgetItem(category));

    ui->tableWidget_food->setItem(i,4,new QTableWidgetItem(food_list[i].getIsOnSale()?"是":"否"));
    ui->tableWidget_food->setItem(i,5,new QTableWidgetItem(QString::number(food_list[i].getSaleRate())));
    QTableWidgetItem *item1 = new QTableWidgetItem;
    item1->setData(Qt::UserRole,food_list[i].getId());
    item1->setText("编辑");
    ui->tableWidget_food->setItem(i,6,item1);

 }
}
void Food_a::setCategorys(QList<Category_entity> category_list){
    ui->listWidget_category->clear();
    for(int i=0;i<category_list.size();i++){
        QListWidgetItem *item = new QListWidgetItem;

        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        item->setData(Qt::UserRole,category_list[i].getId());
        item->setText(category_list[i].getName());
        item->setSizeHint(QSize(80,20));
        ui->listWidget_category->addItem(item);
    }
}

Food_a::~Food_a()
{
    delete ui;
}



void Food_a::on_pushButton_category_clicked()
{
    CategoryDetail c;
    c.init(-1);
    c.exec();
    updateCategory();
}

void Food_a::on_pushButton_food_clicked()
{
    FoodDetail f;
    f.init(-1);
    f.exec();
    updateFood();
}


void Food_a::on_tableWidget_food_itemClicked(QTableWidgetItem *item)
{


    if(item->data(Qt::UserRole).toInt()==0) return;
    int id = item->data(Qt::UserRole).toInt();
    FoodDetail f;
    f.init(id);
    f.exec();
    updateFood();
}

void Food_a::on_listWidget_category_itemClicked(QListWidgetItem *item)
{
    if(item->data(Qt::UserRole).toInt()==0) return;
    int id = item->data(Qt::UserRole).toInt();
    CategoryDetail c;
    c.init(id);
    c.exec();
    updateCategory();
}

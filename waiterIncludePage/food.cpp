#include "food.h"
#include "ui_food.h"
#include <qmessagebox.h>
#include <qlabel.h>
#include "foodIncludePage/tablefood_list.h"
#include "service/orderfood_service.h"
#include "service/order_service.h"
#include <QByteArray>
#pragma execution_character_set("utf-8")
Food::Food(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Food)
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
    ui->listWidget_food->setStyleSheet("color:white;background:transparent;");


        //this->ui->listWidget_category->setFont(QFont("微软雅黑",11));
        ui->listWidget_category->setFlow(QListWidget::LeftToRight);
        ui->listWidget_food->setIconSize(QSize(198,198));
        ui->listWidget_food->setViewMode(QListWidget::IconMode);


        //设置分类
        Category_service category_service;
        this->category_list = category_service.getAll(Global_variable::shopId);
        setCategorys(this->category_list);
        //设置菜单
        Food_service food_service;
        this->Allfood_list = this->food_list = food_service.getAll(Global_variable::shopId);
        this->tempFood_list = this->food_list;
        setFoods(this->food_list);
        ui->listWidget_category->item(0)->setBackgroundColor(QColor("#1E8BE8"));
        //设置可点餐桌子
        Table_service table_service;
        this->table_list = table_service.getUsingTables(Global_variable::shopId);
        setTables(this->table_list);
        //设置当前桌号
        if(ui->comboBox->currentData().toInt()!=0){
            this->tableId = ui->comboBox->currentData().toInt();
            this->tableName = ui->comboBox->currentText();
        }

//        this->ui->listWidget_2->setStyleSheet(
//        "QListWidget{border:1px solid gray; color:black; }"
//        "QListWidget::Item{padding-top:20px; padding-bottom:4px; }"
//        "QListWidget::Item:hover{background:skyblue; }"
//        "QListWidget::item:selected{background:lightgray; color:red; }"
//        "QListWidget::item:selected:!active{border-width:0px; background:lightgreen; }"
//        );
}

Food::~Food()
{
    delete ui;
}

void Food::init(){
    //设置可点餐桌子
    Table_service table_service;
    this->table_list = table_service.getUsingTables(Global_variable::shopId);
    setTables(this->table_list);
    if(ui->comboBox->currentData().toInt()!=0){
        this->tableId = ui->comboBox->currentData().toInt();
    }
}
void Food::setFoods(QList<Food_entity> food_list){
    ui->listWidget_food->clear();
    for(int i = 0;i<food_list.size();i++){
    QListWidgetItem *item = new QListWidgetItem;
    QString name = food_list[i].getName();
    double price = food_list[i].getIsOnSale()?food_list[i].getSalePrice():food_list[i].getPrice();
    QString price1 = "￥"+QString::number(price);
    QString foodStr = name+" "+price1;
    if(food_list[i].getIsOnSale()){
        foodStr = foodStr+"("+QString::number(food_list[i].getSaleRate()*10)+"折）";
        item->setTextColor(QColor(220,20,60));
    }
    item->setText(foodStr);
    item->setData(Qt::UserRole,food_list[i].getId());//设置数据位99携带id（设置太小可能会覆盖settext等内容）
    QByteArray imagebyte = food_list[i].getImage();
    QIcon icon;
    QPixmap pix;
    pix.loadFromData(imagebyte,"jpg");
    icon.addPixmap(pix);
    item->setIcon(QIcon(icon));
    this->ui->listWidget_food->addItem(item);
    }
}
void Food::setCategorys(QList<Category_entity> category_list){
    QListWidgetItem *item = new QListWidgetItem;
    item->setData(1,0);//代表全部
    item->setText("全部");
    item->setSizeHint(QSize(80,20));
    ui->listWidget_category->addItem(item);
    for(int i=0;i<category_list.size();i++){
        QListWidgetItem *item = new QListWidgetItem;
        item->setData(1,category_list[i].getId());
        item->setText(category_list[i].getName());
        item->setSizeHint(QSize(80,20));
        ui->listWidget_category->addItem(item);
    }
}
void Food::setTables(QList<Table_entity> table_list){
    ui->comboBox->clear();
    for(int i=0;i<table_list.size();i++){
        ui->comboBox->addItem(table_list[i].getName(),table_list[i].getId());
    }
}
void Food::on_comboBox_activated(const QString &arg1)
{
    this->tableId = ui->comboBox->currentData().toInt();
    this->tableName = arg1;
}

void Food::on_listWidget_category_itemClicked(QListWidgetItem *item)
{   Food_service food_service;
    int categoryId = item->data(1).toInt();
    this->food_list = food_service.getCategoryFoods(categoryId);
    this->tempFood_list = this->food_list;
    this->food_list = food_service.onlyOnSale(this->food_list,this->isOnSale);
    setFoods(this->food_list);

    for(int i=0;i<ui->listWidget_category->count();i++){
        QListWidgetItem *item1 = ui->listWidget_category->item(i);
        item1->setBackgroundColor(QColor("#FFFFFF"));
        item1->setTextColor("#000000");
    }
    item->setBackgroundColor("#F5F5F5");
    item->setTextColor(QColor("#2C89FF"));
}

void Food::on_listWidget_food_itemClicked(QListWidgetItem *item)
{
    //item->setBackgroundColor(QColor("rgb(44 , 137 , 255)"));
    if(this->table_list.size()==0){
        QMessageBox::warning(this,"错误","目前无可点餐的桌子","确定");
        return;
    }
    OrderTheFood o;
    o.init(item->data(Qt::UserRole).toInt(),this->tableId);
    o.exec();
}

void Food::on_pushButton_search_clicked()
{
    QString keyword = ui->lineEdit->text();
    Food_service food_service;
    this->food_list = food_service.search(keyword);
    this->tempFood_list = this->food_list;
    this->food_list = food_service.onlyOnSale(this->food_list,this->isOnSale);
    setFoods(this->food_list);

}

void Food::on_checkBox_stateChanged(int arg1)
{

    if(arg1){
            this->isOnSale = true;
            Food_service food_service;
            setFoods(food_service.onlyOnSale(this->food_list,true));
    }else{
            this->isOnSale = false;
            setFoods(this->tempFood_list);
    }

}


void Food::on_pushButton_detail_clicked()
{
    if(this->tableId<=0) return;
    TableFood_list t;
    t.init(this->tableId);
    t.exec();
}
//双击项目事件，被单击覆盖了
//void Food::on_listWidget_food_itemDoubleClicked(QListWidgetItem *item)
//{
//        Food_service food_service;
//        Order_service order_service;
//        int tableId = item->data(99).toInt();
//        Food_entity food = food_service.getFood(tableId);
//        Order_entity order = order_service.getOrderByTableId(tableId);
//        OrderFood_entity orderFood;
//        orderFood.setFoodId(food.getId());
//        orderFood.setFoodName(food.getName());
//        orderFood.setNum(1);
//        orderFood.setPrice(food.getPrice());
//        orderFood.setTotalPrice(food.getPrice());
//        orderFood.setOrderId(order.getId());
//        OrderFood_service orderFood_service;
//        orderFood_service.addFoodToOrder(orderFood);
//}

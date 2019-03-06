#include "fooddetail.h"
#include "ui_fooddetail.h"
#include "service/food_service.h"
#include "service/category_service.h"
#include "entity/category_entity.h"
#include "global_variable.h"
#include <qlist.h>
#include <qdebug.h>
#include <qmessagebox.h>
#include <QFileDialog>
#include <qbuffer.h>
#pragma execution_character_set("utf-8")
FoodDetail::FoodDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FoodDetail)
{
    ui->setupUi(this);
    ui->label_image->setScaledContents(true);
    ui->label_image->installEventFilter(this);//安装事件过滤器

}

bool FoodDetail::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->label_image)//指定某个QLabel
    {
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                this->imagePath = QFileDialog::getOpenFileName(this,"选择菜品图片","/","Image Files(*.jpg)");
                QPixmap image(this->imagePath);
                ui->label_image->setScaledContents(true);
                ui->label_image->setPixmap(image);
                QBuffer buffer;
                buffer.open(QIODevice::ReadWrite);
                image.save(&buffer,"jpg");
                QByteArray pixArray;
                pixArray.append(buffer.data());
                this->imageByte = pixArray;
                return true;
            }
        }
    }
    return false;
}



FoodDetail::~FoodDetail()
{
    delete ui;
}

void FoodDetail::init(int id){
    Food_service service;
    Category_service service1;
    this->id = id;
    QList<Category_entity> list = service1.getAll(Global_variable::shopId);
    for(int i=0;i<list.size();i++){
        ui->comboBox->addItem(list[i].getName(),list[i].getId());
    }

    if(this->id>0){
    this->food = service.getFood(id);
    this->category = this->food.getCategoryId();
    this->imageByte = this->food.getImage();

    QPixmap pix;
    pix.loadFromData(this->food.getImage(),"jpg");
    this->ui->label_image->setPixmap(pix);
    ui->lineEdit_name->setText(this->food.getName());
    ui->doubleSpinBox_price->setValue(this->food.getPrice());
    ui->doubleSpinBox_rate->setValue(this->food.getSaleRate());
    ui->checkBox->setChecked(this->food.getIsOnSale());
    ui->comboBox->setCurrentText(service1.getCategoty(this->category).getName());

    }else{
        QPixmap image(":/file/images/food.jpg");
        this->ui->label_image->setPixmap(image);
        QBuffer buffer;
        buffer.open(QIODevice::ReadWrite);
        image.save(&buffer,"jpg");
        QByteArray pixArray;
        pixArray.append(buffer.data());
        this->imageByte = pixArray;
        //ui->label_image->setText("点击添加图片");
        ui->pushButton_delete->setEnabled(false);
        ui->pushButton_ok->setText("确认添加");
    }
}

void FoodDetail::on_pushButton_ok_clicked()
{
    Food_service service;
    Food_entity food;
    if(id>0){
    food.setCategoryId(this->category);
    food.setName(ui->lineEdit_name->text());
    food.setOnSale(ui->checkBox->isChecked());
    food.setPrice(ui->doubleSpinBox_price->value());
    food.setSaleRate(ui->doubleSpinBox_rate->value());
    food.setSalePrice(ui->doubleSpinBox_price->value()*ui->doubleSpinBox_rate->value());
    food.setImage(this->imageByte);
    food.setId(this->id);
    if(service.updateFood(food)){
        QMessageBox::information(this,"成功","修改成功","确认");
        this->close();
    }else{
        QMessageBox::warning(this,"失败","修改失败","确认");
    }
    }else{
        food.setCategoryId(ui->comboBox->currentData().toInt());
        food.setName(ui->lineEdit_name->text());
        food.setOnSale(ui->checkBox->isChecked());
        food.setPrice(ui->doubleSpinBox_price->value());
        food.setSaleRate(ui->doubleSpinBox_rate->value());
        food.setSalePrice(ui->doubleSpinBox_price->value()*ui->doubleSpinBox_rate->value());
        food.setShopId(Global_variable::shopId);
        food.setImage(this->imageByte);
        if(service.addFood(food)){
            QMessageBox::information(this,"成功","添加成功","确认");
            this->close();
        }else{
            QMessageBox::warning(this,"失败","添加失败","确认");
        }
    }
}

void FoodDetail::on_pushButton_delete_clicked()
{
    int i = QMessageBox::warning(this,"确认删除","确认删除此菜品？","确认","取消");
    if(i==0){
        Food_service service;
        if(service.deleteFood(this->id)){
            QMessageBox::information(this,"成功","删除成功","确认");
            this->close();
        }else{
            QMessageBox::warning(this,"失败","删除失败","确认");
        }
    }
}

void FoodDetail::on_comboBox_activated(int index)
{
    this->category = ui->comboBox->currentData().toInt();
    qDebug()<<"dasda"<<this->category;
}

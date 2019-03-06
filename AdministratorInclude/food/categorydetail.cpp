#include "categorydetail.h"
#include "ui_categorydetail.h"
#include <qmessagebox.h>
#include "global_variable.h"
#pragma execution_character_set("utf-8")
CategoryDetail::CategoryDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CategoryDetail)
{
    ui->setupUi(this);
}

CategoryDetail::~CategoryDetail()
{
    delete ui;
}

void CategoryDetail::init(int id){

    this->id = id;
    if(this->id>0){
    this->category = service.getCategoty(id);
    ui->lineEdit->setText(this->category.getName());
    }else{
        ui->pushButton->setText("确认新增");
        ui->pushButton_2->setEnabled(false);
    }
}

void CategoryDetail::on_pushButton_clicked()
{

    Category_entity entity;
    if(this->id>0){
    entity.setName(ui->lineEdit->text());
    entity.setId(this->id);
    if(service.updateCategory(entity)){
        QMessageBox::information(this,"成功","修改成功","确认");
        this->close();
    }else{
        QMessageBox::warning(this,"失败","修改失败","确认");
    }
    }else{
        entity.setName(ui->lineEdit->text());
        entity.setShopId(Global_variable::shopId);
        if(service.addCategory(entity)){
            QMessageBox::information(this,"成功","分类已新增","确认");
            this->close();
        }else{
            QMessageBox::warning(this,"失败","添加失败","确认");
        }
    }
}

void CategoryDetail::on_pushButton_2_clicked()
{
    if(service.deleteCategory(this->id)){
        QMessageBox::information(this,"成功","分类已删除","确认");
        this->close();
    }else{
        QMessageBox::warning(this,"失败","有食物占用此分类，删除失败","确认");
    }
}

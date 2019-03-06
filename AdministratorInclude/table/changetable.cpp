#include "changetable.h"
#include "ui_changetable.h"
#include "service/table_service.h"
#include <qmessagebox.h>
#include "global_variable.h"
#pragma execution_character_set("utf-8")
ChangeTable::ChangeTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeTable)
{
    ui->setupUi(this);
}

ChangeTable::~ChangeTable()
{
    delete ui;
}
void ChangeTable::init(int id){
     this->id = id;
     if(id==0){
         ui->pushButton->setText("确认增添");
         return;
         }
     Table_service service;
     this->table = service.getTable(id);
     ui->lineEdit->setText(this->table->getName());
     ui->lineEdit_2->setText(this->table->getDescribe());
     ui->spinBox->setValue(this->table->getSize());
}

void ChangeTable::on_pushButton_clicked()
{
    if(this->id==0){
        Table_entity t;
        t.setName(ui->lineEdit->text());
        t.setDescribe(ui->lineEdit_2->text());
        t.setSize(ui->spinBox->value());
        t.setIsFree(true);
        t.setShopId(Global_variable::shopId);
        Table_service service;
        if(service.addTable(t)){
            QMessageBox::information(this,"成功","新增成功","确认");
            this->close();
        }else{
            QMessageBox::warning(this,"失败","添加失败","确认");
        }
    }else{
    Table_entity t;
    t.setName(ui->lineEdit->text());
    t.setDescribe(ui->lineEdit_2->text());
    t.setSize(ui->spinBox->value());
    t.setId(this->table->getId());
    Table_service service;
    if(service.changeTable(t)){
        QMessageBox::information(this,"成功","修改成功","确认");
        this->close();
        delete this->table;
    }else{
        QMessageBox::warning(this,"失败","修改失败","确认");
    }
    }
}

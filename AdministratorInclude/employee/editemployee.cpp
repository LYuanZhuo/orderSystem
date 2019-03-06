#include "editemployee.h"
#include "ui_editemployee.h"
#include <qmessagebox.h>
#include <qdebug.h>
#include "global_variable.h"
#pragma execution_character_set("utf-8")
EditEmployee::EditEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditEmployee)
{
    ui->setupUi(this);
}

EditEmployee::~EditEmployee()
{
    delete ui;
}

void EditEmployee::init(int id,int type){

    this->id = id;
    this->type = type;

    if(this->id>0){//编辑

    if(type == 1){
    this->user = service.getUser_w(id);
    }else if(type==2){
    this->user = service.getUser_k(id);
    }

    ui->lineEdit_name->setText(user.getName());
    ui->lineEdit_account->setText(user.getAccount());
    ui->lineEdit_password->setText(user.getPassword());
    }
    else{//增加
        ui->pushButton->setText("确认添加");
    }
}

void EditEmployee::on_pushButton_clicked()
{
    if(this->id>0){//编辑
    User_entity u;
    u.setName(ui->lineEdit_name->text());
    u.setAccount(ui->lineEdit_account->text());
    u.setPassword(ui->lineEdit_password->text());
    u.setId(this->id);
    if(type==1){
        if(this->service.updateUser_w(u)){
             QMessageBox::information(this,"成功","修改成功","确认");
             this->close();
        }else{
             QMessageBox::warning(this,"失败","修改失败","确认");
        }

    }else if(type==2){
        if(this->service.updateUser_k(u)){
              QMessageBox::information(this,"成功","修改成功","确认");
              this->close();
        }else{
              QMessageBox::warning(this,"失败","修改失败","确认");
        }
    }
    }else{//增加
        User_entity u;
        u.setName(ui->lineEdit_name->text());
        u.setAccount(ui->lineEdit_account->text());
        u.setPassword(ui->lineEdit_password->text());
        u.setShopId(Global_variable::shopId);
        if(type==1){
            if(this->service.addUser_w(u)){
                 QMessageBox::information(this,"成功","已添加新员工","确认");
                 this->close();
            }else{
                 QMessageBox::warning(this,"失败","添加失败","确认");
            }

        }else if(type==2){
            if(this->service.addUser_k(u)){
                  QMessageBox::information(this,"成功","已添加","确认");
                  this->close();
            }else{
                  QMessageBox::warning(this,"失败","添加失败","确认");
            }
        }
    }
}

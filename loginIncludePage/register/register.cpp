#include "register.h"
#include "ui_register.h"
#include "entity/user_entity.h"
#include "service/user_service.h"
#include <qmessagebox.h>
#pragma execution_character_set("utf-8")
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_password1->setEchoMode(QLineEdit::Password);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    User_entity user;
    QString p = ui->lineEdit_password->text();
    QString p1 = ui->lineEdit_password1->text();
    if(QString::compare(p,p1)!=0){
        QMessageBox::warning(this,"错误","两次密码不一致","确认");
        return;
    }
    user.setName(ui->lineEdit_name->text());
    user.setAccount(ui->lineEdit_account->text());
    user.setPassword(ui->lineEdit_password->text());
    User_service service;
    if(service.addShop(user)){
        QMessageBox::information(this,"成功","注册成功","确认");
        this->close();
    }else{
        QMessageBox::warning(this,"失败","账号已被注册","确认");
    }
}

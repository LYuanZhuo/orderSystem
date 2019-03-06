#include "mainlogin.h"
#include "ui_mainlogin.h"
#include "QMessageBox"
#include <QTime>
#include "global_variable.h"
#include <QDebug>
#include "register/register.h"
#pragma execution_character_set("utf-8")
MainLogin::MainLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainLogin)
{

    ui->setupUi(this);

    ui->label->setScaledContents(true);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    setWindowTitle("欢迎登陆");
    int loginType = Global_variable::loginType;
    if(loginType==1){
        ui->label_image->setText("服务员登陆");
    }else if(loginType==2){
        ui->label_image->setText("厨房登陆");
    }else{
        ui->label_image->setText("管理员登陆");
    }

}

MainLogin::~MainLogin()
{
    delete ui;
}
void MainLogin::showMainWindow(){
    emit loginSignalShowMainWindow();
}
void MainLogin::on_pushButton_clicked()
{

    if(Global_variable::query==NULL){
        QMessageBox::warning(this,"无法连接服务器","服务器异常！请检查你的网络是否已正常连接！","确定");
        return;
    }
    QString account = this->ui->lineEdit_account->text();
    QString password = this->ui->lineEdit_password->text();

    User_service service;
    User_entity *user = service.getUser(account,password);
    if(user==NULL){
                QMessageBox::warning(this,"登陆失败！","账号或密码错误！","确定");
    }else{
    //设置全局变量
    Global_variable::user = user;
    Global_variable::shopId = user->getShopId();
    emit loginWait();//发信号页面转到等待中的子页面
    //延时进行，避免loginWait的信号不能先进行
    QTime t;
    t.start();
    while(t.elapsed()<1){
        QCoreApplication::processEvents();
    }

    int loginType = Global_variable::loginType;
    if(loginType==1){
         waiterLogin();
    }else if(loginType==2){
         kitchenLogin();
    }else{
         administratorLogin();
    }
    emit loginSignalCloseMainWindow();//关闭主窗口
    emit closeWindow();//关闭大登陆窗口
    }

}

void MainLogin::waiterLogin(){
    this->waiter = new Waiter;
    waiter->init();//初始化waiter
    connect(this->waiter,SIGNAL(waiterSignalShowMainWindow()),this,SLOT(showMainWindow()));
    this->waiter->show();

}
void MainLogin::kitchenLogin(){

    this->kitchen = new Kitchen;
    connect(this->kitchen,SIGNAL(signalShowMainWindow()),this,SLOT(showMainWindow()));
    this->kitchen->show();

}
void MainLogin::administratorLogin(){
    this->administrator = new Administrator;
    connect(this->administrator,SIGNAL(signalShowMainWindow()),this,SLOT(showMainWindow()));
    this->administrator->show();
}



void MainLogin::on_pushButton_register_clicked()
{
    Register r;
    r.exec();
}

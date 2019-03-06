#include "login.h"
#include "ui_login.h"
#include <QDebug>
#pragma execution_character_set("utf-8")

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->mainLogin = new MainLogin;
    this->tip = new Tip;

    connect(mainLogin,SIGNAL(loginSignalCloseMainWindow()),this,SLOT(closeMainWindow()));
    connect(mainLogin,SIGNAL(loginSignalShowMainWindow()),this,SLOT(showMainWindow()));
    connect(mainLogin,SIGNAL(closeWindow()),this,SLOT(closeWindow()));
    connect(mainLogin,SIGNAL(loginWait()),this,SLOT(loginWait()));
    ui->stackedWidget->addWidget(mainLogin);
    ui->stackedWidget->addWidget(tip);
    ui->stackedWidget->setCurrentWidget(mainLogin);

}

login::~login()
{
    delete ui;
}

void login::closeMainWindow(){
    emit loginSignalCloseMainWindow();
}
void login::showMainWindow(){
    emit loginSignalShowMainWindow();
}
void login::closeWindow(){
    this->close();
}
void login::loginWait(){

    ui->stackedWidget->setCurrentWidget(this->tip);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "login.h"
#include "global_variable.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeMainWindow(){
    this->close();
}
void MainWindow::showMainWindow(){
    this->show();
}

void MainWindow::on_pushButton_waiter_clicked()
{

    Global_variable::loginType=1;
    this->l = new login;
    connect(this->l,SIGNAL(loginSignalCloseMainWindow()),this,SLOT(closeMainWindow()));
    connect(this->l,SIGNAL(loginSignalShowMainWindow()),this,SLOT(showMainWindow()));
    this->l->exec();
}

void MainWindow::on_pushButton_kitchen_clicked()
{

    Global_variable::loginType=2;
    this->l = new login;
    connect(this->l,SIGNAL(loginSignalCloseMainWindow()),this,SLOT(closeMainWindow()));
    connect(this->l,SIGNAL(loginSignalShowMainWindow()),this,SLOT(showMainWindow()));
    this->l->exec();
}

void MainWindow::on_pushButton_manager_clicked()
{

    Global_variable::loginType=3;
    this->l = new login;
    connect(this->l,SIGNAL(loginSignalCloseMainWindow()),this,SLOT(closeMainWindow()));
    connect(this->l,SIGNAL(loginSignalShowMainWindow()),this,SLOT(showMainWindow()));
    this->l->exec();
}

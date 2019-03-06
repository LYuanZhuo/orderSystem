#include "editorder.h"
#include "ui_editorder.h"
#include "global_variable.h"
#include "qmessagebox.h"
#pragma execution_character_set("utf-8")
EditOrder::EditOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditOrder)
{
    ui->setupUi(this);
}

EditOrder::~EditOrder()
{
    delete ui;
}
void EditOrder::init(int id){
    this->id = id;
    this->order = order_service.getOrder(this->id);
    this->tableId = this->order.getTableId();
    this->list = table_service.getAllTables(Global_variable::shopId);
    ui->checkBox->setChecked(this->order.getIsPay());
    ui->doubleSpinBox->setValue(this->order.getPrice());
    ui->spinBox->setValue(this->order.getPersonNum());
    setTables();
}

void EditOrder::setTables(){
    for(int i=0;i<this->list.size();i++){
        ui->comboBox->addItem(list[i].getName(),list[i].getId());
    }
    ui->comboBox->setCurrentText(this->order.getTableName());
}

void EditOrder::on_comboBox_activated(const QString &arg1)
{
    this->tableId = ui->comboBox->currentData().toInt();
}

void EditOrder::on_pushButton_clicked()
{
    Order_entity entity;
    entity.setIsPay(ui->checkBox->isChecked());
    entity.setPersonNum(ui->spinBox->value());
    entity.setPrice(ui->doubleSpinBox->value());
    entity.setTableName(ui->comboBox->currentText());
    entity.setTableId(this->tableId);
    entity.setId(this->order.getId());
    if(order_service.updateOrder(entity)){
        QMessageBox::information(this,"成功","订单已修改","确认");
        this->close();
    }else{
        QMessageBox::warning(this,"失败","修改失败","确认");
    }
}

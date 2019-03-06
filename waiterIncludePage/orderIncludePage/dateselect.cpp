#include "dateselect.h"
#include "ui_dateselect.h"
#include "QDebug"
DateSelect::DateSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateSelect)
{
    ui->setupUi(this);
}

DateSelect::~DateSelect()
{
    delete ui;
}

void DateSelect::on_calendarWidget_clicked(const QDate &date)
{
    QString d = date.toString("yyyy-MM-dd");
    emit signalDate(d);
    this->close();
}

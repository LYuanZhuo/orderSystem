#ifndef TABLE_A_H
#define TABLE_A_H

#include <QWidget>
#include <QList>
#include <QTableWidgetItem>
#include <entity/table_entity.h>
namespace Ui {
class Table_a;
}

class Table_a : public QWidget
{
    Q_OBJECT

public:
    explicit Table_a(QWidget *parent = 0);
    ~Table_a();

private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);
    void init();

    void on_pushButton_clicked();

private:
    Ui::Table_a *ui;
    QList<Table_entity> table_list;//当前展示的所有桌子
    void setTableList();

};

#endif // TABLE_A_H

#ifndef FOOD_H
#define FOOD_H
#include <QString>
#include <QDebug>
#include "foodIncludePage/orderthefood.h"
#include "entity/food_entity.h"
#include "entity/category_entity.h"
#include "entity/table_entity.h"
#include "service/category_service.h"
#include "service/food_service.h"
#include "global_variable.h"
#include "service/table_service.h"
#include <QDialog>
#include <QListWidgetItem>
namespace Ui {
class Food;
}

class Food : public QDialog
{
    Q_OBJECT

public:
    explicit Food(QWidget *parent = 0);
    ~Food();


private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_search_clicked();

    void on_listWidget_category_itemClicked(QListWidgetItem *item);

    void on_listWidget_food_itemClicked(QListWidgetItem *item);

    void on_checkBox_stateChanged(int arg1);

    void init();

    void on_pushButton_detail_clicked();

    //void on_listWidget_food_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::Food *ui;
    int tableId = -1;
    QString tableName="";
    QList<Food_entity> Allfood_list;
    QList<Food_entity> food_list;//要展示的食物列表
    QList<Food_entity> tempFood_list;
    bool isOnSale = false;
    void setFoods(QList<Food_entity> food_list);
    QList<Category_entity> category_list;
    void setCategorys(QList<Category_entity> category_list);
    QList<Table_entity> table_list;
    void setTables(QList<Table_entity> table_list);

};

#endif // FOOD_H

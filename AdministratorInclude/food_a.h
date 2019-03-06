#ifndef FOOD_A_H
#define FOOD_A_H

#include <QWidget>
#include "entity/food_entity.h"
#include "entity/category_entity.h"
#include <QTableWidgetItem>
#include <QListWidgetItem>
namespace Ui {
class Food_a;
}

class Food_a : public QWidget
{
    Q_OBJECT

public:
    explicit Food_a(QWidget *parent = 0);
    ~Food_a();

private slots:

    void init();
    void updateFood();
    void updateCategory();
    void on_pushButton_category_clicked();
    void on_pushButton_food_clicked();
    void on_tableWidget_food_itemClicked(QTableWidgetItem *item);
    void on_listWidget_category_itemClicked(QListWidgetItem *item);

private:
    Ui::Food_a *ui;

    QList<Food_entity> food_list;//要展示的食物列表
    void setFoods(QList<Food_entity> food_list);
    QList<Category_entity> category_list;
    void setCategorys(QList<Category_entity> category_list);


};

#endif // FOOD_A_H

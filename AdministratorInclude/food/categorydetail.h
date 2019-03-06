#ifndef CATEGORYDETAIL_H
#define CATEGORYDETAIL_H

#include <QDialog>
#include "entity/category_entity.h"
#include "service/category_service.h"
namespace Ui {
class CategoryDetail;
}

class CategoryDetail : public QDialog
{
    Q_OBJECT

public:
    explicit CategoryDetail(QWidget *parent = 0);
    ~CategoryDetail();
    void init(int id);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CategoryDetail *ui;
    Category_service service;
    int id;
    Category_entity category;
};

#endif // CATEGORYDETAIL_H

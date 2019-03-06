#-------------------------------------------------
#
# Project created by QtCreator 2018-11-13T15:28:41
#
#-------------------------------------------------

QT       += core gui
QT      += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = orderSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    waiterIncludePage/table.cpp \
    waiterIncludePage/tableIncludePage/table_usethistable.cpp \
    waiterIncludePage/order.cpp \
    waiterIncludePage/orderIncludePage/orderdetail.cpp \
    waiterIncludePage/foodIncludePage/orderthefood.cpp \
    entity/food_entity.cpp \
    waiter.cpp \
    entity/order_entity.cpp \
    entity/table_entity.cpp \
    util/databaseconnect.cpp \
    dao/user_waiter_dao.cpp \
    entity/user_entity.cpp \
    loginIncludePage/tip.cpp \
    loginIncludePage/mainlogin.cpp \
    dao/shop_dao.cpp \
    service/shop_service.cpp \
    service/user_service.cpp \
    global_variable.cpp \
    dao/table_dao.cpp \
    dao/food_dao.cpp \
    service/table_service.cpp \
    service/food_service.cpp \
    util/randomnum.cpp \
    dao/order_dao.cpp \
    service/order_service.cpp \
    entity/category_entity.cpp \
    dao/category_dao.cpp \
    service/category_service.cpp \
    waiterIncludePage/orderIncludePage/dateselect.cpp \
    entity/orderfood_entity.cpp \
    dao/orderfood_dao.cpp \
    service/orderfood_service.cpp \
    waiterIncludePage/foodIncludePage/tablefood_list.cpp \
    kitchen.cpp \
    dao/foodneed_dao.cpp \
    service/foodneed_service.cpp \
    entity/foodneed_entity.cpp \
    dao/user_kitchen_dao.cpp \
    administrator.cpp \
    AdministratorInclude/employee.cpp \
    AdministratorInclude/canteen.cpp \
    AdministratorInclude/table/changetable.cpp \
    entity/shop_entity.cpp \
    waiterIncludePage/food.cpp \
    AdministratorInclude/table_a.cpp \
    AdministratorInclude/order_a.cpp \
    AdministratorInclude/food_a.cpp \
    AdministratorInclude/food/fooddetail.cpp \
    AdministratorInclude/food/categorydetail.cpp \
    AdministratorInclude/order/editorder.cpp \
    entity/sales_entity.cpp \
    AdministratorInclude/employee/editemployee.cpp \
    service/statistics_service.cpp \
    loginIncludePage/register/register.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    waiterIncludePage/table.h \
    waiterIncludePage/tableIncludePage/table_usethistable.h \
    waiterIncludePage/order.h \
    waiterIncludePage/orderIncludePage/orderdetail.h \
    waiterIncludePage/foodIncludePage/orderthefood.h \
    entity/food_entity.h \
    waiter.h \
    entity/order_entity.h \
    entity/table_entity.h \
    util/databaseconnect.h \
    dao/user_waiter_dao.h \
    entity/user_entity.h \
    loginIncludePage/tip.h \
    loginIncludePage/mainlogin.h \
    dao/shop_dao.h \
    service/shop_service.h \
    service/user_service.h \
    global_variable.h \
    dao/table_dao.h \
    dao/food_dao.h \
    service/table_service.h \
    service/food_service.h \
    util/randomnum.h \
    dao/order_dao.h \
    service/order_service.h \
    entity/category_entity.h \
    dao/category_dao.h \
    service/category_service.h \
    waiterIncludePage/orderIncludePage/dateselect.h \
    entity/orderfood_entity.h \
    dao/orderfood_dao.h \
    service/orderfood_service.h \
    waiterIncludePage/foodIncludePage/tablefood_list.h \
    kitchen.h \
    dao/foodneed_dao.h \
    service/foodneed_service.h \
    entity/foodneed_entity.h \
    dao/user_kitchen_dao.h \
    administrator.h \
    AdministratorInclude/employee.h \
    AdministratorInclude/canteen.h \
    AdministratorInclude/table/changetable.h \
    entity/shop_entity.h \
    waiterIncludePage/food.h \
    AdministratorInclude/table_a.h \
    AdministratorInclude/order_a.h \
    AdministratorInclude/food_a.h \
    AdministratorInclude/food/fooddetail.h \
    AdministratorInclude/food/categorydetail.h \
    AdministratorInclude/order/editorder.h \
    entity/sales_entity.h \
    AdministratorInclude/employee/editemployee.h \
    service/statistics_service.h \
    loginIncludePage/register/register.h

FORMS += \
        mainwindow.ui \
    login.ui \
    waiterIncludePage/table.ui \
    waiterIncludePage/tableIncludePage/table_usethistable.ui \
    waiterIncludePage/food.ui \
    waiterIncludePage/order.ui \
    waiterIncludePage/orderIncludePage/orderdetail.ui \
    waiterIncludePage/foodIncludePage/orderthefood.ui \
    waiter.ui \
    loginIncludePage/tip.ui \
    loginIncludePage/mainlogin.ui \
    waiterIncludePage/orderIncludePage/dateselect.ui \
    waiterIncludePage/foodIncludePage/tablefood_list.ui \
    kitchen.ui \
    administrator.ui \
    AdministratorInclude/employee.ui \
    AdministratorInclude/canteen.ui \
    AdministratorInclude/table/changetable.ui \
    AdministratorInclude/table_a.ui \
    AdministratorInclude/order_a.ui \
    AdministratorInclude/food_a.ui \
    AdministratorInclude/food/fooddetail.ui \
    AdministratorInclude/food/categorydetail.ui \
    AdministratorInclude/order/editorder.ui \
    AdministratorInclude/employee/editemployee.ui \
    loginIncludePage/register/register.ui

RESOURCES += \
    file.qrc

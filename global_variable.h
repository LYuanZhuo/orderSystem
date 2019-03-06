#ifndef GLOBAL_VARIABLE_H
#define GLOBAL_VARIABLE_H
#include "entity/user_entity.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
class Global_variable
{
public:
    Global_variable();

    static int loginType;//登陆类型
    static User_entity *user;//用户对象
    static QSqlQuery* query;//数据库连接对象指针
    static int shopId;//商店id号
};

#endif // GLOBAL_VARIABLE_H

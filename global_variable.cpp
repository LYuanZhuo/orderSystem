#include "global_variable.h"

Global_variable::Global_variable()
{

}
int Global_variable::loginType = 1;//服务员登陆
User_entity* Global_variable::user = NULL;
QSqlQuery* Global_variable::query = NULL;
int Global_variable::shopId = 0;

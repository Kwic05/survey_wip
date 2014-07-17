#include "querycontainer.h"

QueryContainer::QueryContainer(QObject *parent) :
    QObject(parent)
{
}

void QueryContainer::initialize()
{
    query.exec("create table zxc (id int primary key, "
                  "FIO varchar(20), pol varchar(20), dr varchar(20), kurenie varchar(20))");
}

void QueryContainer::executeSelect()
{
    query.exec("select * from zxc order by id");
}

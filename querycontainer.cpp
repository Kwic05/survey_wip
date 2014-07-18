#include "querycontainer.h"

QueryContainer::QueryContainer(QObject *parent) :
    QObject(parent)
{
}

void QueryContainer::initialize()
{
    query.exec("create table zxc (id int primary key, "
                  "FIO varchar(20), pol varchar(20), dr varchar(20), kurenie varchar(20), id2 int)");
    query2.exec("create table asd (mark varchar(20), "
                " id2 int primary key,kol int, nikotin int)");
}

void QueryContainer::executeSelect()
{
    query.exec("select * from zxc order by id");
    query2.exec("select * from asd order by id2");
}

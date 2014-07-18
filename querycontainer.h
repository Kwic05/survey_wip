#ifndef QUERYCONTAINER_H
#define QUERYCONTAINER_H

#include <QObject>

#include <QSqlQuery>

class QueryContainer : public QObject
{
    Q_OBJECT
public:
    explicit QueryContainer(QObject *parent = 0);

    void initialize();

    void executeSelect();

    QSqlQuery query,query2;
};

#endif // QUERYCONTAINER_H

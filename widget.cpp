#include "widget.h"
#include "ui_widget.h"
#include "dlg1.h"
#include "dlg2.h"
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QSqlDatabase d = QSqlDatabase::addDatabase("QSQLITE");
    d.setDatabaseName("survey.db");

    QSqlQuery query;
    query.exec("create table srv (id int primary key, "
               "FIO varchar(20), pol varchar(20), dr varchar(20), kurenie varchar(20))");
    query.exec("insert into person values(1, 'DIO', 'м', 233, нет)");
    query.exec("insert into person values(2, 'XYZ', 'ж', 221, да)");
    query.exec("insert into person values(3, 'QWE', 'м', 231, нет)");
    query.exec("insert into person values(4, 'RTY', 'м', 241, да)");
    query.exec("insert into person values(5, 'ZXC', 'ж', 215, да)");


    QSqlRecord rec     = query.record();
  //  int        nNumber = 0;
    QString    strfio;
    QString    strpol;
    QString    strdr;
    QString    strkur;

    while (query.next()) {
        //nNumber = query.value(rec.indexOf("id")).toInt();
        strfio  = query.value(rec.indexOf("FIO")).toInt();
        strpol  = query.value(rec.indexOf("pol")).toInt();
        strdr   = query.value(rec.indexOf("dr")).toInt();
        strkur  = query.value(rec.indexOf("kurenie")).toInt();
    }

dlg1 f1;
f1.setMessage("123");
f1.exec();
}

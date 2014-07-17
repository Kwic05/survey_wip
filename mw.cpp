#include <QDebug>

#include "mw.h"
#include "ui_mw.h"
#include "data.h"
#include "dlg1.h"
#include "dlg2.h"
#include "dlg4.h"
#include <QObject>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>


mw::mw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mw)
{
    ui->setupUi(this);
}

mw::~mw()
{
    delete ui;
}

int mw::on_pushButton_clicked()
{

    dlg1 f1;
    f1.setQueryContainer(qc_);
    f1.initializate();
    f1.exec();
    return true;
}
void mw::on_pushButton_2_clicked()
{
    dlg2 f2;
    f2.setQueryContainer(qc_);
    f2.initializate();
    f2.exec();
}


void mw::on_pushButton_3_clicked()
{
    dlg4 dlg44;
    dlg44.exec();
    int nNumber2=0;
    qDebug()<<nNumber2;
    qc_->executeSelect();
    if (qc_->query.last()) {
        QSqlRecord rec3  = qc_->query.record();
        nNumber2 = nNumber2 + qc_->query.value(rec3.indexOf("id")).toInt();
    }
    qDebug()<<nNumber2 ;
    nNumber2 = nNumber2 + 1;
    qDebug()<<nNumber2;
           QSqlRecord rec2  = dlg44.qs_.record();
    if (dlg44.qs_.first()) {
 

    QString z = "INSERT INTO zxc(id, FIO, pol, dr, kurenie)"
                  "VALUES('%1', '%2', '%3', '%4', '%5');";
    QString x;
    x = z.arg(nNumber2)
         .arg(dlg44.qs_.value(rec2.indexOf("FIO")).toString())
         .arg(dlg44.qs_.value(rec2.indexOf("pol")).toString())
         .arg(dlg44.qs_.value(rec2.indexOf("dr")).toString())
         .arg(dlg44.qs_.value(rec2.indexOf("kurenie")).toString());
    qDebug()<<x<<"2asdasa";

    if (!qc_->query.exec(x)) {qDebug()<<dlg44.qs_.lastError().text();}
                    }


while (dlg44.qs_.next())
    {
    nNumber2 = nNumber2 + 1;
    QString z = "INSERT INTO zxc(id, FIO, pol, dr, kurenie)"
                 "VALUES('%1', '%2', '%3', '%4', '%5');";
    QString x;
    x = z.arg(nNumber2)
         .arg(dlg44.qs_.value(rec2.indexOf("FIO")).toString())
         .arg(dlg44.qs_.value(rec2.indexOf("pol")).toString())
         .arg(dlg44.qs_.value(rec2.indexOf("dr")).toString())
         .arg(dlg44.qs_.value(rec2.indexOf("kurenie")).toString());
    qDebug()<<x;

    if (!qc_->query.exec(x)) {qDebug()<<dlg44.qs_.lastError().text();}

    }
}

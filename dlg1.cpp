#include <QDebug>

#include "dlg1.h"
#include "ui_dlg1.h"
#include <QObject>
#include <QSqlRecord>
#include <QSqlError>
#include "dlg4.h"
#include <QSqlQueryModel>

dlg1::dlg1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg1)
{
    ui->setupUi(this);
}

dlg1::~dlg1()
{
    delete ui;
}

void dlg1::setMessage(const QString &str1, const QString &str2, const QString &str3, const QString &kur, const QString &id2)
{
        ui->lineEdit_4->setText(str1);
        ui->lineEdit_5->setText(str2);
        ui->lineEdit_6->setText(str3);



        QSqlQueryModel *mdl = new QSqlQueryModel;


        QString z = "SELECT mark FROM asd WHERE id2 = '%1'";
        QString x;
        x = z.arg(id2);
        if (!qc_->query2.exec(x)) {}
        mdl->setQuery(qc_->query2);
        ui->comboBox->setModel(mdl);

        if (kur.contains("y")) {ui->radioButton_4->toggle();}
        else ui->radioButton_3->toggle();



 }
void dlg1::initializate()
{
    qc_->executeSelect();



    if (qc_->query.next()) {
        QSqlRecord rec  = qc_->query.record();

        QString strfio  = qc_->query.value(rec.indexOf("FIO")).toString(),
        strpol  = qc_->query.value(rec.indexOf("pol")).toString(),
        strdr   = qc_->query.value(rec.indexOf("dr")).toString(),
        strkur  = qc_->query.value(rec.indexOf("kurenie")).toString(),
        strid2  = qc_->query.value(rec.indexOf("id2")).toString();

        setMessage(strfio, strpol, strdr, strkur, strid2);;

    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(qc_->query2);
    ui->comboBox->setModel(model);

}

void dlg1::on_pushButton_7_clicked()
{
    if (qc_->query.next()) {
        QSqlRecord rec  = qc_->query.record();

        QString strfio  = qc_->query.value(rec.indexOf("FIO")).toString(),
        strpol  = qc_->query.value(rec.indexOf("pol")).toString(),
        strdr   = qc_->query.value(rec.indexOf("dr")).toString(),
        strkur  = qc_->query.value(rec.indexOf("kurenie")).toString(),
        strid2  = qc_->query.value(rec.indexOf("id2")).toString();
        setMessage(strfio, strpol, strdr, strkur, strid2);
    }
    else
    {
        if (qc_->query.last()) {
            QSqlRecord rec  = qc_->query.record();

            QString strfio  = qc_->query.value(rec.indexOf("FIO")).toString(),
            strpol  = qc_->query.value(rec.indexOf("pol")).toString(),
            strdr   = qc_->query.value(rec.indexOf("dr")).toString(),
            strkur  = qc_->query.value(rec.indexOf("kurenie")).toString(),
            strid2  = qc_->query.value(rec.indexOf("id2")).toString();
            setMessage(strfio, strpol, strdr, strkur, strid2);
        }
    }

}

void dlg1::on_pushButton_6_clicked()
{
    if (qc_->query.previous()) {
        QSqlRecord rec  = qc_->query.record();

        QString strfio  = qc_->query.value(rec.indexOf("FIO")).toString(),
        strpol  = qc_->query.value(rec.indexOf("pol")).toString(),
        strdr   = qc_->query.value(rec.indexOf("dr")).toString(),
        strkur  = qc_->query.value(rec.indexOf("kurenie")).toString(),
        strid2  = qc_->query.value(rec.indexOf("id2")).toString();
        setMessage(strfio, strpol, strdr, strkur, strid2);
    }
    else
    {
    if (qc_->query.first()) {
            QSqlRecord rec  = qc_->query.record();

            QString strfio  = qc_->query.value(rec.indexOf("FIO")).toString(),
            strpol  = qc_->query.value(rec.indexOf("pol")).toString(),
            strdr   = qc_->query.value(rec.indexOf("dr")).toString(),
            strkur  = qc_->query.value(rec.indexOf("kurenie")).toString(),
            strid2  = qc_->query.value(rec.indexOf("id2")).toString();
            setMessage(strfio, strpol, strdr, strkur, strid2);
        }
    }
}

void dlg1::on_pushButton_5_clicked()
{
    if (qc_->query.first()) {
        QSqlRecord rec  = qc_->query.record();

        QString strfio  = qc_->query.value(rec.indexOf("FIO")).toString(),
        strpol  = qc_->query.value(rec.indexOf("pol")).toString(),
        strdr   = qc_->query.value(rec.indexOf("dr")).toString(),
        strkur  = qc_->query.value(rec.indexOf("kurenie")).toString(),
        strid2  = qc_->query.value(rec.indexOf("id2")).toString();
        setMessage(strfio, strpol, strdr, strkur, strid2);
    }
}

void dlg1::on_pushButton_8_clicked()
{
    if (qc_->query.last()) {
        QSqlRecord rec  = qc_->query.record();

        QString strfio  = qc_->query.value(rec.indexOf("FIO")).toString(),
        strpol  = qc_->query.value(rec.indexOf("pol")).toString(),
        strdr   = qc_->query.value(rec.indexOf("dr")).toString(),
        strkur  = qc_->query.value(rec.indexOf("kurenie")).toString(),
        strid2  = qc_->query.value(rec.indexOf("id2")).toString();
        setMessage(strfio, strpol, strdr, strkur, strid2);
    }
}

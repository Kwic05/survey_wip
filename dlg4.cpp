#include "dlg4.h"
#include "ui_dlg4.h"
#include <QFileDialog>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>

dlg4::dlg4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg4)
{
    ui->setupUi(this);
}

dlg4::~dlg4()
{
    delete ui;
}

void dlg4::on_pushButton_clicked()
{
    QFileDialog dg;
    dg.setFileMode(QFileDialog::ExistingFile);
    QStringList Qs;
    if(dg.exec() != QDialog::Accepted) {
        return;
    }
    Qs  = dg.selectedFiles();
    myString = Qs.at(0);
    ui->lineEdit->setText(myString);
    QSqlDatabase db = QSqlDatabase::addDatabase ("QSQLITE","connection2") ;
    db.setDatabaseName(ui->lineEdit->text());
    if (!db.open()){qDebug()<<"222";}
    QSqlQuery* qs_ = new QSqlQuery(db);
    qDebug()<<qs_->lastError().text();
    qs_->exec("select * from zxc");

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qs_);
    ui->tableView->setModel(model);
}

void dlg4::on_pushButton_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase ("QSQLITE","connection2") ;
    db.setDatabaseName(ui->lineEdit->text());
    if (!db.open()){qDebug()<<"222";}
    QSqlQuery* qs_ = new QSqlQuery(db);
    qDebug()<<qs_->lastError().text();
    qs_->exec("select * from zxc");
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
           QSqlRecord rec2  = qs_->record();
    if (qs_->first()) {


    QString z = "INSERT INTO zxc(id, FIO, pol, dr, kurenie)"
                  "VALUES('%1', '%2', '%3', '%4', '%5');";
    QString x;
    x = z.arg(nNumber2)
         .arg(qs_->value(rec2.indexOf("FIO")).toString())
         .arg(qs_->value(rec2.indexOf("pol")).toString())
         .arg(qs_->value(rec2.indexOf("dr")).toString())
         .arg(qs_->value(rec2.indexOf("kurenie")).toString());
    qDebug()<<x<<"2asdasa";

    if (!qc_->query.exec(x)) {qDebug()<<qs_->lastError().text();}
                    }


while (qs_->next())
    {
    nNumber2 = nNumber2 + 1;
    QString z = "INSERT INTO zxc(id, FIO, pol, dr, kurenie)"
                 "VALUES('%1', '%2', '%3', '%4', '%5');";
    QString x;
    x = z.arg(nNumber2)
         .arg(qs_->value(rec2.indexOf("FIO")).toString())
         .arg(qs_->value(rec2.indexOf("pol")).toString())
         .arg(qs_->value(rec2.indexOf("dr")).toString())
         .arg(qs_->value(rec2.indexOf("kurenie")).toString());
    qDebug()<<x;

    if (!qc_->query.exec(x)) {qDebug()<<qs_->lastError().text();}

    }
}

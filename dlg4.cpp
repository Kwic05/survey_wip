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
    QSqlDatabase db = QSqlDatabase::addDatabase ("QSQLITE","connection3") ;
    db.setDatabaseName(ui->lineEdit->text());
    if (!db.open()){qDebug()<<"222";}
    QSqlQuery* qs_ = new QSqlQuery(db);
    qDebug()<<qs_->lastError().text();
    qs_->exec("create table zxc (id int primary key, "
                  "FIO varchar(20), pol varchar(20), dr varchar(20), kurenie varchar(20), id2 int, id3 int)");
    qs_->exec("select * from zxc");
    qs_->exec("UPDATE asd SET id3 = '0'");
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

           //итератор
           int nNumber22=0;
           qDebug()<<nNumber22;
           qc_->executeSelect();
           if (qc_->query2.last()) {
               QSqlRecord rec3_imp  = qc_->query2.record();
               nNumber22 = nNumber22 + qc_->query2.value(rec3_imp.indexOf("id2")).toInt();
           }
           qDebug()<<nNumber22;
           nNumber22 = nNumber22 + 1;
           qDebug()<<nNumber22;


    QSqlQuery* qm_ = new QSqlQuery(db);

    qm_->exec("create table asd (mark varchar(20), id2 int primary key, "
               "kol int), nikotin int, id3 int)");
    qm_->exec("select * from asd");
    qm_->exec("UPDATE asd SET id3 = '0'");

    QSqlRecord rec_imp = qm_->record();
           while (qm_->next()) {
                        qDebug()<<"qm->";

                QString strmark_imp  = qm_->value(rec_imp.indexOf("mark")).toString(),
                        strid2_imp  = qm_->value(rec_imp.indexOf("id2")).toString();

                while (qc_->query2.next()) {
                     qDebug()<<"qm_-> qc_->";
                    QSqlRecord rec  = qc_->query2.record();

                    QString strmark  = qc_->query2.value(rec.indexOf("mark")).toString(),
                            strid2  = qc_->query2.value(rec.indexOf("id2")).toString();

                    if (strmark_imp == strmark) {
                          qDebug()<<"if1";
                        QString e = "UPDATE asd"
                                "SET id3 = '%1'"
                                "WHERE id2 = '%2'";

                        QString f = "UPDATE zxc"
                                "SET id3 = '%1'"
                                "WHERE id2 = '%2'";

                        QString w;
                        w = e.arg(strid2)
                             .arg(strid2_imp);

                        QString l;
                        l = f.arg(strid2)
                             .arg(strid2_imp);

                        if (!qm_->exec(w)) {}
                        if (!qs_->exec(l)) {}
                    }
                    else
                    {
                         qDebug()<<"if2";
                        QString e = "UPDATE asd"
                                "SET id3 = '%1'"
                                "WHERE id2 = '%2'";
                        QString w;
                        w = e.arg(nNumber22)
                             .arg(strid2_imp);
                        if (!qm_->exec(w)) {}

                        QString f = "UPDATE zxc"
                                "SET id3 = '%1'"
                                "WHERE id2 = '%2'";
                        QString l;
                        l = f.arg(nNumber22)
                             .arg(strid2_imp);
                        if (!qm_->exec(l)) {}
                        nNumber22++;


                    }
                }
            }










    if (qm_->first()) {

        QString z = "INSERT INTO asd(mark, id2, kol, nikotin)"
                      "VALUES('%1', '%2', '%3', '%4');";
        QString x;
        x = z.arg(qm_->value(rec_imp.indexOf("mark")).toString())
             .arg(qm_->value(rec_imp.indexOf("id3")).toString())
             .arg(qm_->value(rec_imp.indexOf("kol")).toString())
             .arg(qm_->value(rec_imp.indexOf("nikotin")).toString());
        qDebug()<<x<<"2asdasa";
        if (!qc_->query2.exec(x)) {qDebug()<<qs_->lastError().text();}

    }

  while (qm_->next()) {

        QString z = "INSERT INTO asd(mark, id2, kol, nikotin)"
                      "VALUES('%1', '%2', '%3', '%4');";
        QString x;
        x = z.arg(qm_->value(rec_imp.indexOf("mark")).toString())
             .arg(qm_->value(rec_imp.indexOf("id3")).toString())
             .arg(qm_->value(rec_imp.indexOf("kol")).toString())
             .arg(qm_->value(rec_imp.indexOf("nikotin")).toString());
        qDebug()<<x<<"2asdasa";
        if (!qc_->query2.exec(x)) {qDebug()<<qs_->lastError().text();}

    }














    if (qs_->first()) {


    QString z = "INSERT INTO zxc(id, FIO, pol, dr, kurenie, id2)"
                  "VALUES('%1', '%2', '%3', '%4', '%5', '%6');";
    QString x;
    x = z.arg(nNumber2)
         .arg(qs_->value(rec2.indexOf("FIO")).toString())
         .arg(qs_->value(rec2.indexOf("pol")).toString())
         .arg(qs_->value(rec2.indexOf("dr")).toString())
         .arg(qs_->value(rec2.indexOf("kurenie")).toString())
         .arg(qs_->value(rec2.indexOf("id3")).toString());
    qDebug()<<x<<"2asdasa";

    if (!qc_->query.exec(x)) {qDebug()<<qs_->lastError().text();}
                    }   


while (qs_->next())
    {
    nNumber2 = nNumber2 + 1;
    QString z = "INSERT INTO zxc(id, FIO, pol, dr, kurenie, id2)"
                 "VALUES('%1', '%2', '%3', '%4', '%5', '%6');";
    QString x;
    x = z.arg(nNumber2)
         .arg(qs_->value(rec2.indexOf("FIO")).toString())
         .arg(qs_->value(rec2.indexOf("pol")).toString())
         .arg(qs_->value(rec2.indexOf("dr")).toString())
         .arg(qs_->value(rec2.indexOf("kurenie")).toString())
         .arg(qs_->value(rec2.indexOf("id3")).toString());
    qDebug()<<x;

    if (!qc_->query.exec(x)) {qDebug()<<qs_->lastError().text();}

    }
}

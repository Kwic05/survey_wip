#include "dlg2.h"
#include "ui_dlg2.h"
#include <QSqlRecord>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQueryModel>




dlg2::dlg2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg2)
{
    ui->setupUi(this);
}

dlg2::~dlg2()
{
    delete ui;
}

void dlg2::initializate()
{
    qc_->executeSelect();

     if (qc_->query.last()) {
         QSqlRecord rec  = qc_->query.record();
         nNumber = qc_->query.value(rec.indexOf("id")).toInt();
     }
     QSqlQueryModel *model = new QSqlQueryModel();
     model->setQuery(qc_->query2);
     ui->comboBox->setModel(model);
}

void dlg2::on_pushButton_2_clicked()
{

    QString d = "SELECT id2 FROM asd WHERE mark = '%1'";
    QString s = d.arg(ui->comboBox->currentText());
            qc_->query2.exec(s);
            QSqlQueryModel *model2 = new QSqlQueryModel();
            model2->setQuery(qc_->query2);

    QComboBox comb1;
    comb1.setModel(model2);

    if (comb1.currentText().isEmpty()) {
    qc_->query2.exec("select * from asd order by id2");
        if (qc_->query2.last()) {
            QSqlRecord rec  = qc_->query2.record();
            nNumber2 = qc_->query2.value(rec.indexOf("id2")).toInt();
        }

        nNumber2 = nNumber2 + 1;
        QString e = "INSERT INTO asd(mark, id2, kol, nikotin)"
                "VALUES('%1', '%2', '%3', '%4');";

        QString w;
        w = e.arg(ui->comboBox->currentText())
             .arg(nNumber2)
             .arg("null")
             .arg("null");

        if (!qc_->query2.exec(w)) {}


        nNumber = nNumber + 1;
        QString y;
        if (ui->radioButton->isChecked()) {y="y";}
        else y="n";
        QString z = "INSERT INTO zxc(id, FIO, pol, dr, kurenie, id2)"
                      "VALUES('%1', '%2', '%3', '%4', '%5', '%6');";
        QString x;
        x = z.arg(nNumber)
             .arg(ui->lineEdit->text())
             .arg(ui->lineEdit_2->text())
             .arg(ui->lineEdit_3->text())
             .arg(y)
             .arg(nNumber2);

        if (!qc_->query.exec(x)) {qDebug()<<qc_->query.lastError().text();}

        QMessageBox::information(0,"","Operation successful","Ok",QString(),0);
    }
    else
    {
        nNumber = nNumber + 1;
        QString y;
        if (ui->radioButton->isChecked()) {y="y";}
        else y="n";


        QString z = "INSERT INTO zxc(id, FIO, pol, dr, kurenie, id2)"
                      "VALUES('%1', '%2', '%3', '%4', '%5', '%6');";
        QString x;
        x = z.arg(nNumber)
             .arg(ui->lineEdit->text())
             .arg(ui->lineEdit_2->text())
             .arg(ui->lineEdit_3->text())
             .arg(y)
             .arg(comb1.currentText());

        if (!qc_->query.exec(x)) {qDebug()<<qc_->query.lastError().text();}

        QMessageBox::information(0,"","Operation successful","Ok",QString(),0);


    }

}

void dlg2::on_pushButton_clicked()
{
    close();
}

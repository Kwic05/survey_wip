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
     ui->fontComboBox->setModel(model);
}

void dlg2::on_pushButton_2_clicked()
{

    nNumber = nNumber + 1;
    QString y;
    if (ui->radioButton->isChecked()) {y="y";}
    else y="n";
    QString z = "INSERT INTO zxc(id, FIO, pol, dr, kurenie)"
                  "VALUES('%1', '%2', '%3', '%4', '%5');";
    QString x;
    x = z.arg(nNumber)
         .arg(ui->lineEdit->text())
         .arg(ui->lineEdit_2->text())
         .arg(ui->lineEdit_3->text())
         .arg(y);


    if (!qc_->query.exec(x)) {qDebug()<<qc_->query.lastError().text();}

    QMessageBox::information(0,"","Operation successful","Ok",QString(),0);
}

void dlg2::on_pushButton_clicked()
{
    close();
}

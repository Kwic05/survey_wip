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

}

void dlg4::on_pushButton_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase ("QSQLITE","connection2") ;
    db.setDatabaseName(ui->lineEdit->text());
    if (!db.open()){qDebug()<<"222";}
    qs_ = QSqlQuery(db);
    qDebug()<<qs_.lastError().text();
    qs_.exec("select * from zxc");
    close();
}

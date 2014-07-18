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
    dlg44.setQueryContainer(qc_);
    dlg44.exec();

}

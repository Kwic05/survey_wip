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

struct Cigarette
{
    int id;
    QString name;
    int quantity;
    int nicotine;
};

struct Survey
{
    QString fio;
    QString gender;
    QString birthDate;
    QString smocking;
    int cigaretteId;
    Cigarette* cigarette;
};

void dlg4::on_pushButton_2_clicked()
{
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE", "joiningConnection");
    db2.setDatabaseName(ui->lineEdit->text());
    qDebug() << "open: " << db2.open();

    typedef QMap<int, Cigarette*> Cigarette2Map;
    Cigarette2Map cigarette2Map;

    {
        QString cigarette2Query = "SELECT id2,mark,kol,nikotin FROM asd";
        QSqlQuery q(cigarette2Query, db2);

        while(q.next()) {
            auto cig = new Cigarette;
            cig->id = q.value("id2").toInt();
            cig->name = q.value("mark").toString();
            cig->nicotine = q.value("nikotin").toInt();
            cig->quantity = q.value("kol").toInt();

            cigarette2Map[cig->id] = cig;
        }
    }

    QVector<Survey> survies2;

    {
        QString survies2Query = "";
        QSqlQuery q;

        while(q.next()) {
            Survey s;
            s.fio = q.value();


            Cigarette2Map::const_iterator it = cigarette2Map.find(s.cigaretteId);
            s.cigarette = it!=cigarette2Map.cend()? *it: 0;

            survies2.push_back(s);
        }
    }

    QMap<QString, int> cigarette1Map;

    {

    }


}

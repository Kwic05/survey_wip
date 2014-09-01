#include "dlg4.h"
#include "ui_dlg4.h"
#include <QFileDialog>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QMap>

#include <algorithm>
#include <memory>

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

typedef std::shared_ptr<Cigarette> CigarettePtr;

struct Survey
{
    QString fio;
    QString gender;
    QString birthDate;
    QString smoking;
    int cigaretteId;
    CigarettePtr cigarette;
};



void dlg4::on_pushButton_2_clicked()
{
    QSqlDatabase db1 = QSqlDatabase::database();

    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE", "joiningConnection");
    db2.setDatabaseName(ui->lineEdit->text());
    qDebug() << "open: " << db2.open();

    typedef QMap<int, CigarettePtr> Cigarette2Map;
    Cigarette2Map cigarette2Map;

    {
        QString cigarette2Query = "SELECT id2,mark,kol,nikotin FROM asd";
        QSqlQuery q(cigarette2Query, db2);

        while(q.next()) {
            CigarettePtr cig(new Cigarette);
            cig->id = q.value("id2").toInt();
            cig->name = q.value("mark").toString();
            cig->nicotine = q.value("nikotin").toInt();
            cig->quantity = q.value("kol").toInt();

            cigarette2Map[cig->id] = cig;
        }
    }

    typedef QVector<Survey> Surveys2;
    Surveys2 surveys2;

    {
        QString surveys2Query = "SELECT FIO,id,pol,dr,kurenie,id2 FROM zxc";
        QSqlQuery q(surveys2Query, db2);

        while(q.next()) {
            Survey s;
            s.fio = q.value("FIO").toString();
            s.gender = q.value("pol").toString();
            s.birthDate = q.value("dr").toString();
            s.smoking = q.value("kurenie").toString();
            s.cigaretteId = q.value("id2").toInt();

            Cigarette2Map::const_iterator it = cigarette2Map.find(s.cigaretteId);
            s.cigarette = it!=cigarette2Map.cend()? *it: 0;

            surveys2.push_back(s);
        }
    }

    typedef QMap<QString, int> Cigarette1Map;
    Cigarette1Map cigarette1Map;

    {
        QString cigarette1Query = "SELECT id2, mark FROM asd";
        QSqlQuery q(cigarette1Query, db1);

        while (q.next()) {
            QString name = q.value("mark").toString();
            int cigId = q.value("id2").toInt();
            cigarette1Map[name] = cigId;
        }
    }

    {
        QVariantList ids;
        QVariantList names;
        QVariantList quantities;
        QVariantList nicotines;

        int unusedId = *std::max_element(cigarette1Map.cbegin(), cigarette1Map.cend());
        ++unusedId;

        for (auto cig2It=cigarette2Map.begin(); cig2It!=cigarette2Map.end(); ++cig2It) {
            CigarettePtr cig = cig2It.value();

            Cigarette1Map::iterator cig1It = cigarette1Map.find(cig->name);
            if (cig1It!=cigarette1Map.end()) {
                cig->id = cig1It.value();
            }
            else {
                cig->id = unusedId++;

                ids.push_back(cig->id);
                names.push_back(cig->name);
                quantities.push_back(cig->quantity);
                nicotines.push_back(cig->nicotine);
            }
        }

        QString cig1InsertQuery = "INSERT INTO asd(id2,mark,kol,nikotin) VALUES(?,?,?,?)";
        QSqlQuery q(cig1InsertQuery,db1);
        q.prepare(cig1InsertQuery);
        q.addBindValue(ids);
        q.addBindValue(names);
        q.addBindValue(quantities);
        q.addBindValue(nicotines);

        qDebug() << "cig1InsertQuery:" << q.execBatch();
    }

    {
        QVariantList ids;
        QVariantList fios;
        QVariantList genders;
        QVariantList birthDates;
        QVariantList smokings;
        QVariantList cigaretteIds;

        int unusedId=0;
        qc_->executeSelect();
        if (qc_->query.last()) {
            QSqlRecord rec3  = qc_->query.record();
            unusedId = unusedId + qc_->query.value(rec3.indexOf("id")).toInt();
        }
        unusedId++;
        qDebug() << "unusedId" << unusedId;

        for (auto it=surveys2.cbegin(); it!=surveys2.cend(); ++it) {
            const Survey &survey = *it;
            ids.push_back(unusedId++);
            fios.push_back(survey.fio);
            genders.push_back(survey.gender);
            birthDates.push_back(survey.birthDate);
            smokings.push_back(survey.smoking);
            cigaretteIds.push_back(survey.cigaretteId);
        }

        QString survey1InsertQuery = "INSERT INTO zxc(id, FIO, pol, dr, kurenie, id2) VALUES(?,?,?,?,?,?)";
        QSqlQuery q(survey1InsertQuery,db1);
        q.prepare(survey1InsertQuery);
        q.addBindValue(ids);
        q.addBindValue(fios);
        q.addBindValue(genders);
        q.addBindValue(birthDates);
        q.addBindValue(smokings);
        q.addBindValue(cigaretteIds);

        qDebug() << "survey1InsertQuery:" << q.execBatch();
    }
}

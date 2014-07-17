#ifndef DLG4_H
#define DLG4_H
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDialog>
#include <QFileDialog>
#include "querycontainer.h"


namespace Ui {
class dlg4;
}

class dlg4 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg4(QWidget *parent = 0);
    ~dlg4();
    QString myString;
    QSqlQuery qs_;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::dlg4 *ui;
};

#endif // DLG4_H

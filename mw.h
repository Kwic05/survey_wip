#ifndef MW_H
#define MW_H

#include <QMainWindow>
#include <QSqlQuery>
#include "dlg1.h"

#include "querycontainer.h"

namespace Ui {
class mw;
}

class mw : public QMainWindow
{
    Q_OBJECT

public:
    explicit mw(QWidget *parent = 0);
    ~mw();

    void setQueryContainer(QueryContainer* qc) {
        qc_ = qc;
    }

public slots:
    int on_pushButton_clicked();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::mw *ui;
    QueryContainer* qc_;
};

#endif // MW_H

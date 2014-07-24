#ifndef DLG2_H
#define DLG2_H

#include <QDialog>

#include "querycontainer.h"

namespace Ui {
class dlg2;
}

class dlg2 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg2(QWidget *parent = 0);
    ~dlg2();

    void setQueryContainer(QueryContainer* qc){
        qc_ = qc;
    }

    void initializate();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::dlg2 *ui;
    QueryContainer* qc_;
   int nNumber, nNumber2;
};

#endif // DLG2_H

#ifndef DLG1_H
#define DLG1_H

#include <QDialog>

#include "querycontainer.h"

namespace Ui {
class dlg1;
}

class dlg1 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg1(QWidget *parent = 0);
    ~dlg1();

    void setMessage(const QString& str1, const QString& str2, const QString& str3, const QString& kur);

    void setQueryContainer(QueryContainer* qc){
        qc_ = qc;
    }

    void initializate();
       QueryContainer* qc_;

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();


private:
    Ui::dlg1 *ui;

};

#endif // DLG1_H

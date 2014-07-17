#include "mw.h"

#include <QApplication>

#include "data.h"
#include "querycontainer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!createConnection())
        return -1;
    QueryContainer qc;
    qc.initialize();

    mw w;
    w.setQueryContainer(&qc);
    w.show();

    return a.exec();
}

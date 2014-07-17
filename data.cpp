#include "data.h"


bool createConnection(){
    QSqlDatabase d = QSqlDatabase::addDatabase("QSQLITE");
    d.setDatabaseName("survey.sqlite3");
    return d.open();
}

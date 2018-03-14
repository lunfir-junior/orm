#include <QCoreApplication>
#include <QtSql>

#include "Entity.h"
#include "A.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  Entity<int> entity(23);
  A test;

  QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
  db.setHostName("127.0.0.1");
  db.setDatabaseName("schema");
  db.setUserName("lunfir");
  db.setPassword("lunfir");

  bool ok = db.open();

  if ( ok ) {
    qDebug() << "Connect to database...";
//    QSqlQuery ins("DELETE FROM section WHERE section_id=5");
    QSqlQuery query("SELECT section_title FROM section");
    while (query.next())
    {
      qWarning() << query.value(0).toString();
    }
  } else {
    qDebug() << "smth going wrong: " << db.lastError();
  }

  a.quit();

  return 0;
}

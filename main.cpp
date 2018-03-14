#include <QCoreApplication>
#include <QtSql>

#include "Entity.h"
#include "Article.h"
#include "Category.h"
#include "Tag.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  Article article;

  bool ok = article.Article::setDatabase(QString("127.0.0.1"), QString("schema"), QString("lunfir"), QString("lunfir"));

  if ( ok ) {
    qDebug() << "Connect to database...!!!!!!";
//    QSqlQuery ins("DELETE FROM section WHERE section_id=5");
//    QSqlQuery query("SELECT section_title FROM section");
//    while (query.next())
//    {
//      qWarning() << query.value(0).toString();
//    }
  } else {
    qDebug() << "smth going wrong: " /*<< db.lastError()*/;
  }

  a.quit();

  return 0;
}

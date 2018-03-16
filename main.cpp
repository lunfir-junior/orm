#include <QCoreApplication>
#include <QtSql>

#include "Entity.h"
#include "Article.h"
#include "Category.h"
#include "Tag.h"
#include "Section.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  /*bool ok = */Entity::setDatabase(QString("127.0.0.1"), QString("schema"), QString("lunfir"), QString("lunfir"));
  Section section(2);

  section.insert();

//  section.load();
  qDebug() << "created: " << section.getCreated();

//  section.retrieve();
//  qDebug() << "date time: " << section.getCreated();

//  Tag tag(2);
//  tag.retrieve();

//  qDebug() << "article.getId(): " << article.getId();


//  if ( ok ) {
//    qDebug() << "Connect to database...!!!!!!";
//    QSqlQuery ins("INSERT INTO section(section_title) VALUES ('content')");
//    QSqlQuery query("SELECT section_title FROM section");
//    while (query.next())
//    {
//      qWarning() << query.value(0).toString();
//    }
//  } else {
//    qDebug() << "smth going wrong: " /*<< db.lastError()*/;
//  }

  a.quit();

  return 0;
}

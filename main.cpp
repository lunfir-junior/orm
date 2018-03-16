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

  Entity::setDatabase(QString("127.0.0.1"), QString("schema"), QString("lunfir"), QString("lunfir"));
  Section section(2);

  section.setColumn(QString("section_title"), QString("news"));
  section.save();
  qDebug() << section.getColumn(QString("section_title"));

  a.quit();

  return 0;
}

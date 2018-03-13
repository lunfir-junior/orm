#include <QString>
#include <QDebug>

class Entity
{
  public:
    explicit Entity()
    {
      qDebug() << __PRETTY_FUNCTION__ << deleteQuery;
    }

    virtual ~Entity()
    {
      qDebug() << __PRETTY_FUNCTION__;
    }

    static QString deleteQuery;
    static QString insertQuery;
    static QString listQuery;
    static QString selectQuery;
    static QString updateQuery;

  private:

};

QString Entity::deleteQuery  = QString ("DELETE FROM %1 WHERE %1_id=%2");  //%1 - table
QString Entity::insertQuery  = QString ("INSERT INTO %1(%2) VALUES (%3) RETURNING %1_id");
QString Entity::listQuery    = QString ("SELECT * FROM %1");
QString Entity::selectQuery  = QString ("SELECT * FROM %1 WHERE %1_id=%3");
QString Entity::updateQuery  = QString ("UPDATE %1 SET %2 WHERE %1_id=%3"); //%2 - columns

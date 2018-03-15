#include "Entity.h"

QSqlDatabase Entity::db = QSqlDatabase();
QString Entity::deleteQuery   = "DELETE FROM %1 WHERE %1_id=%2";
QString Entity::insertQuery   = "INSERT INTO %1 (%2) VALUES (%3) RETURNING %1_id";
QString Entity::listQuery     = "SELECT * FROM %1";
QString Entity::selectQuery   = "SELECT * FROM %1 WHERE %1_id=%2";
QString Entity::updateQuery   = "UPDATE %1 SET %2 WHERE %1_id=%3";

bool Entity::setDatabase(QString host, QString dbName, QString user, QString password)
{
  Entity::db = QSqlDatabase::addDatabase("QPSQL");
  Entity::db.setHostName(host);
  Entity::db.setDatabaseName(dbName);
  Entity::db.setUserName(user);
  Entity::db.setPassword(password);

  return Entity::db.open();
}

Entity::Entity(QObject *parent) : QObject(parent)
{
  m_id = 0;
  m_isLoaded = false;
  m_isModified = false;
}

Entity::Entity(int id, QObject *parent) : QObject(parent)
{
  m_id = id;
  m_isLoaded = false;
  m_isModified = false;

//  # select from article where article_id=?
}

void Entity::retrieve()
{
  if ( !db.isOpen() ) {
    qWarning() << "No db connect";
    return;
  }

  m_isLoaded = true;
  m_table = QString::fromUtf8(metaObject()->className()).toLower();
  QSqlQuery query(Entity::selectQuery.arg(m_table, QString::number(m_id)));

  while ( query.next() ) {
    qWarning() << query.value(0).toString();
    qWarning() << query.value(1).toString();
    qWarning() << query.value(2).toString();
    qWarning() << query.value(3).toString();
    qWarning() << query.value(4).toString();
  }
}

Entity::~Entity()
{

}

int Entity::getId()
{
  return m_id;
}

QDateTime Entity::getCreated()
{
  QDateTime out = QDateTime::currentDateTime();

  return out;
}

QDateTime Entity::getUpdated()
{
  QDateTime out = QDateTime::currentDateTime();

  return out;
}

void Entity::load()
{
  // check, if current object is already loaded
  // get a single row from corresponding table by id
  // store columns as object fields with unchanged column names as keys
}

void Entity::insert()
{
  // execute an insert query, built from fields keys and values
}

void Entity::update()
{
  // execute an update query, built from fields keys and values
}

void Entity::destroy()
{
  // execute a delete query with current instance id
}

void Entity::save()
{
  // execute either insert or update query, depending on instance id
}

QString Entity::getColumn(QString name)
{
  return m_fields.value(name);
}

void Entity::setColumn(QString name, QString value)
{
  m_fields.insert(name, value);
}




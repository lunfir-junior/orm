#include "Entity.h"

QSqlDatabase Entity::db = QSqlDatabase();
QString Entity::deleteQuery   = "DELETE FROM %1 WHERE %1_id=%2";
QString Entity::insertQuery   = "INSERT INTO %1 (%2) VALUES (%3) RETURNING %1_id";
QString Entity::listQuery     = "SELECT * FROM %1";
QString Entity::selectQuery   = "SELECT * FROM %1 WHERE %1_id=%2";
QString Entity::childrenQuery = "SELECT * FROM %1 WHERE %2$s_id=?";
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
  qDebug() << __PRETTY_FUNCTION__ <<  deleteQuery;
}

Entity::Entity(int id, QObject *parent) : QObject(parent)
{
  m_id = id;
  m_isLoaded = false;
  m_isModified = false;
  qDebug() << "m_id: " << m_id;
  qDebug() << __PRETTY_FUNCTION__ <<  deleteQuery;
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

Entity* Entity::getColumn(QString name)
{
  return m_fields.value(name);
}

void Entity::setColumn(QString name, Entity *value)
{
  m_fields.insert(name, value);
}

void Entity::setParent(QString name, int id)
{
  Q_UNUSED(name);
  Q_UNUSED(id);
  // put parent id into fields with <name>_<id> as a key
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



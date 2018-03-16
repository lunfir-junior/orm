#include "Entity.h"

QSqlDatabase Entity::db = QSqlDatabase();
QString Entity::deleteQuery   = "DELETE FROM %1 WHERE %1_id=%2";
QString Entity::insertQuery   = "INSERT INTO %1 (%2) VALUES (%3) RETURNING %1_id";
QString Entity::listQuery     = "SELECT * FROM %1";
QString Entity::selectQuery   = "SELECT * FROM %1 WHERE %1_id=%2";
QString Entity::updateQuery   = "UPDATE %1 SET (%2)=(%3) WHERE %1_id=%4";

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
}

Entity::~Entity()
{

}

int Entity::getId()
{
  return m_id;
}

int Entity::getCreated()
{
  if ( m_isLoaded )
    return m_fields.value(QString(m_table + "created")).toInt();

  if ( !db.isOpen() ) {
    qWarning() << "No db connect";
    return -1;
  }

  int out;
  QSqlQuery query(QString("SELECT %1_created FROM %1 WHERE %1_id=%2").arg(m_table, QString::number(m_id)));

  while ( query.next() ) {
    out = query.value(0).toInt();
  }
  return out;
}

int Entity::getUpdated()
{
  if ( m_isLoaded )
    return m_fields.value(QString(m_table + "updated")).toInt();

  if ( !db.isOpen() ) {
    qWarning() << "No db connect";
    return -1;
  }

  int out;
  QSqlQuery query(QString("SELECT %1_updated FROM %1 WHERE %1_id=%2").arg(m_table, QString::number(m_id)));

  while ( query.next() ) {
    out = query.value(0).toInt();
  }
  return out;
}

void Entity::load()
{
  if ( !db.isOpen() ) {
    qWarning() << "No db connect";
    return;
  }

  if ( m_isLoaded ) {
    qWarning() << "Already loaded";
    return;
  }

  m_table = QString::fromUtf8(metaObject()->className()).toLower();
  QSqlQuery query(Entity::selectQuery.arg(m_table, QString::number(m_id)));
  QSqlRecord rec = query.record();
  int count = rec.count();

  while ( query.next() ) {
    for ( int i = 0; i < count; i++ ) {
      m_fields.insert(rec.fieldName(i), query.value(i).toString());
      qWarning() << rec.fieldName(i) << "   " << query.value(i).toString();
    }
  }

  m_isLoaded = true;
  qDebug() << "load: " << m_fields;
}

void Entity::insert()
{
  if ( !db.isOpen() ) {
    qWarning() << "No db connect";
    return;
  }

  if ( !m_isLoaded )
    load();

  m_table = QString::fromUtf8(metaObject()->className()).toLower();
  QString keys, values;

  keys = this->keys();
  values = this->values();

  QSqlQuery query(Entity::insertQuery.arg(m_table, keys, values));
  qWarning() << "insert: " << query.lastError();
}

void Entity::update()
{
  if ( !db.isOpen() ) {
    qWarning() << "No db connect";
    return;
  }

  if ( !m_isLoaded )
    load();

  m_table = QString::fromUtf8(metaObject()->className()).toLower();
  QString keys, values;
  keys = this->keys();
  values = this->values();

  QSqlQuery query(Entity::updateQuery.arg(m_table, keys, values, QString::number(m_id)));
  qWarning() << "update: " << query.lastError();
}

void Entity::destroy()
{
  if ( !db.isOpen() ) {
    qWarning() << "No db connect";
    return;
  }

  m_table = QString::fromUtf8(metaObject()->className()).toLower();
  QSqlQuery query(Entity::deleteQuery.arg(m_table, QString::number(m_id)));
}

void Entity::save()
{
  m_table = QString::fromUtf8(metaObject()->className()).toLower();

  if ( m_isModified ) {
    update();
    m_isModified = false;
  } else {
    insert();
  }
}

QString Entity::getColumn(QString name)
{
  return m_fields.value(name);
}

void Entity::setColumn(QString name, QString value)
{
  if ( !db.isOpen() ) {
    qWarning() << "No db connect";
    return;
  }

  if ( !m_isLoaded )
    load();

  m_fields.insert(name, value);
  qDebug() << "setColumn: " << m_fields;
  m_isModified = true;
}

QString Entity::values()
{
  QString out;
  QList<QString> valueList = m_fields.values();
  int lim = valueList.size() - 1;

  for ( int i = 0; i < lim; i++ ) {
    out.append("'");
    out.append(valueList.at(i));
    out.append("'");
    out.append(", ");
  }
  out.append("'");
  out.append(valueList.takeLast());
  out.append("'");

  return out;
}

QString Entity::keys()
{
  QString out;
  QList<QString> keyList = m_fields.keys();
  int lim = keyList.size() - 1;

  for ( int i = 0; i < lim; i++ ) {
    out.append(keyList.at(i));
    out.append(", ");
  }
   out.append(keyList.takeLast());

   return out;
}

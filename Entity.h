#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QtSql>
#include <QDateTime>

class Entity : public QObject
{
  Q_OBJECT

public:
  explicit Entity(QObject *parent = nullptr);
  explicit Entity(int id, QObject *parent = nullptr);

  virtual ~Entity();

  int m_id;
  bool m_isLoaded;
  bool m_isModified;
  QString m_table;
  QMap<QString, Entity*> m_fields;

  static bool setDatabase(QString host, QString dbName, QString user, QString password);

  int getId();
  QDateTime getCreated();
  QDateTime getUpdated();
  Entity* getColumn(QString name);

  template<class T>
  T getParent(T cls) {
    // get parent id from fields as <classname>_id, create and return an instance of class T with that id
    T def; return def; }

  template<class T>
  QList<T> getSiblings(T cls) {
    QList<T> out;
    T alpha; T beta;
    out.push_back(alpha);
    out.push_back(beta);

    // select needed rows and ALL columns from corresponding table
    // convert each row from ResultSet to instance of class T with appropriate id
    // fill each of new instances with column data
    // return list of children instances

    return out; }

  template<class T>
  QList<T> all(T cls) {
    QList<T> out;
    T alpha; T beta;
    out.push_back(alpha);
    out.push_back(beta);
    return out;
    // select ALL rows and ALL columns from corresponding table
    // convert each row from ResultSet to instance of class T with appropriate id
    // fill each of new instances with column data
    // aggregate all new instances into a single List<T> and return it
  }

  void setColumn(QString name, Entity *value);
  void setParent(QString name, int id);
  void destroy();
  void save();

private:
  static QSqlDatabase db;
  static QString deleteQuery;
  static QString insertQuery;
  static QString listQuery;
  static QString selectQuery;
  static QString childrenQuery;
  static QString updateQuery;

  void load();
  void insert();
  void update();

signals:

public slots:
};

#endif // ENTITY_H

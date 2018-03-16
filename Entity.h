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
  QMap<QString, QString> m_fields;

  static bool setDatabase(QString host, QString dbName, QString user, QString password);

  int getId();
  int getCreated();
  int getUpdated();
  QString getColumn(QString name);

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

  void setColumn(QString name, QString value);
  void destroy();
  void save();
  void load();
  void insert();
  void update();

private:
  static QSqlDatabase db;
  static QString deleteQuery;
  static QString insertQuery;
  static QString listQuery;
  static QString selectQuery;
  static QString childrenQuery;
  static QString updateQuery;


  QString values();
  QString keys();

signals:

public slots:
};

#endif // ENTITY_H

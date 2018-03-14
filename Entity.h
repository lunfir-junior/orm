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

  void setColumn(QString name, Entity *value);
  void setParent(QString name, int id);

private:
  static QSqlDatabase db;
  static QString deleteQuery;
  static QString insertQuery;
  static QString listQuery;
  static QString selectQuery;
  static QString childrenQuery;
  static QString updateQuery;

signals:

public slots:
};

#endif // ENTITY_H

//    public final void setParent(String name, Integer id) {
//        // put parent id into fields with <name>_<id> as a key
//    }

//    private void load() {
//        // check, if current object is already loaded
//        // get a single row from corresponding table by id
//        // store columns as object fields with unchanged column names as keys
//    }

//    private void insert() throws SQLException {
//        // execute an insert query, built from fields keys and values
//    }

//    private void update() throws SQLException {
//        // execute an update query, built from fields keys and values
//    }

//    public final void delete() throws SQLException {
//        // execute a delete query with current instance id
//    }

//    public final void save() throws SQLException {
//        // execute either insert or update query, depending on instance id
//    }

//    protected static <T extends Entity> List<T> all(Class<T> cls) {
//        // select ALL rows and ALL columns from corresponding table
//        // convert each row from ResultSet to instance of class T with appropriate id
//        // fill each of new instances with column data
//        // aggregate all new instances into a single List<T> and return it
//    }

//    private static Collection<String> genPlaceholders(int size) {
//        // return a collection, consisting of <size> "?" symbols,
//        // which should be joined later.
//        // each "?" is used in insert statements as a placeholder for values (google prepared statements)
//    }

//    private static Collection<String> genPlaceholders(int size, String placeholder) {
//        // return a collection, consisting of <size> <placeholder> symbols,
//        // which should be joined later.
//        // each <placeholder> is used in insert statements as a placeholder for values (google prepared statements)
//    }

//    private static String getJoinTableName(String leftTable, String rightTable) {
//        // generate the name of associative table for many-to-many relation
//        // sort left and right tables alphabetically
//        // return table name using format <table>__<table>
//    }

//    private java.util.Date getDate(String column) {
//        // pwoerful method, used to remove copypaste from getCreated and getUpdated methods
//    }

//    private static String join(Collection<String> sequence) {
//        // join collection of strings with ", " as <glue> and return a joined string
//    }

//    private static String join(Collection<String> sequence, String glue) {
//        // join collection of strings with <glue> and return a joined string
//    }

//    private static <T extends Entity> List<T> rowsToEntities(Class<T> cls, ResultSet rows) {
//        // convert a ResultSet of database rows to list of instances of corresponding class
//        // each instance must be filled with its data so that it must not produce additional queries to database to get it's fields
//    }

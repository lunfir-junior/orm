//#include <QObject>
#include <QString>
#include <QtSql>
#include <QDebug>

#include <typeinfo>

//#include "A.h"

template <class T>
class Entity/* : public A*//* : public QObject*/
{
//    Q_OBJECT

    static QString deleteQuery;
    static QString insertQuery;
    static QString listQuery;
    static QString selectQuery;
    static QString updateQuery;

  private:
//    QObject *test;
    QSqlDatabase m_db;
    QList<T> m_fields;
    T m_id;
    bool m_loaded;
    bool m_modified;
    const char* m_table;

  public:
    explicit Entity(T id = nullptr/*, QObject *parent = nullptr*/)
    {
      m_id = id;
      m_loaded = false;
      m_modified = false;
//      m_table = this->metaObject()->className();
      m_table = typeid(this).name();

      qDebug() << __PRETTY_FUNCTION__ << "  " << m_table;
    }

    virtual ~Entity()
    {
      qDebug() << __PRETTY_FUNCTION__;
    }

};

//template <class T>
//QString Entity<T>::deleteQuery  = QString ("DELETE FROM %1 WHERE %1_id=%2");  //%1 - table

//template <class T>
//QString Entity<T>::insertQuery  = QString ("INSERT INTO %1(%2) VALUES (%3) RETURNING %1_id");
//template <class T>
//QString Entity<T>::listQuery    = QString ("SELECT * FROM %1");
//template <class T>
//QString Entity<T>::selectQuery  = QString ("SELECT * FROM %1 WHERE %1_id=%3");
//template <class T>
//QString Entity<T>::updateQuery  = QString ("UPDATE %1 SET %2 WHERE %1_id=%3"); //%2 - columns


//class DatabaseError(Exception):
//    pass
//class NotFoundError(Exception):
//    pass

//class Entity(object):
//    db = None


//    def __init__(self, id=None):
//        if self.__class__.db is None:
//            raise DatabaseError()

//        self.__cursor   = self.__class__.db.cursor(
//            cursor_factory=psycopg2.extras.DictCursor
//        )
//        self.__fields   = {}
//        self.__id       = id
//        self.__loaded   = False
//        self.__modified = False
//        self.__table    = self.__class__.__name__.lower()

//    def __getattr__(self, name):
//        # check, if instance is modified and throw an exception
//        # get corresponding data from database if needed
//        # check, if requested property name is in current class
//        #    columns, parents, children or siblings and call corresponding
//        #    getter with name as an argument
//        # throw an exception, if attribute is unrecognized
//        pass

//    def __setattr__(self, name, value):
//        # check, if requested property name is in current class
//        #    columns, parents, children or siblings and call corresponding
//        #    setter with name and value as arguments or use default implementation
//        pass

//    def __execute_query(self, query, args):
//        # execute an sql statement and handle exceptions together with transactions
//        pass

//    def __insert(self):
//        # generate an insert query string from fields keys and values and execute it
//        # use prepared statements
//        # save an insert id
//        pass

//    def __load(self):
//        # if current instance is not loaded yet — execute select statement and store it's result as an associative array (fields), where column names used as keys
//        pass

//    def __update(self):
//        # generate an update query string from fields keys and values and execute it
//        # use prepared statements
//        pass

//    def _get_children(self, name):
//        # return an array of child entity instances
//        # each child instance must have an id and be filled with data
//        pass

//    def _get_column(self, name):
//        # return value from fields array by <table>_<name> as a key
//        pass

//    def _set_column(self, name, value):
//        # put new value into fields array with <table>_<name> as a key
//        pass

//    @classmethod
//    def all(cls):
//        # get ALL rows with ALL columns from corrensponding table
//        # for each row create an instance of appropriate class
//        # each instance must be filled with column data, a correct id and MUST NOT query a database for own fields any more
//        # return an array of istances
//        pass

//    def delete(self):
//        # execute delete query with appropriate id
//        pass

//    @property
//    def id(self):
//        # try to guess yourself
//        pass

//    @property
//    def created(self):
//        # try to guess yourself
//        pass

//    @property
//    def updated(self):
//        # try to guess yourself
//        pass

//    def save(self):
//        # execute either insert or update query, depending on instance id
//        pass

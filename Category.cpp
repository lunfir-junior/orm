#include "Category.h"

Category::Category(QObject *parent) : Entity(parent)
{
//  m_table = QString::fromUtf8(metaObject()->className()).toLower();
//  qDebug() << "m_table: " << m_table;
}

Category::Category(int id, QObject *parent) : Entity(id, parent)
{
//  m_table = QString::fromUtf8(metaObject()->className()).toLower();
//  qDebug() << "m_table: " << m_table;
}

Category::~Category()
{

}

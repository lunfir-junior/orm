#include "Article.h"

Article::Article(QObject *parent) : Entity(parent)
{
//  m_table = QString::fromUtf8(metaObject()->className()).toLower();
//  retrieve();
//  qDebug() << "m_table: " << m_table;
//  qDebug() << "m_fields: " << m_fields;
}

Article::Article(int id, QObject *parent) : Entity(id, parent)
{
//  m_table = QString::fromUtf8(metaObject()->className()).toLower();
//  retrieve();
//  qDebug() << "m_table: " << m_table;

}

Article::~Article()
{

}

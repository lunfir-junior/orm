#include "Tag.h"

Tag::Tag(QObject *parent) : Entity(parent)
{
//  m_table = QString::fromUtf8(metaObject()->className()).toLower();
//  qDebug() << "m_table: " << m_table;
}

Tag::Tag(int id, QObject *parent) : Entity(id, parent)
{
//  m_table = QString::fromUtf8(metaObject()->className()).toLower();
//  qDebug() << "m_table: " << m_table;
}

Tag::~Tag()
{

}

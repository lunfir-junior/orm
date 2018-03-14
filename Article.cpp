#include "Article.h"

Article::Article(QObject *parent) : Entity(parent)
{

}

Article::Article(int id, QObject *parent) : Entity(id, parent)
{

}

Article::~Article()
{

}

#ifndef ARTICLE_H
#define ARTICLE_H

#include "Entity.h"

class Article : public Entity
{
  Q_OBJECT

public:
  Article(QObject *parent = nullptr);
  Article(int id, QObject *parent = nullptr);

  virtual ~Article();
};

#endif // ARTICLE_H

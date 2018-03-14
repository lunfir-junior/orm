#ifndef CATEGORY_H
#define CATEGORY_H

#include "Entity.h"

class Category : public Entity
{
  Q_OBJECT

public:
  Category(QObject *parent = nullptr);
  Category(int id, QObject *parent = nullptr);

  virtual ~Category();

};

#endif // CATEGORY_H

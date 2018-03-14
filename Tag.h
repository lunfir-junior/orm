#ifndef TAG_H
#define TAG_H

#include "Entity.h"

class Tag : public Entity
{
  Q_OBJECT

public:
  Tag(QObject *parent = nullptr);
  Tag(int id, QObject *parent = nullptr);

  virtual ~Tag();
};

#endif // TAG_H

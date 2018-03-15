#ifndef SECTION_H
#define SECTION_H

#include "Entity.h"

class Section : public Entity
{
    Q_OBJECT

  public:
    Section(QObject *parent = nullptr);
    Section(int id, QObject *parent = nullptr);

    virtual ~Section();
};

#endif // SECTION_H

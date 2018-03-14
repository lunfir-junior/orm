#ifndef A_H
#define A_H

#include <Entity.h>

class A : public Entity
{
//    Q_OBJECT

  public:
    explicit A() : Entity() {
      qDebug() << __PRETTY_FUNCTION__ << "  " << this->m_table;
       }

    virtual ~A() { }

};

#endif // A_H

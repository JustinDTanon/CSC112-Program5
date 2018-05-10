#ifndef ARCHER_H
#define ARCHER_H
#include "characters.h"

class Archer : public Characters
{
public:
    Archer();
    virtual ~Archer();

    virtual void actionChoice(int a);
    
    virtual void attack();
    virtual void defend();
    virtual void skillChoice(int c);
    virtual void retreat();
    
    virtual void skill1();
    virtual void skill2();
    
private:
    int hp;
    int ad;
    int ap;
    int mana;
};

#endif
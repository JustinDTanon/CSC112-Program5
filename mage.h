#ifndef Mage_H
#define Mage_H
#include "characters.h"

class Mage : public Characters
{
public:
    Mage();
    virtual ~Mage();

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
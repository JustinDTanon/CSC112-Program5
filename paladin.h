#ifndef PALADIN_H
#define PALADIN_H
#include "characters.h"

class Paladin : public Characters
{
public:
    Paladin();
    virtual ~Paladin();
    
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
    int energy;
};

#endif
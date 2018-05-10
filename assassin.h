#ifndef ASSASSIN_H
#define ASSASSIN_H
#include "characters.h"

class Assassin : public Characters
{
public:
    Assassin();
    virtual ~Assassin();

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
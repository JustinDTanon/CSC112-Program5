#ifndef WARRIOR_H
#define WARRIOR_H
#include "characters.h"

class Warrior : public Characters
{
public:
    Warrior();
    virtual ~Warrior();

    virtual void actionChoice(int a);
    
    virtual void attack();
    virtual void defend();
    virtual void skillChoice();
    virtual void actionValidate();
    virtual void retreat();
    
    virtual void skill1();
    virtual void skill2();
    
private:
    int hp;
    int ad;
    int ap;
    int mana;
    double dr;
};

#endif
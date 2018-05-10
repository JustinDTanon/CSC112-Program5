#ifndef BERZERKER_H
#define BERZERKER_H
#include "characters.h"

class Berzerker : public Characters
{
public:
    Berzerker();
    virtual ~Berzerker();

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
};

#endif
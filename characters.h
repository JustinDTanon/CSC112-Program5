#ifndef CHARACTERS_H
#define CHARACTERS_H

class Characters
{
public:
    virtual void actionChoice(int a)=0;
    
    virtual void attack()=0;
    virtual void defend()=0;
    virtual void skillChoice(int c)=0;
    virtual void retreat()=0;
    
    virtual void skill1()=0;
    virtual void skill2()=0;
    
};

#endif
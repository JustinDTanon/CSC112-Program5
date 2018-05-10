#ifndef MENU_H
#define MENU_H
#include "widget.h"
#include "application.h"
#include "termmanip.h"
#include <iostream>

class Menu : public Widget
{
public:
    //Constructors
    Menu();
    Menu(int _x, int _y);
    
    //Widget functions
    virtual void display();
    virtual void handleEvent(Event *e);
    
    //Weapon display functions
    virtual void sword();
    virtual void shield();
    virtual void axe();
    virtual void fist();
    virtual void bow();
    virtual void dagger();
    virtual void book();
    virtual void staff();
    virtual int cursor();
    virtual void cursor(int c);
    virtual void instructions();
    
    //Running check
    virtual void running(bool r);
    virtual bool running();
    
private:
    int _cursor;
    bool _running;
    int counter;
};

#endif
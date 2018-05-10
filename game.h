#ifndef GAME_H
#define GAME_H

#include "menu.h"
#include "widget.h"
#include "characters.h"
#include "event.h"

class Game : public Widget
{
public:
    //Constructors
    Game();
    Game(int _x, int _y);
    ~Game();
    
    //Widget functions
    virtual void handleEvent(Event *e);
    virtual void display();
    
    //Game functions
    virtual void pickFighter(int c);
    
private:
    bool _menu;
    Menu menu;
    Characters *fighter;
    int choice;
};


#endif
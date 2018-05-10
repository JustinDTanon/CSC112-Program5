#include "game.h"
#include "warrior.h"
#include "paladin.h"
#include "berzerker.h"
#include "monk.h"
#include "archer.h"
#include "assassin.h"
#include "mage.h"
#include "necromancer.h"

using namespace std;

Game::Game() : Game(1, 1)
{
    //Do nothing
}


Game::Game(int _x, int _y) : Widget(_x, _y, 90, 30)
{
    _menu = true;
}


Game::~Game()
{
    delete fighter;
}


void Game::handleEvent(Event *e)
{
    if(e->type() == "keyboard")
    {
        //we got a keyboard event!
        KeyboardEvent *kb = (KeyboardEvent *)e;  //cast to a kb event

        if(_menu)
        {
            //If the player is still in the menu then pass the event to the menu
            menu.handleEvent(e);
            _menu = menu.running();
            
            //If the player has selected their fighter then retrieve the choice
            if(! _menu)
            {
                choice = menu.cursor();
                pickFighter(choice);
            }
        } else
        {
            if(kb->key() == '1')
            {
                
            } else if(kb->key() == '2')
            {
                
            } else if(kb->key() == '3')
            {
                
            } else if(kb->key() == '4')
            {
                if(_parent) ((Application*)_parent)->running(false);
            } else if(kb->key() == ENTER)
            {
                
            }
        }
    }
    
    display();
}


void Game::display()
{
    cout << cursorPosition(28, 5) << " __________            __________"
         << cursorPosition(28, 6) << '[' << greenBackground << "__________" << normal << "]          [" << redBackground << "__________" << normal << ']';
    
    cout << cursorPosition(1, 23) << "     ________________________________________________________________________________"
         << cursorPosition(1, 24) << "   _/                                                                                \\_"
         << cursorPosition(1, 25) << " _/                                                                                    \\_"
         << cursorPosition(1, 26) << "|                                                                                        |"
         << cursorPosition(1, 27) << "|                                                                                        |"
         << cursorPosition(1, 28) << "|_                                                                                      _|"
         << cursorPosition(1, 29) << "  \\_                                                                                  _/"
         << cursorPosition(1, 30) << "    \\________________________________________________________________________________/";
}


void Game::pickFighter(int c)
{
    if(c == 1)
    {
        fighter = new Warrior();
    } else if(c == 2)
    {
        fighter = new Paladin();
    } else if(c == 3)
    {
        fighter = new Berzerker();
    } else if(c == 4)
    {
        fighter = new Monk();
    } else if(c == 5)
    {
        fighter = new Archer();
    } else if(c == 6)
    {
        fighter = new Assassin();
    } else if(c == 7)
    {
        fighter = new Mage();
    } else if(c == 8)
    {
        fighter = new Necromancer();
    }
}


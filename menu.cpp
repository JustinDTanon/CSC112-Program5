#include <iostream>
#include "menu.h"
#include "termmanip.h"
#include "widget.h"
#include "term.h"

using namespace std;

Menu::Menu() : Menu(1, 1)
{
    //Nothing here
}


Menu::Menu(int _x, int _y) : Widget(_x, _y, 90, 30)
{
    _cursor = 1;
    _running = true;
    counter = 0;
}


void Menu::display()
{
    if(counter == 0)
    {
        //Tell the player what to do. They have no choice
        cout << cursorPosition(36, 3) << underline << "Select Your Fighter" << normal;

        //Display the names of the fighters and highlight the one the player is looking at
        if(_cursor == 1)
        {
            cout << cursorPosition(9, 5) << reverseVideo << "1.) Warrior" << normal;
        } else
        {
            cout << cursorPosition(9, 5) << "1.) Warrior";
        }
        if(_cursor == 2)
        {
            cout << cursorPosition(9, 7) << reverseVideo << "2.) Paladin" << normal;
        } else
        {
            cout << cursorPosition(9, 7) << "2.) Paladin";
        }
        if(_cursor == 3)
        {
            cout << cursorPosition(9, 9) << reverseVideo << "3.) Berzerker" << normal;
        } else
        {
            cout << cursorPosition(9, 9) << "3.) Berzerker";
        }
        if(_cursor == 4)
        {
            cout << cursorPosition(9, 11) << reverseVideo << "4.) Monk" << normal;
        } else
        {
            cout << cursorPosition(9, 11) << "4.) Monk";
        }
        if(_cursor == 5)
        {
            cout << cursorPosition(9, 13) << reverseVideo << "5.) Archer" << normal;
        } else
        {
            cout << cursorPosition(9, 13) << "5.) Archer";
        }
        if(_cursor == 6)
        {
            cout << cursorPosition(9, 15) << reverseVideo << "6.) Assassin" << normal;
        } else
        {
            cout << cursorPosition(9, 15) << "6.) Assassin";
        }
        if(_cursor == 7)
        {
            cout << cursorPosition(9, 17) << reverseVideo << "7.) Mage" << normal;
        } else
        {
            cout << cursorPosition(9, 17) << "7.) Mage";
        }
        if(_cursor == 8)
        {
            cout << cursorPosition(9, 19) << reverseVideo << "8.) Necromancer" << normal;
        } else
        {
            cout << cursorPosition(9, 19) << "8.) Necromancer";
        }

        if(_cursor == 1) //The player is looking at the warrior
        {
            sword(); //Display the weapon of the fighter
            //Display the discription of the fighter
            cout << cursorPosition(9, 28) << "Basic, all-around fighter. Has the potential to be anything.                   ";

        } else if(_cursor == 2) //The player is looking at the paladin
        {
            shield(); //Display the weapon of the fighter
            //Display the discription of the fighter
            cout << cursorPosition(9, 28) << "A man with a strong shield and an even stronger will.                          "
                << cursorPosition(9, 29) << "He uses skills that can deflect attacks.                                       ";

        } else if(_cursor == 3) //The player is looking at the berzerker
        {
            axe(); //Display the weapon of the fighter
            //Display the discription of the fighter
            cout << cursorPosition(9, 28) << "The bloodthirsty mad man from your nightmares.                                 "
                << cursorPosition(9, 29) << "He specializes in melee combat with skills that buff his attacks.              ";

        } else if(_cursor == 4) //The player is looking at the monk
        {
            fist(); //Display the weapon of the fighter
            //Display the discription of the fighter
            cout << cursorPosition(9, 28) << "A bald head to distract you and two fists to punch you.                        "
                << cursorPosition(9, 29) << "His skills allow him to punch harder or heal.                                  ";

        } else if(_cursor == 5) //The player is looking at the archer
        {
            bow(); //Display the weapon of the fighter
            //Display the discription of the fighter
            cout << cursorPosition(9, 28) << "Fires arrows from afar using skills that improve his accuracy                  "
                << cursorPosition(9, 29) << "or add effects to his arrows.                                                  ";

        } else if(_cursor == 6) //The player is looking at the assassin
        {
            dagger(); //Display the weapon of the fighter
            //Display the discription of the fighter
            cout << cursorPosition(9, 28) << "From the shadows this sneaky lady will steal your life with critical strikes   "
                << cursorPosition(9, 29) << "then dissapear into thin air.                                                  ";

        } else if(_cursor == 7) //The player is looking at the mage
        {
            book(); //Display the weapon of the fighter
            //Display the discription of the fighter
            cout << cursorPosition(9, 28) << "A woman with a spell book that contains powerful spells                        "
                << cursorPosition(9, 29) << "for just about anything and everything.                                        ";

        } else if(_cursor == 8) //The player is looking at the necromancer
        {
            staff(); //Display the weapon of the fighter
            //Display the discription of the fighter
            cout << cursorPosition(9, 28) << "A summoner who uses dark magic to bring forth demons                           "
                << cursorPosition(9, 29) << "and steal health from his enemies.                                             ";

        }

        cout << cursorPosition(9, 26) << "Description:";
    } else
    {
        instructions();
    }
}


void Menu::handleEvent(Event *e)
{
    if(e->type() == "keyboard")
    {
        //we got a keyboard event!
        KeyboardEvent *kb = (KeyboardEvent *)e;  //cast to a kb event
        if(counter == 0)
        {
            if(kb->key() == UP)
            {
                if(_cursor != 1)
                {
                    _cursor--;
                }
            } else if(kb->key() == DOWN)
            {
                if(_cursor != 8)
                {
                    _cursor++;
                }
            }
        }
        if(kb->key() == ENTER)
        {
            counter++;
            if(counter == 2)
            {
                running(false);
            }
        }
    }
    
    display();
}


void Menu::sword() //Weapon for the warrior
{
    cout << cursorPosition(50, 5)  << "          .          " << endl
         << cursorPosition(50, 6)  << "         / \\        " << endl
         << cursorPosition(50, 7)  << "        |   |        " << endl
         << cursorPosition(50, 8)  << "        |   |        " << endl
         << cursorPosition(50, 9)  << "        |   |        " << endl
         << cursorPosition(50, 10) << "        |   |        " << endl
         << cursorPosition(50, 11) << "        |   |        " << endl
         << cursorPosition(50, 12) << "        |   |        " << endl
         << cursorPosition(50, 13) << "        |   |        " << endl
         << cursorPosition(50, 14) << "        |   |        " << endl
         << cursorPosition(50, 15) << "        |   |        " << endl
         << cursorPosition(50, 16) << "      __|___|__      " << endl
         << cursorPosition(50, 17) << "     [_________]     " << endl
         << cursorPosition(50, 18) << "         III         " << endl
         << cursorPosition(50, 19) << "         III         " << endl
         << cursorPosition(50, 20) << "         III         " << endl
         << cursorPosition(50, 21) << "         III         " << endl
         << cursorPosition(50, 22) << "        /   \\       " << endl
         << cursorPosition(50, 23) << "        \\___/       " << endl;
}


void Menu::shield() //Weapon for the paladin
{
    cout << cursorPosition(50, 5)  << "                       " << endl
         << cursorPosition(50, 6)  << "                       " << endl
         << cursorPosition(50, 7)  << "         _/\\_         " << endl
         << cursorPosition(50, 8)  << "  ______/ || \\______  " << endl
         << cursorPosition(50, 9)  << " |        ||        |  " << endl
         << cursorPosition(50, 10) << " |        ||        |  " << endl
         << cursorPosition(50, 11) << " |________||________|  " << endl
         << cursorPosition(50, 12) << " |________  ________|  " << endl
         << cursorPosition(50, 13) << " |        ||        |  " << endl
         << cursorPosition(50, 14) << " |        ||        |  " << endl
         << cursorPosition(50, 15) << "  \\       ||       /  " << endl
         << cursorPosition(50, 16) << "   \\      ||      /   " << endl
         << cursorPosition(50, 17) << "    \\_    ||    _/    " << endl
         << cursorPosition(50, 18) << "      \\_  ||  _/      " << endl
         << cursorPosition(50, 19) << "        \\_||_/        " << endl
         << cursorPosition(50, 20) << "          \\/          " << endl
         << cursorPosition(50, 21) << "                       " << endl
         << cursorPosition(50, 22) << "                       " << endl
         << cursorPosition(50, 23) << "                       " << endl;
}


void Menu::axe() //Weapon for the berzerker
{
    cout << cursorPosition(50, 5)  << "                          " << endl
         << cursorPosition(50, 6)  << "      _        _/\\       " << endl
         << cursorPosition(50, 7)  << "     | |    __/   \\      " << endl
         << cursorPosition(50, 8)  << "  ___| |___/       \\     " << endl
         << cursorPosition(50, 9)  << " /   | |            |     " << endl
         << cursorPosition(50, 10) << "<    | |            |     " << endl
         << cursorPosition(50, 11) << " \\___| |___         |    " << endl
         << cursorPosition(50, 12) << "     | |   \\__     /     " << endl
         << cursorPosition(50, 13) << "     | |      \\_  /      " << endl
         << cursorPosition(50, 14) << "     | |        \\/       " << endl
         << cursorPosition(50, 15) << "     | |                  " << endl
         << cursorPosition(50, 16) << "     | |                  " << endl
         << cursorPosition(50, 17) << "     | |                  " << endl
         << cursorPosition(50, 18) << "     | |                  " << endl
         << cursorPosition(50, 19) << "     | |                  " << endl
         << cursorPosition(50, 20) << "     | |                  " << endl
         << cursorPosition(50, 21) << "     | |                  " << endl
         << cursorPosition(50, 22) << "     |_|                  " << endl
         << cursorPosition(50, 23) << "                          " << endl;
}


void Menu::fist() //Weapon for the monk
{
    cout << cursorPosition(50, 5)  << "                       " << endl
         << cursorPosition(50, 6)  << "                       " << endl
         << cursorPosition(50, 7)  << "                       " << endl
         << cursorPosition(50, 8)  << "                       " << endl
         << cursorPosition(50, 9)  << "           ____        " << endl
         << cursorPosition(50, 10) << "      ____|    |____   " << endl
         << cursorPosition(50, 11) << "  ___|              |  " << endl
         << cursorPosition(50, 12) << " |        |    |    |  " << endl
         << cursorPosition(50, 13) << " |   |    |    |    |  " << endl
         << cursorPosition(50, 14) << " |   |    |    |    |  " << endl
         << cursorPosition(50, 15) << " |   |    |    |    |  " << endl
         << cursorPosition(50, 16) << " |___|    |    |    |  " << endl
         << cursorPosition(50, 17) << "     |____|    |____|  " << endl
         << cursorPosition(50, 18) << "          |____|   |   " << endl
         << cursorPosition(50, 19) << "           |_|_____|   " << endl
         << cursorPosition(50, 20) << "                       " << endl
         << cursorPosition(50, 21) << "                       " << endl
         << cursorPosition(50, 22) << "                       " << endl
         << cursorPosition(50, 23) << "                       " << endl;
}


void Menu::bow() //Weapon for the archer
{
    cout << cursorPosition(50, 5)  << "                         " << endl
         << cursorPosition(50, 6)  << "                         " << endl
         << cursorPosition(50, 7)  << "          .              " << endl
         << cursorPosition(50, 8)  << "          |\\            " << endl
         << cursorPosition(50, 9)  << "          | \\           " << endl
         << cursorPosition(50, 10) << "          |  \\          " << endl
         << cursorPosition(50, 11) << "          |   \\         " << endl
         << cursorPosition(50, 12) << "          |    \\        " << endl
         << cursorPosition(50, 13) << "   \\\\\\    |     |     " << endl
         << cursorPosition(50, 14) << "  --------|-----|--->    " << endl
         << cursorPosition(50, 15) << "   ///    |     |        " << endl
         << cursorPosition(50, 16) << "          |    /         " << endl
         << cursorPosition(50, 17) << "          |   /          " << endl
         << cursorPosition(50, 18) << "          |  /           " << endl
         << cursorPosition(50, 19) << "          | /            " << endl
         << cursorPosition(50, 20) << "          |/             " << endl
         << cursorPosition(50, 21) << "          '              " << endl
         << cursorPosition(50, 22) << "                         " << endl
         << cursorPosition(50, 23) << "                         " << endl;
}


void Menu::dagger() //Weapon for the assassin
{
    cout << cursorPosition(50, 5)  << "                       " << endl
         << cursorPosition(50, 6)  << "                       " << endl
         << cursorPosition(50, 7)  << "                       " << endl
         << cursorPosition(50, 8)  << "                       " << endl
         << cursorPosition(50, 9)  << "          .            " << endl
         << cursorPosition(50, 10) << "         III           " << endl
         << cursorPosition(50, 11) << "         III           " << endl
         << cursorPosition(50, 12) << "      \\__III___       " << endl
         << cursorPosition(50, 13) << "         | |   \\      " << endl
         << cursorPosition(50, 14) << "         | |           " << endl
         << cursorPosition(50, 15) << "         | |           " << endl
         << cursorPosition(50, 16) << "         | |           " << endl
         << cursorPosition(50, 17) << "         | |           " << endl
         << cursorPosition(50, 18) << "         | |           " << endl
         << cursorPosition(50, 19) << "          \\|          " << endl
         << cursorPosition(50, 20) << "           '           " << endl
         << cursorPosition(50, 21) << "                       " << endl
         << cursorPosition(50, 22) << "                       " << endl
         << cursorPosition(50, 23) << "                       " << endl;
}


void Menu::book() //Weapon for the mage
{
    cout << cursorPosition(50, 5)  << "                       " << endl
         << cursorPosition(50, 6)  << " ____________________  " << endl
         << cursorPosition(50, 7)  << "| |                  | " << endl
         << cursorPosition(50, 8)  << "| |                  | " << endl
         << cursorPosition(50, 9)  << "| |     --------     | " << endl
         << cursorPosition(50, 10) << "| |     -- --- -     | " << endl
         << cursorPosition(50, 11) << "| |     ---- ---     | " << endl
         << cursorPosition(50, 12) << "| |                  | " << endl
         << cursorPosition(50, 13) << "| |                  | " << endl
         << cursorPosition(50, 14) << "| |                  | " << endl
         << cursorPosition(50, 15) << "| |                  | " << endl
         << cursorPosition(50, 16) << "| |                  | " << endl
         << cursorPosition(50, 17) << "| |                  | " << endl
         << cursorPosition(50, 18) << "|_|__________________| " << endl
         << cursorPosition(50, 19) << "[==|  |==============| " << endl
         << cursorPosition(50, 20) << " ``|  |``````````````` " << endl
         << cursorPosition(50, 21) << "   |/\\|               " << endl
         << cursorPosition(50, 22) << "                       " << endl
         << cursorPosition(50, 23) << "                       " << endl;
}


void Menu::staff() //Weapon for the necromancer
{
    cout << cursorPosition(50, 5)  << "         ___             " << endl
         << cursorPosition(50, 6)  << "      / /   \\ \\        " << endl
         << cursorPosition(50, 7)  << "     |  \\___/  |        " << endl
         << cursorPosition(50, 8)  << "      \\___V___/         " << endl
         << cursorPosition(50, 9)  << "       |     |           " << endl
         << cursorPosition(50, 10) << "       |     |           " << endl
         << cursorPosition(50, 11) << "        \\   /           " << endl
         << cursorPosition(50, 12) << "         | |             " << endl
         << cursorPosition(50, 13) << "         | |             " << endl
         << cursorPosition(50, 14) << "         | |             " << endl
         << cursorPosition(50, 15) << "         | |             " << endl
         << cursorPosition(50, 16) << "         | |             " << endl
         << cursorPosition(50, 17) << "         | |             " << endl
         << cursorPosition(50, 18) << "         | |             " << endl
         << cursorPosition(50, 19) << "         | |             " << endl
         << cursorPosition(50, 20) << "          V              " << endl
         << cursorPosition(50, 21) << "          |              " << endl
         << cursorPosition(50, 22) << "          |              " << endl
         << cursorPosition(50, 23) << "                         " << endl;
}


int Menu::cursor()
{
    return _cursor;
}


void Menu::cursor(int c)
{
    _cursor = c;
}

void Menu::running(bool r)
{
    _running = r;
}


bool Menu::running()
{
    return _running;
}


void Menu::instructions()
{
    cout << cursorPosition(39, 3) << underline << "Instructions"
         << cursorPosition(35, 5) << "Go on a journey to kill all your enemies."
         << cursorPosition(35, 6) << "Eventually you will get to the enemy castle and fight their king."
         << cursorPosition(35, 7) << "By pressing 1, 2, 3, or 4 you will be able to attack, defend, or run away."
         << cursorPosition(35, 8) << "Running will end the program."
         << cursorPosition(35, 10) << "Press enter to start";
}


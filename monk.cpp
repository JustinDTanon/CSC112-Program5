#include <iostream>
#include "monk.h"

using namespace std;

Monk::Monk()
{
    hp = 0; //Hit points
    ad = 0; //Attack damage
    ap = 0; //Ability power
    dr = 1; //Damage reduction
    energy = 0; //Ability resource
}


Monk::~Monk()
{
    //Do nothing
}


void Monk::actionChoice()
{
    switch(actionValidate())
    {
        case 1:
            attack();
            break;
            
        case 2:
            defend();
            break;
            
        case 3:
            skillChoice();
            break;
            
        case 4:
            retreat();
            break;
    }
}


//Use the characters AD to determine damage done to enemy
void Monk::attack()
{
    _enemy -> takeDamage(ad);
    _enemy -> attack();
}


//Reduce damage taken from enemy and restore resource
void Monk::defend()
{
    dr /= 2;
    _enemy -> attack();
    dr *= 2;
    //Increase resource
}


void Monk::skillChoice()
{
    switch(abilityValidate())
    {
        case 1:
            skillOne();
            break;
            
        case 2:
            skillTwo();
            break;
            
        case 3:
            actionChoice();
            break;
    }
}


void Monk::retreat()
{
    //End the program
}



void Monk::skillOne()
{
    //Use character's first skill
}


void Monk::skillTwo()
{
    //Use character's second skkill
}


void Monk::takeDamage(int d)
{
    hp -= (d * dr);
    if(hp < 1)
    {
        //end program
    }
}


//Ask the player what they want to do then check whether the player's input is valid
int Monk::actionValidate()
{
    do //Make a loop to make sure that retrieved values are correct
    {
        cout << "What do you wish to do?" << endl //Give the player options
             << "1.) Attack" << endl
             << "2.) Defend" << endl
             << "3.) Ability" << endl
             << "4.) Retreat" << endl;
        cin >> int c;
        valid = bool (cin) && (c >=1 && c <=4); //Check the validity of the value that was received

        if (! valid) //If the value isn't valid then have the user put in another value
        {
            cout << "You made an invalid choice." << endl << endl;
            //Clear the error flags and skip the rest of the user's input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (! valid);
    return c;
}


//Ask the player what they want to do then check whether the player's input is valid
int Monk::abilityValidate()
{
    do //Make a loop to make sure that retrieved values are correct
    {
        cout << "What ability do you wish to use?" << endl //Give the player options
             << "1.) " << endl
             << "2.) " << endl
             << "3.) back" << endl;
        cin >> int c;
        valid = bool (cin) && (c == 1 || c == 2 || c == 3); //Check the validity of the value that was received

        if (! valid) //If the value isn't valid then have the user put in another value
        {
            cout << "You made an invalid choice." << endl << endl;
            //Clear the error flags and skip the rest of the user's input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (! valid);
    return c;
}
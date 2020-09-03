/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: Lobby class implementation file 
****************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include "lobby.hpp"
#include "inputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;

//************************************************************************
// Default constructor for Lobby					         
//************************************************************************
Lobby::Lobby()
{
    name = "Lobby";
}

//************************************************************************
// interact function for Lobby		         
//************************************************************************
void Lobby::interact(Player &user)
{
    showInstruction();

    randomSkillAdd(user);

    return;

}

//************************************************************************
// showInstruction shows instructions		         
//************************************************************************
void Lobby::showInstruction()
{
    cout << "\n>> This is your starting location!" << endl;
    cout << ">> Move to another room to start!" << endl;

    cout << "\n*Hint* you can sometimes add to your skills by interacting with random rooms" << endl;
    cout << "\n*Hint* your superficiality may affect the outcome ;)" << endl;
}


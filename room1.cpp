/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: Room1 class implementation file 
****************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include "room1.hpp"
#include "inputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;

//************************************************************************
// Room1 Constructor
//************************************************************************
Room1::Room1()
{
    name = "Room 1";
}

//************************************************************************
// swipe lets the player swipe to choose or go in blind into the date  
// is overridden due to the photo or secret skill add
//************************************************************************
bool Room1::swipe(Player &user)
{
    cout << "\nYou can choose to see their picture first or go straight into a blind date." << endl;
    cout << "\nPress 1 to see their picture first" << endl;
    cout << "Press 2 to go in blind" << endl;
    bool interact = false;
    bool valid = false;

    int swipeOrNot;

    //input validation
    do{
		swipeOrNot = intChosen(1,2);

		if(swipeOrNot <= 0 || swipeOrNot > 2)
		{
         	valid = false;
			std::cout << "Please enter a valid number" << std::endl;
		}
		else
		{
			valid = true;
		}
	}while(!valid);

    if(swipeOrNot == 1) //go in with a swipe, maybe exit based on what you see
    {
        cout << "____Photo____" << endl;
        cout << "\n(ღ˘⌣˘ღ)" << endl;
        cout << "\nEnter the room?" << endl;
        cout << "Press 1 for YES, 2 for NO" << endl;
        bool valid = false;
        int swipe;

        //input validation
        do{
			swipe = intChosen(1,2);

			if(swipe <= 0 || swipe > 2)
			{
         		valid = false;
				std::cout << "Please enter a valid number" << std::endl;
			}
			else
			{
				valid = true;
			}
		}while(!valid);
        
        if(swipe == 1)
        {
            didYouSwipe = true; 
            swipeYes = true;
            interact = true; 
        }
        else if(swipe == 2)
        {
            didYouSwipe = true; 
            swipeYes = false;
            interact = false;
        }
    }
    else if(swipeOrNot == 2) //go in blind
    {
        interact = true;
    }
    
    //reduce the room number count
    user.reduceMovementCount();

    return interact;
}

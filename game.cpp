/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: Game class implementation file 
**               This class constructs the new space objects and links the
**               spaces together. It then runs the player through the game
**               while there are enough confidence and rooms remaining.              
****************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "game.hpp"
#include "space.hpp"
#include "lobby.hpp"
#include "room1.hpp"
#include "room2.hpp"
#include "room3.hpp"
#include "room4.hpp"
#include "room5.hpp"
#include "inputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

//************************************************************************
// Default constructor of Game class
//************************************************************************
Game::Game()
{
	//create new objects
    lobby = new Lobby();
    room1 = new Room1();
    room2 = new Room2();
    room3 = new Room3();
    room4 = new Room4();
    room5 = new Room5();
    
    //set space links
    lobby->top = room3;
    lobby->bottom = NULL;
    lobby->left = room1;
    lobby->right = room5;

    room1->top = room2;
    room1->bottom = NULL;
    room1->left = NULL;
    room1->right = lobby;

    room2->top = NULL;
    room2->bottom = room1;
    room2->left = NULL;
    room2->right = room3;

    room3->top= NULL;
    room3->bottom = lobby;
    room3->left = room2;
    room3->right = room4;

    room4->top= NULL;
    room4->bottom = room5;
    room4->left = room3;
    room4->right= NULL;
    
    room5->top = room4;
    room5->bottom = NULL;
    room5->left = lobby;
    room5->right = NULL;

    //set starting location
    location = lobby;
    
}

//************************************************************************
// runGame runs the player through the game
//************************************************************************
void Game::runGame(Player &user)
{
    cout << "\n**********************************" << endl;
    cout << "Welcome to the Sort-of-Blind-Date!" << endl;
    cout << "**********************************" << endl;

    cout << "\nDating has become difficult in our increasingly superficial society." << endl;
    cout << "Here in the Sort-of-Blind-Date, you can take control and choose to be superficial or not!" << endl;

    cout << "\nHere at the dating venue, you must visit all 5 rooms." << endl;
    cout << "Before you go on the date, you can either choose to see their photo first and back out" << endl;
    cout << "or just go on a blind date!" << endl;

    cout << "\n1) Woo them while you interact and maybe use one of your skillsets" << endl;
    
    cout << "\n2) If you use a skill, it is removed from your skillset. However, you" << endl;
    cout << "   may pick up another skill by randomly by interacting in a room!" << endl;

    cout << "\n3) Based on how the dates go, your confidence might rise or fall..." << endl;

    cout << "\n4) Using dance skills guarantee you a date" << endl;
    
    cout << "\n   Your goal is to walk away from the venue with your confidence intact" << endl;
    cout << "   with at least one date set-up before you run out of rooms to visit!" << endl;

    cout << "\n5) If your confidence is zapped, you are kicked out from the venue!" << endl;

    cout << "\nGood luck!" << endl;


    //the game loops until confidence runs out or rooms remaining is zero
    while(user.hasConfidence() && user.getMovement() != 0)
    {   
        //print current location
        cout << "\n----------------------" << endl;
        cout << "Your location: " << location->getName() << endl;
        cout << "----------------------" << endl;
        
        //show rooms remaining and check if there are any dates lined up
        user.showMovementCount();
        user.checkFutureDate();
        
        //print confidence level
        cout << "\n----------------------" << endl;
        cout << "Confidence level: " << user.getConfidence() << endl;
        cout << "----------------------" << endl;
        
        int menuChoice;
        bool valid = false;

        cout << "\nChoose from the following:" << endl;
        cout << "1. Interact" << endl;
        cout << "2. See your skills" << endl;
        cout << "3. See the map" << endl;
        cout << "4. Move to another room" << endl;
        cout << "5. Quit" << endl;
        
        //input validation 
        do{
		
        menuChoice = intChosen(1,5);
		
		if(menuChoice <= 0 || menuChoice > 5)
        	{
         		valid = false;
				std::cout << "Please enter a valid number" << std::endl;
            }
        	else
        	{
            	valid = true;
        	}
        }while(!valid);  
    
        //menu choices start here
        if(menuChoice == 1)
        {
            location->interact(user); //interact with your blind date here 
                                      //once during interaction, decide whether to enter the room or not
                                      //use the items in your inventory during the interaction
        }
        else if(menuChoice ==2)
        {
            //see what kind of skills you have (such as jokes, dancing etc)
            user.printSkillSet(); 
        }
        else if(menuChoice == 3)
        {
            //print your location on a map
            printMap(); 
        }
        else if(menuChoice == 4)
        {
            //allow player to move to another space
            location = moveSpace(); 
        }
        //quits the game by setting confidence to zero
        else if(menuChoice == 5)
        {
            user.setConfidence();
            cout << "\n**********************************" << endl;
            cout << "Sorry you don't want to continue!" << endl;
            cout << "**********************************" << endl;
        }
        
        //check if movement possible, if zero then quits the game while showing whether you have any dates
        if(user.getMovement() == 0)
        {
            cout << "\n**********************************" << endl;            
            cout << "You ran out of rooms to visit!" << endl;
            cout << "**********************************" << endl;
            cout << "" << endl;
            user.checkFutureDate();
            user.dateCheck();
        }

        //check confidence level, if zero then quit
        if(user.getConfidence() == 0)
        {
            cout << "\n*******************************" << endl;
            cout << "Sorry your confidence ran out!" << endl;
            cout << "*******************************" << endl;
            cout << "\n>> Game over! " << endl;
        }
    }
    
    cout << "\n>> Thanks for trying! Try again soon!" << endl;
    
    return;
}

//************************************************************************
// moveSpace helps the player move to another space
//************************************************************************
Space* Game::moveSpace()
{
    cout << "\nChoose a room..." << endl;
    int choice;
    bool valid = false;
    
    //provides a menu based on the linked spaces and their relative locations
    if(location->top != NULL)
    {
        cout << "1. " << location->top->getName() << endl;
    }
    else
    {
        cout << "1. No access" << endl; //because the pointer points to null, access is not possible
    }
    if(location->bottom != NULL)
    {
        cout << "2. " << location->bottom->getName() << endl;
    }
    else
    {
        cout << "2. No access" << endl;
    }
    if(location->left != NULL)
    {
        cout << "3. " << location->left->getName() << endl;
    }
    else
    {
        cout << "3. No access" << endl;
    }
    if(location->right != NULL)
    {
        cout << "4. " << location->right->getName() << endl;
    }
    else
    {
        cout << "4. No access" << endl;
    }
    
    do
    {
	    choice = intChosen(1,4);
		
		if(choice < 1 || choice > 4)
        {
         	valid = false;
			std::cout << "Please enter a valid number" << std::endl;
        }
        else
        {
            valid = true;
        }
    }while(!valid);  
    
    if (choice == 1)
    {
        if(location->top == NULL)
        {
            cout << "\n>> There is no room there... try again" << endl;
            return location;
        }
        else
        {
            return location->top;
        }
    }
    else if(choice == 2)
    {
        if(location->bottom == NULL)
        {
            cout << "\n>> There is no room there... try again" << endl;
            return location;
        }
        else
        {
            return location->bottom;
        }
    }    
    else if(choice == 3)
    {
        if(location->left == NULL)
        {
            cout << "\n>> There is no room there... try again" << endl;
            return location;
        }
        else
        {
            return location->left;
        }
    }   
    else if(choice == 4)
    {
        if(location->right == NULL)
        {
            cout << "\n>> There is no room there... try again" << endl;
            return location;
        }
        else
        {
            return location->right;
        }
    }   

}

//************************************************************************
// printMap prints the map and the current location
//************************************************************************
void Game::printMap()
{
    if(location->getName() == "Lobby")
	{
		cout << " _______________ _______________ _______________" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|    Room 2     |    Room 3     |     Room 4    |" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|_______________|_______________|_______________|" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|    Room 1     |    Lobby      |     Room 5    |" << endl;
		cout << "|               |      X        |               |" << endl;
		cout << "|_______________|_______________|_______________|" << endl;
	}
    else if(location->getName() == "Room 1")
    { 
    	cout << " _______________ _______________ _______________" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|    Room 2     |    Room 3     |     Room 4    |" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|_______________|_______________|_______________|" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|    Room 1     |    Lobby      |     Room 5    |" << endl;
		cout << "|       X       |               |               |" << endl;
		cout << "|_______________|_______________|_______________|" << endl;
    }
    else if(location->getName() == "Room 2") 
    {
        cout << " _______________ _______________ _______________" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|    Room 2     |    Room 3     |     Room 4    |" << endl;
		cout << "|       X       |               |               |" << endl;
		cout << "|_______________|_______________|_______________|" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|    Room 1     |    Lobby      |     Room 5    |" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|_______________|_______________|_______________|" << endl;
    }
    else if(location->getName() == "Room 3") 
    {
        cout << " _______________ _______________ _______________" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|    Room 2     |    Room 3     |     Room 4    |" << endl;
		cout << "|               |       X       |               |" << endl;
		cout << "|_______________|_______________|_______________|" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|    Room 1     |    Lobby      |     Room 5    |" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|_______________|_______________|_______________|" << endl;
    }
    else if(location->getName() == "Room 4") 
    {
        cout << " _______________ _______________ _______________" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|    Room 2     |    Room 3     |     Room 4    |" << endl;
		cout << "|               |               |       X       |" << endl;
		cout << "|_______________|_______________|_______________|" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|    Room 1     |    Lobby      |     Room 5    |" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|_______________|_______________|_______________|" << endl;
    }
    else if(location->getName() == "Room 5") 
    {
        cout << " _______________ _______________ _______________" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|    Room 2     |    Room 3     |     Room 4    |" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|_______________|_______________|_______________|" << endl;
		cout << "|               |               |               |" << endl;
		cout << "|    Room 1     |    Lobby      |     Room 5    |" << endl;
		cout << "|               |               |        X      |" << endl;
		cout << "|_______________|_______________|_______________|" << endl;
    }
}

//************************************************************************
// Deconstructor
//************************************************************************
Game::~Game()
{
    delete lobby;
    delete room1;
    delete room2;
    delete room3;
    delete room4;
    delete room5;
}
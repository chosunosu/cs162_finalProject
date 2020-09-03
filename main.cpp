/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: main.cpp implementation file 
****************************************************************************/

#include "game.hpp"
#include "inputValidation.hpp"

int main()
{
    int testdriverOver = 1;

    std::cout << "\nCS162 Fall 2018 Final Project" << std::endl;

	std::cout << "\nWould you like to" << std::endl;
	std::cout << "1. Play" << std::endl;
	std::cout << "2. Exit" << std::endl;

    std::cout << "\nEnter your choice..." << std::endl;
	bool valid = false;

	int gameStart;

	do{
			gameStart = intChosen(1,2);

			if(gameStart <= 0 || gameStart > 2)
			{
         		valid = false;
				std::cout << "Please enter a valid number" << std::endl;
			}
			else
			{
				valid = true;
			}
		}while(!valid);

	if(gameStart ==1)
	{
		do{
        Player user;
        Game game;

        game.runGame(user);

		std::cout << "\nWould you like to" << std::endl;
		std::cout << "1. Play again" << std::endl;
		std::cout << "2. Exit" << std::endl;

		std::cout << "\nEnter your choice..." << std::endl;
		bool valid = false;
		int endMenu;

		do{
			endMenu = intChosen(1,2);

			if(endMenu <= 0 || endMenu > 2)
			{
         		valid = false;
				std::cout << "Please enter a valid number" << std::endl;
			}
			else
			{
				valid = true;
			}
		}while(!valid);
		
		if(endMenu == 1)
			{
				testdriverOver = false;
			}
		else if(endMenu == 2)
			{
				testdriverOver = true;
			}
		
		}while(!testdriverOver);
	}

    return 0;
}
/********************************************************************************
** Program: inputValidation.cpp
** Author: Sunghoon Cho
** Date: 10/16/18
** Description: This is the class implementation file for the input validation class.
**              It uses validation by checking for digits after using get.line.             
**********************************************************************************/

#include "inputValidation.hpp"

#include <iostream>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <random>


/********************************************************************************
** The getUserInput function validates input of integers between min and max
** specified. 
**********************************************************************************/
int intChosen(int min, int max)
{
    int integer = 0;
    std::string userInput; 

    while(1)
    {
        do
        {
            std::getline(std::cin, userInput); //get user input
        }while(userInput == "");

        std::stringstream ss(userInput);   //store input as ss object

       //check if every thing is a digit
        bool digitCheck = true;
        for (unsigned int nIndex=0; nIndex < userInput.length(); nIndex++)
            if (!isdigit(userInput[nIndex]))
            {
                std::cout << "Please enter a valid number" << std::endl;
                digitCheck = false;
                break;
            }
        if (!digitCheck)
        {
        continue;
        }
        
        std::stringstream strStream; //use stringstream to convert to a digit
        strStream << userInput;
        strStream >> integer;
        
        break;
    }
    
    return integer;
}

/********************************************************************************
** The getUserInput function validates input of integers between min and max
** specified. Found at stackoverflow 19728404
**********************************************************************************/
int randomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min,max);
    auto random_integer = uni(rng);
    return random_integer;
}


/********************************************************************************
** The getUserInput function validates input of integers between min and max
** specified. 
**********************************************************************************/
bool numberBool()
{
    int integer;
    std::string userInput;

    while(1)
    {
        std::getline(std::cin, userInput); 
        std::stringstream ss(userInput); 

        bool digitCheck = true;
        for(unsigned int nIndex=0; nIndex < userInput.length(); nIndex++)
            if(!isdigit(userInput[nIndex]))
            {
                std::cout << "Please enter 1 or 2" << std::endl;
                digitCheck = false;
                break;
            }
        if(!digitCheck)
            continue;
    

        std::stringstream strStream;
        strStream << userInput;
        strStream >> integer;
 
        if(integer == 0) // make sure user chooses either 1 or 2 at beginning
            return true;
		else if(integer == 1)
            return false;
        }
    }


/********************************************************************************
** The getUserInput function validates input of integers between min and max
** specified. 
**********************************************************************************/
int checkOneTwo(int)
{
    int integercheck = 0;
    std::string userInput; 

    do
    {
        std::getline(std::cin, userInput); //get user input
        std::stringstream ss(userInput);   //store input as ss object

       //check if every thing is a digit
        bool digitCheck = true;
        for (unsigned int nIndex=0; nIndex < userInput.length(); nIndex++)
            if (!isdigit(userInput[nIndex]))
            {
                std::cout << "Please enter a valid number" << std::endl;
                digitCheck = false;
                break;
            }
        if (!digitCheck)
        {
        continue;
        }
        
        std::stringstream strStream; //use stringstream to convert to a digit
        strStream << userInput;
        strStream >> integercheck;
        
        break;

    }while(integercheck != 1 && integercheck != 2);
    
    return integercheck;
}
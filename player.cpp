/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18
** Program name: Player class  
****************************************************************************/

#include "player.hpp"
#include "inputValidation.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;

//************************************************************************
// Default constructor for Player class
//************************************************************************
Player::Player()
{
    confidence = 100;
    haveDate = 0;
    movementCount = 5;
}


//************************************************************************
// hasConfidence checks whether player still has any confidence
//************************************************************************
bool Player::hasConfidence()
{
    if(confidence > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//************************************************************************
// printInventory prints the list of skills the player has
//************************************************************************
void Player::printSkillSet()
{
    if(skillSet.empty())
    {
        cout << "\n>> Your skillset is empty!" << endl;
        cout << "\n>> Hint: interact with the lobby to learn a skill!" << endl;
    }
    else
    {
        cout << "\n>> Here are your current skills" << endl;

        for (int i = 0; i < skillSet.size(); i++)
        {
            cout << "   " << i+1 << ". " << skillSet[i] << endl;
        }
    }
    return;
}


//************************************************************************
// getConfidence returns confidence level
//************************************************************************
int Player::getConfidence()
{
    return confidence;
}


//************************************************************************
// addSkill adds any skills picked up during the date
//************************************************************************
void Player::addSkill(string skill)
{
    if(skillSet.size() < 5)
    {
        //skill is added to skillset
        skillSet.push_back(skill);
    }
    else
    {
        cout << "\n>> You cannot have any more skills" << endl;
    }
}


//************************************************************************
// setConfidence is a game kill function by setting confidence to 0
//************************************************************************
void Player::setConfidence()
{
    confidence = 0;
}

//************************************************************************
// getaDate tracks whether the player gets any dates lined up
//************************************************************************
void Player::getaDate()
{
    haveDate = haveDate + 1;
}


//************************************************************************
// dateCheck outputs two statements based on the quantity of dates lined up
//************************************************************************
void Player::dateCheck()
{
    if(haveDate > 0)
    {
        cout << "\n>> Good job! You won the game!" << endl;
    }
    else
    {
        cout << "\n>> Sorry you lost the game" << endl;
    }
}


//************************************************************************
// checkFutureDate is the final output after checking room count
//************************************************************************
void Player::checkFutureDate()
{
    if(haveDate > 0)
    {
        cout << "You currently have " << haveDate << " date(s) for the future" << endl;
    }
    else
    {
        cout << "You have no future dates lined up." << endl;
    }
}

//************************************************************************
// searchSkill searches for a skill to be used during date when available 
//************************************************************************
bool Player::searchSkill(string skill)
{
	for (int i = 0; i < skillSet.size(); i++) 
	{
		if(skillSet[i] == skill) 
		{
			return true; 
		}
	}
    return false;
}


//************************************************************************
// loseConfidence subtracts an int from the confidence depending on date
//************************************************************************
void Player::loseConfidence(int number)
{
	confidence -= number;
}


//************************************************************************
// loseConfidence adds an int to the confidence depending on date
//************************************************************************
void Player::gainConfidence(int number)
{
	confidence += number;
}


//************************************************************************
// removeSkill removes any skills that are used during the date
//************************************************************************
void Player::removeSkill(string skill)
{
	for (int i = 0; i < skillSet.size(); i++) 
	{
		if (skillSet[i] == skill) 
		{
			skillSet.erase(skillSet.begin() + i); 
			
            return;
		}
	}

	return;
}


//************************************************************************
// reduceMovementCount reduces the number of rooms that can be visited
//************************************************************************
void Player::reduceMovementCount()
{
    movementCount = movementCount-1;
}


//************************************************************************
// showMovementCount shows the number of rooms that can be visited
//************************************************************************
void Player::showMovementCount()
{
    cout << "\nYou have " << movementCount << " remaining rooms to visit" << endl;
}


//************************************************************************
// getMovement returns the int movementCount
//************************************************************************
int Player::getMovement()
{
    return movementCount;
}
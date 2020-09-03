/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: Space class implementation file contains the functions 
**              necessary to act in each space. It is an abstract class 
**              with pure virtual functions to help actions take place.
****************************************************************************/

#include <iostream>
#include <string>
#include "space.hpp"
#include "inputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;

//************************************************************************
// Default constructor for Space					         
//************************************************************************
Space::Space()
{
    top = NULL;
    bottom = NULL;
    left = NULL;
    right = NULL;
}

//************************************************************************
// getName reutnrs the name of the space
//************************************************************************
std::string Space::getName()
{
    return name;
}

//************************************************************************
// swipe lets the player swipe to choose or go in blind into the date      
//************************************************************************
bool Space::swipe(Player &user)
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

        //choose to swipe or not
        if(swipe == 1)
        {
            //check whether you swiped
            didYouSwipe = true; 
            //check whether you said yes or no
            swipeYes = true;
            //check whether you decided to interact once you saw the photo
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

    return interact;
}


//************************************************************************
// interact function lets the player interact with the date
//************************************************************************
void Space::interact(Player &user)
{
    if(!beenHere) //have you been here? have you been on a date? if not then
    {
        if(!didYouSwipe) //did you swipe? if not then
        {
            interaction = swipe(user); //do you swipe? do you go in blind?
            if(interaction) //lets swipe or not but decide if you want to continue
            {
                beenHere = true; //book changed to yes for future checks
                date = true;
                //start your date here
                cout << "\n>> You are on your date" << endl;
                beginDate(user);
            }
            else if(!interaction) //you didn't like what you saw and you left the room
            {
                beenHere = true;
                cout << "\n>> You didn't like what you saw and you left" << endl;
                cout << "\n>> You've been penalized for your superficial decisionmaking" << endl;
                user.loseConfidence(25);
            }
        }
    }
    //if you've been to the room already, you swiped, and did not swipe Yes 
    else if(beenHere && !swipeYes && didYouSwipe)    
    {
        cout << "\n>> The person you said NO to has left. Nothing here for you!" << endl;
    }
    else
    {
        cout << "\n>> You've been here and already interacted" << endl;
    }       

    return;

}


//************************************************************************
// saySomething is a function that says something to the date when
// you lack any other skills to use on the date.
//************************************************************************
void Space::saySomething(Player &user)
{
    cout << "\n>> You said something to your date" << endl;
    
    int impressed = randomInt(1,10);
    
    if(impressed > 5)
    {
        cout << "\n>> Your date was not impressed" << endl;
        user.loseConfidence(10);
    }
    else
    {
        cout << "\n>> Your date was impressed" << endl;
        user.gainConfidence(5);
    }
}


//************************************************************************
// beginDate is the actual date if it happens
//************************************************************************
void Space::beginDate(Player &user)
{
    cout << "\n>> You have four chances to do something with your date" << endl;
    cout << ">> If you have a skill, it will be used randomly" << endl;
    cout << ">> The outcome of your date will determine your confidence level" << endl;
    
    int impressed;
    bool dance =false;
    //four interactions with your dates
    for (int i = 0; i < 4; i++)
    {
        //use skill based on likelihood of 25% and whether the skill exists or not
        //however if you have the dance skill, that guarantees a date
        //and you basically win the game early
        int useSkill = randomInt(1,4);

        if(user.searchSkill("dance"))
            {
                user.removeSkill("dance");
                cout << "\n>> You danced for your date" << endl;
                cout << "\n>> Your date was impressed" << endl;
                user.getaDate();
                cout << "   Your dance won her over. You secured a future date!" << endl;
                user.gainConfidence(15);
                dance = true;
            }
        //25 percent chance the user sings or jokes if available, if not then just says something
        else if(useSkill == 1)
        {
            if(user.searchSkill("sing"))
            {
                user.removeSkill("sing");
                cout << "\n>> You sang to your date" << endl;
                impressed = randomInt(1,10);
                if(impressed > 3)
                {
                    cout << "\n>> Your date was not impressed" << endl;
                    user.loseConfidence(15);
                }
                else
                {
                    cout << "\n>> Your date was impressed" << endl;
                    user.gainConfidence(10);
                }
            }
            else if(user.searchSkill("joke"))
            {
                user.removeSkill("joke");
                cout << "\n>> You made a joke to your date" << endl;
                impressed = randomInt(1,10);
                if(impressed > 5)
                {
                    cout << "\n>> Your date was not impressed" << endl;
                    user.loseConfidence(10);
                }
                else
                {
                    cout << "\n>> Your date was impressed" << endl;
                    user.gainConfidence(5);
                }
            }
            else
            {
                saySomething(user);
            }
        }
        //25 percent chance the user compliments or talks politics if available, if not then just says something
        else if(useSkill == 2)
        {
            if(user.searchSkill("compliment"))
            {
                user.removeSkill("compliment");
                cout << "\n>> You complimented your date" << endl;
                impressed = randomInt(1,10);
                if(impressed > 5)
                {
                    cout << "\n>> Your date was not impressed" << endl;
                    user.loseConfidence(15);
                }
                else
                {
                    cout << "\n>> Your date was impressed" << endl;
                    user.gainConfidence(10);
                }
            }
            else if(user.searchSkill("politics"))
            {
                user.removeSkill("politics");
                cout << "\n>> You talked about politics to your date" << endl;
                impressed = randomInt(1,10);
                if(impressed > 7)
                {
                    cout << "\n>> Your date was not impressed" << endl;
                    user.loseConfidence(25);
                }
                else
                {
                    cout << "\n>> Your date was impressed" << endl;
                    user.gainConfidence(20);
                }
            }
            else
            {
                saySomething(user);
            }   
        }
        //25 percent chance the user gifts if available, if not then just says something
        else if(useSkill == 3)
        {
            if(user.searchSkill("gift"))
            {
                user.removeSkill("gift");
                cout << "\n>> You gave a gift to your date" << endl;
                impressed = randomInt(1,10);
                if(impressed > 7)
                {
                    cout << "\n>> Your date was not impressed" << endl;
                    user.loseConfidence(15);
                }
                else
                {
                    cout << "\n>> Your date was impressed" << endl;
                    user.gainConfidence(10);
                }
            }
            else
            {
                saySomething(user);
            }
        }
        //25 percent chance the user just says something
        else
        {
            saySomething(user);
        }
        
    }

    int futureDate = randomInt(1,10);
    //there is a 30% chance whether you might get a next date lined up
    //regardless of your interaction
    if(futureDate > 7)
    {
        cout << "\n>> Hmm, I guess the date went well? You've got another date in the future!" << endl;
        user.getaDate();
    }
    else if(futureDate <= 7 && dance)
    {
        cout << "\n>> Hmm, well regardless of your date after your dance, you've got a date lined up!" << endl;
    }
    else if(futureDate <= 7 && !dance)
    {
        cout << "\n>> Hmm, I guess the date didn't go well. You went your separate ways." << endl;
    }

}

//************************************************************************
// randomSkillAdd randomly adds skills in room where function is placed
//************************************************************************
void Space::randomSkillAdd(Player &user)
{
    //about a 50% chance that a random skill is picked up during interaction
    int addSkill = randomInt(1,11);
    if (addSkill == 1)
    {
        if(!user.searchSkill("sing"))
        {
            user.addSkill("sing");
        }
    }
    else if (addSkill == 3)
    {
        if(!user.searchSkill("joke"))
        {
            user.addSkill("joke");
        }
    }
    else if (addSkill == 5)
    {
        if(!user.searchSkill("compliment"))
        {
            user.addSkill("compliment");
        }
    }    
    else if (addSkill == 7)
    {
        if(!user.searchSkill("politics"))
        {
            user.addSkill("politics");
        }
    }
    else if (addSkill == 9)
    {
        if(!user.searchSkill("dance"))
        {
            user.addSkill("dance");
        }
    }    
    else if (addSkill == 11)
    {
        if(!user.searchSkill("gift"))
        {
            user.addSkill("gift");
        }
    }
}

//************************************************************************
// Deconstructor
//************************************************************************
Space::~Space()
{
}
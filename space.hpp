/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: Space class header file 
****************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "player.hpp"

class Space{
    
    public:
        Space();
        virtual ~Space() = 0; //deconstructor is pure virtual function
        virtual std::string getName();
        virtual void interact(Player &user);
        virtual void beginDate(Player &user);
        virtual bool swipe(Player &user);
        virtual void saySomething(Player &user);
        virtual void randomSkillAdd(Player &user);
        
        Space* top;
        Space* bottom;
        Space* left;
        Space* right;

    protected:
        std::string name;
        bool interaction = false;
        bool beenHere = false;
        bool didYouSwipe = false;
        bool date = false;
        bool swipeYes = false;


};

#endif
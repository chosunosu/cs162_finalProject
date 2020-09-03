/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: Room3 class header file 
****************************************************************************/

#ifndef ROOM3_HPP
#define ROOM3_HPP
#include "space.hpp"

class Room3 : public Space{
    
    public: 
        Room3();
        //virtual void interact(Player &user);
        bool swipe(Player &user);
        //virtual void beginDate(Player &user);


    private:
        /*
        bool interaction = false;
        bool beenHere = false;
        bool didYouSwipe = false;
        bool date = false;
        bool swipeYes = false;
        */
};

#endif
/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: Room1 class header file 
****************************************************************************/

#ifndef ROOM1_HPP
#define ROOM1_HPP
#include "space.hpp"

class Room1 : public Space{
    
    public: 
        Room1();
        //void interact(Player &user);
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
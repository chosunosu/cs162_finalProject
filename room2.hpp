/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: Room2 class header file 
****************************************************************************/

#ifndef ROOM2_HPP
#define ROOM2_HPP
#include "space.hpp"

class Room2 : public Space{
    
    public: 
        Room2();
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
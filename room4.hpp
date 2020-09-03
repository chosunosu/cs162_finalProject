/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: Room4 class header file 
****************************************************************************/

#ifndef ROOM4_HPP
#define ROOM4_HPP
#include "space.hpp"

class Room4 : public Space{
    
    public: 
        Room4();
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
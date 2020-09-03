/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: Room5 class header file 
****************************************************************************/

#ifndef ROOM5_HPP
#define ROOM5_HPP
#include "space.hpp"

class Room5 : public Space{
    
    public: 
        Room5();
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
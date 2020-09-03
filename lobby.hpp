/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: Lobby class header file 
****************************************************************************/

#ifndef LOBBY_HPP
#define LOBBY_HPP
#include "space.hpp"

class Lobby : public Space{
    
    public: 
        Lobby();
        void interact(Player &user);
        void showInstruction();

    private:
        //bool interaction = false;
        //bool beenHere = false;
        //bool didYouSwipe = false;
        //bool date = false;
        //bool swipeYes = false;
    

};

#endif
/***************************************************************************
** Author: Sunghoon Cho
** Date: 12/4/18	
** Program name: Game class header file 
****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "space.hpp"
#include <vector>

class Game{
    
    public: 
        Game();
        ~Game();
        void runGame(Player &user);
        Space* moveSpace();
        void printMap();
        
    private:
        Space* lobby;
        Space* room1;
        Space* room2;
        Space* room3;
        Space* room4;
        Space* room5;
        Space* location;

        std::vector<int> skills;
        
};

#endif
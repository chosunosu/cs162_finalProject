#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Player{

    public:
        Player();
        bool hasConfidence();
        void printSkillSet();
        int getConfidence();
        void addSkill(string skill);
        void removeSkill(string skill);
        void setConfidence();
        bool searchSkill(string skill);
        void loseConfidence(int number);
        void gainConfidence(int number);
        void getaDate();
        void checkFutureDate();
        void reduceMovementCount();
        void showMovementCount();
        int getMovement();
        void dateCheck();


    private:
        int confidence;
        int haveDate;
        int movementCount;
        vector<string> skillSet;
};

#endif
//
// Created by Taekyoung Kim on 2019-03-05.
//

#ifndef FP_CHARACTER_H
#define FP_CHARACTER_H
#include <iostream>
#include "Space.h"
class Space;

class Character {

private:

    std::string cName = "";
    int strength = 0;
    int count = 0;
    Space *locate;

public:

    Character();
    ~Character();
    Character(std::string na, int s, int ct);
    std::string getCName();
    void setCName(std::string cNa);
    int getStrength();
    void setStrength(int s);
    int getCount();
    void setCount(int ct);
    Space *getLocate();
    void setLocate(Space *room);
    bool gotUSB = false;
};


#endif //FP_CHARACTER_H

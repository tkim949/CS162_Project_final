//
// Created by Taekyoung Kim on 2019-03-05.
//

#ifndef FP_CHARACTER_H
#define FP_CHARACTER_H
#include <iostream>
#include "Space.h"
#include "Inventory.h"
class Space;
class Inventory;

class Character {

private:

    std::string cName = "";
    int strength = 0;
    Space *locate;
    bool hasUSB = false;

public:

    Character();
    ~Character();
    Character(std::string na, int s);
    std::string getCName();
    void setCName(std::string cNa);
    int getStrength();
    void setStrength(int s);
    Space *getLocate();
    void setLocate(Space *room);
    bool getHasUSB();
    void setHasUSB(bool usb);

};


#endif //FP_CHARACTER_H

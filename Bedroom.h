/****************************************************************************************************
 * * Program name: CS162 Final Project
 * * Author: Taekyoung Kim
 * * Date: 03/03/2019
 * * Description: This is Bedroom.h file for CS162 Final Project
 * * This project implements text-based game.
 * * A user(you) need to find a USB that has financial info of his deceased father.
 * * There are total 7 rooms in the house and 5 of them might have the USB.
 * * And each room has three places that the USB might be.
 * * Also, there is an obstacles, his/her step mother and brother.
 * * If the user ran into them, he might lose his strength or jewelry.
 * * User has a container and its capacity is 3, but he/she needs to keep the PASSWORD for the usb,
 * * actual capacity would be 2. Users can find jewelry in the house and keep and use it.
 * * Users can search for a room one at a time, and he has 15 turns to change rooms.
 * * The last two rooms of 7 are the places for user to rest and get a chance to have something good.
 ******************************************************************************************************/


#ifndef FP_BEDROOM_H
#define FP_BEDROOM_H
#include "Space.h"
#include "Character.h"

class Bedroom :
        public Space
{

private:

public:
    Bedroom();
    ~Bedroom() override;
    void description(Character *cha, int hiddenP) override;
    void print() override;

};


#endif //FP_BEDROOM_H

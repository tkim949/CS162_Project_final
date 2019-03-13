/****************************************************************************************************
 * * Program name: CS162 Final Project
 * * Author: Taekyoung Kim
 * * Date: 03/03/2019
 * * Description: This is Space.h file for CS162 Final Project
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


#ifndef FP_SPACE_H
#define FP_SPACE_H
#include <iostream>
#include "Character.h"
class Character;

class Space {

protected:
    std::string sName;
    Space *top = nullptr;
    Space *right = nullptr;
    Space *left = nullptr;
    Space *bottom = nullptr;
    bool isUSB = false;
    bool isItem = false;
    bool doneF = false;
    bool doneS = false;
    bool doneT = false;


public:
    Space();
    virtual ~Space();
    Space* getTop();
    Space* getBottom();
    Space* getRight();
    Space* getLeft();
    virtual std::string getName() const;
    virtual void setTop(Space *ptr);
    virtual void setBottom(Space *ptr);
    virtual void setRight(Space *ptr);
    virtual void setLeft(Space *ptr);
    virtual void setName(std::string na);
    virtual void description(Character *cha, int num) = 0; //This makes it abstract
    virtual bool getIsUSB();
    virtual void setIsUSB(bool usb);
    virtual bool getIsItem();
    virtual void setIsItem(bool item);

    virtual bool getDoneF();
    virtual void setDoneF(bool dF);

    virtual bool getDoneS();
    virtual void setDoneS(bool dS);

    virtual bool getDoneT();
    virtual void setDoneT(bool dT);


};


#endif //FP_SPACE_H

/****************************************************************************************************
 * * Program name: CS162 Final Project
 * * Author: Taekyoung Kim
 * * Date: 03/03/2019
 * * Description: This is Inventory.h file for CS162 Final Project
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


#ifndef FP_INVENTORY_H
#define FP_INVENTORY_H
#include <iostream>
#include <stack>


class Inventory {


private:

    const int LIMIT = 3;
    std::stack<std::string> myString;

public:

    Inventory();
    ~Inventory();
    void addItem(std::string s);
    void removeItem();
    void print(std::stack<std::string> mySt);
    int count();
    void hasLast();
    void showItem();
    void writeList(std::string s);
    void clear();

};


#endif //FP_INVENTORY_H

/****************************************************************************************************
 * * Program name: CS162 Final Project
 * * Author: Taekyoung Kim
 * * Date: 03/03/2019
 * * Description: This is Restroom.cpp file for CS162 Final Project
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


#include "Restroom.h"
#include <iostream>
#include "helper.h"
#include <climits>

//constructor
Restroom::Restroom() = default;
//destructor
Restroom::~Restroom() = default;

/********************************************************************************
 * * This description function is different from othe rooms because this room
 * * doesn't have USB, but it has other options, which is using random number.
 * * @param cha, @param num
 ********************************************************************************/

void Restroom::description(Character *cha, int num) {

    int restCh = randomNum(3);
    int getPower = randomNum(3);

    //std::cout<<"Is there the USB here: "<<getIsUSB()<<std::endl;
    //std::cout<<"The random number for search place: "<<restCh<<std::endl;

    std::cout<<"\nThis room is a restroom that you can take a rest and think where to go what todo."<<std::endl;
    std::cout<<"Also you can get some good stuff here."<<std::endl;
    std::cout<<"What is waiting for you? Let's check!\n\n"<<std::endl;
    //std::cin.clear();
   // std::cin.ignore(INT_MAX, '\n');
    //std::cout << "\nPress ENTER to Continue....\n";
    //std::cin.get();

    if(restCh == 1){
        std::cout<<"You took a good rest and got strength "<<getPower<<" It's great!"<<std::endl;
        cha->setStrength(cha->getStrength() + getPower);
    }
    else if(restCh == 2){
        std::cout<<"Oh Here is OPAL. You're lucky this time."<<std::endl;
        setIsItem(true);
    }
    else if(restCh == 3) {
        std::cout<<"Oh, this time you got blessing but the pot is empty. Sorry! "<<std::endl;
    }

}
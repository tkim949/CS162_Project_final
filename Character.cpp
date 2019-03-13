/****************************************************************************************************
 * * Program name: CS162 Final Project
 * * Author: Taekyoung Kim
 * * Date: 03/03/2019
 * * Description: This is Character.cpp file for CS162 Final Project
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


#include "Character.h"
#include <iostream>
#include "Space.h"

//constructor
Character::Character() = default;
//destructor
Character::~Character() = default;

//constructor with two parameter
Character::Character(std::string na, int s) {

    this->cName = na;
    this->strength = s;

}

//Accessor for character name
std::string Character::getCName(){

    return this->cName;
}

//Modifier for character name
void Character::setCName(std::string cNa){
    cName = cNa;
}
//Accessor for strength
int Character::getStrength(){
    return this->strength;
}
//Modifier for strength
void Character::setStrength(int s){
    strength = s;
}
//Accessor for locate
Space *Character::getLocate(){
    return this->locate;
}
//modifier for locate
void Character::setLocate(Space *room){
   locate = room;
}
//accessor for USB
bool Character::getHasUSB(){

    return this->hasUSB;

}
//Modifier for USB
void Character::setHasUSB(bool usb){
    hasUSB = usb;
}

/****************************************************************************************************
 * * Program name: CS162 Final Project
 * * Author: Taekyoung Kim
 * * Date: 03/03/2019
 * * Description: This is Space.cpp file for CS162 Final Project
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


#include "Space.h"

//Constructor
Space::Space() = default;

//destructor
Space::~Space() = default;

//Accessor for top
Space *Space::getTop(){
    return this->top;

}
//Accessor for bottom
Space *Space::getBottom(){
    return this->bottom;

}
//Accessor for right
Space *Space::getRight(){
   return this->right;
}
//Accessor for left
Space *Space::getLeft(){
   return this->left;
}
//Accessor for the room/space name
std::string Space::getName() const{
   return this->sName;
}
//modifier for top
void Space::setTop(Space *ptr){
    top = ptr;

}
//modifier for bottom
void Space::setBottom(Space *ptr){
    bottom = ptr;
}
//modifier for right
void Space::setRight(Space *ptr){
    right = ptr;
}
//modifier for left
void Space::setLeft(Space *ptr){
    left = ptr;
}
//modifier for the room/space name
void Space::setName(std::string na){
    sName = na;
}
//Accessor for USB
bool Space::getIsUSB(){
    return this->isUSB;

}
//Modifier for USB
void Space::setIsUSB(bool usb){
    isUSB = usb;
}
//Accessor for Item
bool Space::getIsItem(){
    return this->isItem;
}
//Modifier for Item
void Space::setIsItem(bool item){
    isItem = item;
}
//Accessor for doneF
bool Space::getDoneF(){
    return this->doneF;

}
//Modifier for doneF
void Space::setDoneF(bool dF){
    doneF = dF;
}
//Accessor for doneS
bool Space::getDoneS(){
    return this->doneS;

}
//Modifier for doneS
void Space::setDoneS(bool dS){
    doneS = dS;
}
//Accessor for doneT
bool Space::getDoneT(){
    return this->doneT;
}
//Modifier for doneT
void Space::setDoneT(bool dT){
    doneT = dT;
}

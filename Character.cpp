//
// Created by Taekyoung Kim on 2019-03-05.
//

#include "Character.h"
#include <iostream>
#include "Space.h"


Character::Character() = default;
Character::~Character() = default;
Character::Character(std::string na, int s, int ct) {

    this->cName = na;
    this->strength = s;
    this->count = ct;
}

std::string Character::getCName(){

    return this->cName;
}

void Character::setCName(std::string cNa){
    cName = cNa;
}

int Character::getStrength(){
    return this->strength;
}

void Character::setStrength(int s){
    strength = s;
}

int Character::getCount() {
    return this->count;

}
void Character::setCount(int ct){
    count = ct;
}

Space *Character::getLocate(){
    return this->locate;
}
void Character::setLocate(Space *room){
   locate = room;
}
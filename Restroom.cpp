//
// Created by Taekyoung Kim on 2019-03-05.
//

#include "Restroom.h"
#include <iostream>

Restroom::Restroom() = default;
Restroom::~Restroom() = default;
void Restroom::description(Character *cha) {

    std::cout<<"This room is a restroom that you can take a rest and think where to go what todo."<<std::endl;
    std::cout<<"Also you can find some hidden money here.";
    std::cout<<"Let's check it. What is it in the backside of the mirror."<<std::endl;
    std::cout<<"Oh, a $100 bill. Let's put it in the wallet if there is room."<<std::endl;
    /* check the vector and do something */

}
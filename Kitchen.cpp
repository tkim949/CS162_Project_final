//
// Created by Taekyoung Kim on 2019-03-05.
//

#include "Kitchen.h"
#include <iostream>
#include "helper.h"
#include "Character.h"

Kitchen::Kitchen() = default;
Kitchen::~Kitchen() = default;
void Kitchen::description(Character *cha) {

    double dWater;
    int dWa;

    std::cout<<"Now you entered in the Kitchen. There are a fridge, a cabinet, and a cupboard."<<std::endl;
    std::cout<<"The USB might be hidden in the one of those three places."<<std::endl;
    std::cout<<"Also, you can find money and have it if your wallet has room"<<std::endl;


    if(!hasUSB) {

        std::cout<<"\nFirst, you go to the fridge. And check it. USB is not here."<<std::endl;
        std::cout<<"\nNext, you go to the cabinet. USB is not either."<<std::endl;
        std::cout<<"Finally check the cupboard. No, USB is not there too."<<std::endl;
        std::cout<<"Oh wait. here is $100 bill. You can put it in your wallet"<<std::endl;
        /* something to do here */

    }
    else {

        int hiddenP = randomNum(3);

        if(hiddenP == 1) {
            std::cout<<"\nFirst, you go to the fridge. And check it. USB is here. You got it!"<<std::endl;
            std::cout<<"Now, you need to leave the house quietly."<<std::endl;
            cha->gotUSB = true;
        }
        else if(hiddenP == 2 ) {
            std::cout<<"\nFirst, you go to the fridge. And check it. USB is not here."<<std::endl;
            std::cout<<"\nNext, you go to the cabinet. USB is here!!!"<<std::endl;
            std::cout<<"Now, you need to leave the house quietly."<<std::endl;
            cha->gotUSB = true;
        }
        else {
            std::cout<<"\nFirst, you go to the fridge. And check it. USB is not here."<<std::endl;
            std::cout<<"\nNext, you go to the cabinet. USB is not either."<<std::endl;
            std::cout<<"Finally check the cupboard. Yes! USB is here!!!"<<std::endl;
            cha->gotUSB = true;
        }
    }




}


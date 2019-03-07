//
// Created by Taekyoung Kim on 2019-03-05.
//

#include "Studyroom.h"
#include <iostream>
#include "helper.h"


Studyroom::Studyroom() = default;
Studyroom::~Studyroom() = default;
void Studyroom::description(Character *cha) {

    std::cout<<"This room is a study room that has a desk, a bookshelf, and a sofa set."<<std::endl;
    std::cout<<"The USB might be hidden in the one of those three places."<<std::endl;
    std::cout<<"Also, you can find money and have it if your wallet has room"<<std::endl;


    if(!hasUSB) {

        std::cout<<"\nFirst, you go to the desk. And check it. USB is not here."<<std::endl;
        std::cout<<"Oh wait. here is $100 bill. You can put it in your wallet"<<std::endl;
        /* something to do here */
        std::cout<<"\nNext, you go to the bookshelf. USB is not either."<<std::endl;
        std::cout<<"Finally check the drawer. No, USB is not there too."<<std::endl;

    }
    else {

        int hiddenP = randomNum(3);

        if(hiddenP == 1) {
            std::cout<<"\nFirst, you go to the desk. And check it. USB is here. You got it!"<<std::endl;
            std::cout<<"Now, you need to leave the house quietly."<<std::endl;
            cha->gotUSB = true;
        }
        else if(hiddenP == 2 ) {
            std::cout<<"\nFirst, you go to the desk. And check it. USB is not here."<<std::endl;
            std::cout<<"Oh wait. here is $100 bill. You can put it in your wallet"<<std::endl;
            /* something to do here */
            std::cout<<"\nNext, you go to the bookshelf. USB is here!!!"<<std::endl;
            std::cout<<"Now, you need to leave the house quietly."<<std::endl;
            cha->gotUSB = true;
        }
        else {
            std::cout<<"\nFirst, you go to the desk. And check it. USB is not here."<<std::endl;
            std::cout<<"Oh wait. here is $100 bill. You can put it in your wallet"<<std::endl;
            /* something to do here */
            std::cout<<"\nNext, you go to the bookshelf. USB is not either."<<std::endl;
            std::cout<<"Finally check the drawer. Yes! USB is here!!!"<<std::endl;
            cha->gotUSB = true;
        }
    }

}
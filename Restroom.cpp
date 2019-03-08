//
// Created by Taekyoung Kim on 2019-03-05.
//

#include "Restroom.h"
#include <iostream>
#include "helper.h"
#include <climits>

Restroom::Restroom() = default;
Restroom::~Restroom() = default;
void Restroom::description(Character *cha, int num) {

    int restCh = randomNum(3);
    int getPower = randomNum(3);

    std::cout<<"Is there the USB here: "<<getIsUSB()<<std::endl;
    std::cout<<"The random number for search place: "<<restCh<<std::endl;

    std::cout<<"\nThis room is a restroom that you can take a rest and think where to go what todo."<<std::endl;
    std::cout<<"Also you can get some good stuff here."<<std::endl;
    std::cout<<"What is waiting for you? Let's check!"<<std::endl;

    std::cout << "\nPress ENTER to Continue....\n";
    std::cin.get();

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
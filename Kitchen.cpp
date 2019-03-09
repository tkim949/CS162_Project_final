//
// Created by Taekyoung Kim on 2019-03-05.
//

#include "Kitchen.h"
#include <iostream>
#include "helper.h"
#include "Character.h"

Kitchen::Kitchen() = default;
Kitchen::~Kitchen() = default;
void Kitchen::description(Character *cha, int hiddenP) {

    //double dWater;
    //int dWa;
    std::cout<<"Is there the USB here: "<<getIsUSB()<<std::endl;
    std::cout<<"The random number for search place: "<<hiddenP<<std::endl;

    int count = 0;

    if(doneF) {
        count ++;
    }
    if(doneS) {
        count ++;
    }
    if(doneT) {
        count ++;
    }
    std::cout<<"The found place number: "<<count<<std::endl;

    double oChoice;
    int choice;
    double tChoice;
    int tCh;

    if(count == 0 ) {

        std::cout<<"\nNow you entered in the Kitchen. There are a fridge, a cabinet, and a cupboard."<<std::endl;
        std::cout<<"The USB might be hidden in one of those three places."<<std::endl;
        std::cout<<"Also, you can find other stuff."<<std::endl;
        std::cout<<"You are here first, so you need to search all three."<<std::endl;
        std::cout<<"Where do you want to search this time?"<<std::endl;
        std::cout<<"1. Fridge"<<std::endl;
        std::cout<<"2. Cabinet"<<std::endl;
        std::cout<<"3. Cupboard"<<std::endl;
        std::cin.clear();
        //std::cin.ignore(INT_MAX, '\n');
        std::cin>>oChoice;
        choice = inputVal(oChoice);

        switch(choice) {

            case 1: std::cout<<"You want to search the Fridge first. Okay, Let's do it."<<std::endl;
                if(getIsUSB() && hiddenP == 1) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "What is it behind the bottle?" << std::endl;
                    std::cout << "Oh dame it! It is rotten food covered with mold. Who did this?" << std::endl;
                    std::cout << "You were shocked and lost your energy 1. So sorry." << std::endl;
                    cha->setStrength(cha->getStrength() - 1);
                }
                doneF = true;
                break;

            case 2: std::cout<<"You want to search the cabinet first. Clever, Is the USB there?"<<std::endl;
                if(getIsUSB() && hiddenP == 2) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "No, USB not here. But wait a sec. You found PEARL." << std::endl;
                    setIsItem(true);
                }
                doneS = true;
                break;

            case 3: std::cout<<"You want to search the cupboard first. Let's start!"<<std::endl;
                if(getIsUSB() && hiddenP == 3) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "Oh bad! Nothing is here. Next time you have luck." << std::endl;

                }
                doneT = true;
                break;

            default:
                break;

        }

    }

    else if(count == 1) {

        std::cout<<"This is your second search in the kitchen. Okay now you have two places to search."<<std::endl;

        if(doneF){
            std::cout<<"1. Cabinet"<<std::endl;
            std::cout<<"2. Cupboard"<<std::endl;
            std::cin>>tChoice;
            tCh = inputNum(tChoice);

            if(tCh == 1) {
                std::cout<<"You chose the cabinet to search this time. Good. Let's check it."<<std::endl;
                if(getIsUSB() && hiddenP == 2) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "No, USB not here. But wait a sec. You found PEARL." << std::endl;
                    setIsItem(true);
                }
                doneS = true;

            }
            else { //tCh == 2
                std::cout<<"You want to search the cupboard this time. Let's start!"<<std::endl;
                if(getIsUSB() && hiddenP == 3) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "No, USB is not here." << std::endl;

                }
                doneT = true;

            }

        }
        else if(doneS) {

            std::cout<<"1. Fridge"<<std::endl;
            std::cout<<"2. Cupboard"<<std::endl;
            std::cin>>tChoice;
            tCh = inputNum(tChoice);

            if(tCh == 1) {
                std::cout<<"You want to search the Fridge this time. Let's go!"<<std::endl;
                if(getIsUSB() && hiddenP == 1) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "What is it behind the bottle?" << std::endl;
                    std::cout << "Oh dame it! It is rotten food covered with mold. Who did this?" << std::endl;
                    std::cout << "You were shocked and lost your energy 1. So sorry." << std::endl;
                    cha->setStrength(cha->getStrength() - 1);
                }
                doneF = true;
            }
            else { //tCh ==2
                std::cout<<"You want to search the cupboard this time. Let's start!"<<std::endl;
                if(getIsUSB() && hiddenP == 3) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "No, USB is not here." << std::endl;
                }
                doneT = true;
            }
        }
        else if(doneT) {

            std::cout<<"1. Fridge"<<std::endl;
            std::cout<<"2. Cabinet"<<std::endl;
            std::cin>>tChoice;
            tCh = inputNum(tChoice);

            if(tCh == 1) {
                std::cout<<"You want to search the Fridge this time. Let's go!"<<std::endl;
                if(getIsUSB() && hiddenP == 1) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "What is it behind the bottle?" << std::endl;
                    std::cout << "Oh dame it! It is rotten food covered with mold. Who did this?" << std::endl;
                    std::cout << "You were shocked and lost your energy 1. So sorry." << std::endl;
                    cha->setStrength(cha->getStrength() - 1);
                }
                doneF = true;
            }
            else { //tCh == 2
                std::cout<<"You chose the cabinet to search this time. Good. Let's check it."<<std::endl;
                if(getIsUSB() && hiddenP == 2) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "No, USB not here. But wait a sec. You found PEARL." << std::endl;
                    setIsItem(true);
                }
                doneS = true;

            }

        }
    }
    else if(count == 2) {
        std::cout<<"This is the third time in the Kitchen"<<std::endl;

        if(!doneF) {
            std::cout<<"You finally have a chance to search the Fridge. Let's hurry."<<std::endl;
            if(getIsUSB() && hiddenP == 1) {
                std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                cha->setHasUSB(true);

            } else {
                std::cout << "What is it behind the bottle?" << std::endl;
                std::cout << "Oh dame it! It is rotten food covered with mold. Who did this?" << std::endl;
                std::cout << "You were shocked and lost your energy 1. So sorry." << std::endl;
                cha->setStrength(cha->getStrength() - 1);
            }
            doneF = true;
        }
        else if(!doneS) {
            std::cout<<"You finally have a chance to search the cabinet. Let's hurry."<<std::endl;
            if(getIsUSB() && hiddenP == 2) {
                std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                cha->setHasUSB(true);

            } else {
                std::cout << "No, USB not here. But wait a sec. You found PEARL." << std::endl;
                setIsItem(true);
            }
            doneS = true;
        }
        else if(!doneT){
            std::cout<<"You finally have a chance to search the cupboard. Let's hurry."<<std::endl;
            if(getIsUSB() && hiddenP == 3) {
                std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                cha->setHasUSB(true);

            } else {
                std::cout << "No, USB is not here. So sorry this was the last place of this room." << std::endl;
            }
            doneT = true;
        }
    }
    else if(count == 3) {
        std::cout<<"You have already searched the fridge, cabinet, and the cupboard."<<std::endl;
        std::cout<<"So, go find other rooms!"<<std::endl;
    }

}


//
// Created by Taekyoung Kim on 2019-03-05.
//

#include "Studyroom.h"
#include <iostream>
#include "helper.h"


Studyroom::Studyroom() = default;
Studyroom::~Studyroom() = default;
void Studyroom::description(Character *cha, int hiddenP) {

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

        std::cout<<"\nThis room is a study room that has a desk, a bookshelf, and a sofa set."<<std::endl;
        std::cout<<"The USB might be hidden in one of those three places."<<std::endl;
        std::cout<<"Also, you can find other stuff."<<std::endl;
        std::cout<<"You are here first, so you need to search all three."<<std::endl;
        std::cout<<"Where do you want to search this time?"<<std::endl;
        std::cout<<"1. Desk"<<std::endl;
        std::cout<<"2. Bookshelf"<<std::endl;
        std::cout<<"3. Sofa"<<std::endl;
        std::cin>>oChoice;
        choice = inputVal(oChoice);

        switch(choice) {

            case 1: std::cout<<"You want to search the Desk first. Okay, Let's do it."<<std::endl;
                if(getIsUSB() && hiddenP == 1) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "Oh bad! Nothing is here. Maybe it is in the other study room. " << std::endl;
                }
                doneF = true;
                break;

            case 2: std::cout<<"You want to search the Bookshelf first. Clever, Is the USB there?"<<std::endl;
                if(getIsUSB() && hiddenP == 2) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "No, USB not here. But wait a sec. You found SILVER." << std::endl;
                    setIsItem(true);
                }
                doneS = true;
                break;

            case 3: std::cout<<"You want to search the Sofa first. Let's start!"<<std::endl;
                if(getIsUSB() && hiddenP == 3) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "What is it under the sofa?" << std::endl;
                    std::cout << "Oh dame it! It is a discarded chewing gum. Why was it there?" << std::endl;
                    std::cout << "You were shocked and lost your energy 1. So sorry." << std::endl;
                    cha->setStrength(cha->getStrength() - 1);
                }
                doneT = true;
                break;

            default:
                break;

        }

    }

    else if(count == 1) {

        std::cout<<"This is your second search in the study room. Okay now you have two places to search."<<std::endl;

        if(doneF){

            std::cout<<"1. Bookshelf"<<std::endl;
            std::cout<<"2. Sofa"<<std::endl;
            std::cin>>tChoice;
            tCh = inputNum(tChoice);

            if(tCh == 1) {
                std::cout<<"You chose the bookshelf to search this time. Good. Let's check it."<<std::endl;
                if(getIsUSB() && hiddenP == 2) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "No, USB not here. But wait a sec. You found SILVER" << std::endl;
                    setIsItem(true);
                }
                doneS = true;

            }
            else { //tCh == 2
                std::cout<<"You want to search the sofa this time. Let's start!"<<std::endl;
                if(getIsUSB() && hiddenP == 3) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "What is it under the sofa?" << std::endl;
                    std::cout << "Oh dame it! It is a discarded chewing gum. Why was it there?" << std::endl;
                    std::cout << "You were shocked and lost your energy 1. So sorry." << std::endl;
                    cha->setStrength(cha->getStrength() - 1);
                }
                doneT = true;

            }

        }
        else if(doneS) {

            std::cout<<"1. Desk"<<std::endl;
            std::cout<<"2. Sofa"<<std::endl;
            std::cin>>tChoice;
            tCh = inputNum(tChoice);

            if(tCh == 1) {
                std::cout<<"You want to search the Desk this time. Let's go!"<<std::endl;
                if(getIsUSB() && hiddenP == 1) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "No, usb is not here! Don't worry. You can find it elsewhere soon" << std::endl;
                }
                doneF = true;
            }
            else { //tCh ==2
                std::cout<<"You want to search the Sofa this time. Let's start!"<<std::endl;
                if(getIsUSB() && hiddenP == 3) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "What is it under the sofa?" << std::endl;
                    std::cout << "Oh dame it! It is a discarded chewing gum. Why was it there?" << std::endl;
                    std::cout << "You were shocked and lost your energy 1. So sorry." << std::endl;
                    cha->setStrength(cha->getStrength() - 1);
                }
                doneT = true;
            }
        }
        else if(doneT) {

            std::cout<<"1. Desk"<<std::endl;
            std::cout<<"2. Bookshelf"<<std::endl;
            std::cin>>tChoice;
            tCh = inputNum(tChoice);

            if(tCh == 1) {
                std::cout<<"You want to search the desk this time. Let's go!"<<std::endl;
                if(getIsUSB() && hiddenP == 1) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "No, usb is not here! Don't worry. You can find it elsewhere soon" << std::endl;
                }
                doneF = true;
            }
            else { //tCh == 2
                std::cout<<"You chose the bookshelf to search this time. Good. Let's check it."<<std::endl;
                if(getIsUSB() && hiddenP == 2) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "No, USB not here. But wait a sec. You found SILVER." << std::endl;
                    setIsItem(true);
                }
                doneS = true;

            }

        }
    }
    else if(count == 2) {

        std::cout<<"This is the third time in the Study room"<<std::endl;

        if(!doneF) {
            std::cout<<"You finally have a chance to search the desk. Let's hurry."<<std::endl;
            if(getIsUSB() && hiddenP == 1) {
                std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                cha->setHasUSB(true);

            } else {
                std::cout << "I'm so sorry, but USB is not here too." << std::endl;
            }
            doneF = true;
        }
        else if(!doneS) {
            std::cout<<"You finally have a chance to search the bookshelf. Let's hurry."<<std::endl;
            if(getIsUSB() && hiddenP == 2) {
                std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                cha->setHasUSB(true);

            } else {
                std::cout << "No, USB not here. But wait a sec. You found SILVER." << std::endl;
                setIsItem(true);
            }
            doneS = true;
        }
        else if(!doneT){
            std::cout<<"You finally have a chance to search the sofa. Let's hurry."<<std::endl;
            if(getIsUSB() && hiddenP == 3) {
                std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                cha->setHasUSB(true);

            } else {
                std::cout << "What is it under the sofa?" << std::endl;
                std::cout << "Oh dame it! It is a discarded chewing gum. Why is it there?" << std::endl;
                std::cout << "You were shocked and lost your energy 1. Terribly sorry." << std::endl;
                cha->setStrength(cha->getStrength() - 1);
            }
            doneT = true;
        }

    }
    else if(count == 3) {
        std::cout<<"You have already searched the desk, bookshelf, and the sofa."<<std::endl;
        std::cout<<"So, go find other rooms!"<<std::endl;
    }


}
//
// Created by Taekyoung Kim on 2019-03-05.
//

#include "Bedroom.h"
# include <iostream>
#include "helper.h"

Bedroom::Bedroom() = default;
Bedroom::~Bedroom() = default;

void Bedroom::description(Character *cha, int hiddenP) {

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
    std::cout<<"The number of room that already search: "<<count<<std::endl;

    double oChoice;
    int choice;
    double tChoice;
    int tCh;


        if(count == 0 ) {
            std::cout<<"This is a bedroom that has a bed, a closet, and a drawer."<<std::endl;
            std::cout<<"The USB might be hidden in one of those three places."<<std::endl;
            std::cout<<"Also, you can find other stuff."<<std::endl;
            std::cout<<"\nYou are here first, so you need to search all three."<<std::endl;
            std::cout<<"Where do you want to search this time?"<<std::endl;
            std::cout<<"1. Bed"<<std::endl;
            std::cout<<"2. Closet"<<std::endl;
            std::cout<<"3. Drawer"<<std::endl;
            std::cin>>oChoice;
            choice = inputVal(oChoice);

            switch(choice) {

                case 1: std::cout<<"You want to search the Bed first. Okay, Let's do it."<<std::endl;
                        if(getIsUSB() && hiddenP == 1) {
                            std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                            cha->setHasUSB(true);

                        } else {
                            std::cout << "Oh bad! Nothing is here. Next Time you get luck" << std::endl;
                        }
                        doneF = true;
                        break;

                case 2: std::cout<<"You want to search the closet first. Good, Is the USB there?"<<std::endl;
                       if(getIsUSB() && hiddenP == 2) {
                        std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                        cha->setHasUSB(true);

                        } else {
                           std::cout << "No, USB not here. But wait a sec. You found GOLD." << std::endl;
                           setIsItem(true);
                        }
                        doneS = true;
                        break;

                case 3: std::cout<<"You want to search the Drawer first. Let's start!"<<std::endl;
                        if(getIsUSB() && hiddenP == 3) {
                        std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                        cha->setHasUSB(true);

                        } else {
                            std::cout << "What is it behind the socks in the bottom?" << std::endl;
                            std::cout << "Oh dame it! It was a dead rat!" << std::endl;
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

            std::cout<<"This is your second search in the bedroom. Okay now you have two places to search."<<std::endl;

            if(doneF){

                std::cout<<"1. Closet"<<std::endl;
                std::cout<<"2. Drawer"<<std::endl;
                std::cin>>tChoice;
                tCh = inputNum(tChoice);

                if(tCh == 1) {
                    std::cout<<"You chose the closet to search this time. Good. Let's check it."<<std::endl;
                    if(getIsUSB() && hiddenP == 2) {
                        std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                        cha->setHasUSB(true);

                    } else {
                        std::cout << "No, USB not here. But wait a sec. You found GOLD." << std::endl;
                        setIsItem(true);
                    }
                    doneS = true;

                }
                else { //tCh == 2
                    std::cout<<"You want to search the Drawer this time. Let's start!"<<std::endl;
                    if(getIsUSB() && hiddenP == 3) {
                        std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                        cha->setHasUSB(true);

                    } else {
                        std::cout << "What is it behind the socks in the bottom?" << std::endl;
                        std::cout << "Oh dame it! It was a dead rat!" << std::endl;
                        std::cout << "You were shocked and lost your energy 1. So sorry." << std::endl;
                        cha->setStrength(cha->getStrength() - 1);
                    }
                    doneT = true;

                }

            }
            else if(doneS) {

                std::cout<<"1. Bed"<<std::endl;
                std::cout<<"2. Drawer"<<std::endl;
                std::cin>>tChoice;
                tCh = inputNum(tChoice);

                if(tCh == 1) {
                    std::cout<<"You want to search the bed this time. Let's go!"<<std::endl;
                    if(getIsUSB() && hiddenP == 1) {
                        std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                        cha->setHasUSB(true);

                    } else {
                        std::cout << "No, usb is not here! Don't worry. You can find it elsewhere soon" << std::endl;
                    }
                    doneF = true;
                }
                else { //tCh ==2
                    std::cout<<"You want to search the Drawer this time. Let's start!"<<std::endl;
                    if(getIsUSB() && hiddenP == 3) {
                        std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                        cha->setHasUSB(true);

                    } else {
                        std::cout << "What is it behind the socks in the bottom?" << std::endl;
                        std::cout << "Oh dame it! It was a dead rat!" << std::endl;
                        std::cout << "You were shocked and lost your energy 1. So sorry." << std::endl;
                        cha->setStrength(cha->getStrength() - 1);
                    }
                    doneT = true;
                }
            }
            else if(doneT) {

                std::cout<<"1. Bed"<<std::endl;
                std::cout<<"2. Closet"<<std::endl;
                std::cin>>tChoice;
                tCh = inputNum(tChoice);

                if(tCh == 1) {
                    std::cout<<"You want to search the bed this time. Let's go!"<<std::endl;
                    if(getIsUSB() && hiddenP == 1) {
                        std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                        cha->setHasUSB(true);

                    } else {
                        std::cout << "No, usb is not here! Don't worry. You can find it elsewhere soon" << std::endl;
                    }
                    doneF = true;
                }
                else { //tCh == 2
                    std::cout<<"You chose the closet to search this time. Good. Let's check it."<<std::endl;
                    if(getIsUSB() && hiddenP == 2) {
                        std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                        cha->setHasUSB(true);

                    } else {
                        std::cout << "No, USB not here. But wait a sec. You found GOLD." << std::endl;
                        setIsItem(true);
                    }
                    doneS = true;

                }

            }
        }
        else if(count == 2) {

            std::cout<<"This is the third time in this bedroom."<<std::endl;

            if(!doneF) {
                std::cout<<"You finally have a chance to search the bed. Let's do it. We don't have much time."<<std::endl;
                if(cha->getHasUSB() && hiddenP == 1) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "I'm so sorry, but USB is not here too." << std::endl;
                }
                doneF = true;
            }
            else if(!doneS) {
                std::cout<<"You finally have a chance to search the closet. Let's do it. We don't have much time."<<std::endl;
                if(cha->getHasUSB() && hiddenP == 2) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "No, USB not here. But wait a sec. You found GOLD." << std::endl;
                    setIsItem(true);
                }
                doneS = true;
            }
            else if(!doneT){
                std::cout<<"You finally have a chance to search the drawer. Let's do it. We don't have much time."<<std::endl;
                if(cha->getHasUSB() && hiddenP == 3) {
                    std::cout <<"Oh, something is here! You got the USB!"<<std::endl;
                    cha->setHasUSB(true);

                } else {
                    std::cout << "What is it behind the socks in the bottom?" << std::endl;
                    std::cout << "Oh dame it! It was a dead rat!" << std::endl;
                    std::cout << "You were shocked and lost your energy 1. Terribly sorry." << std::endl;
                    cha->setStrength(cha->getStrength() - 1);
                }
                doneT = true;
            }

        }
        else if(count == 3) {
            std::cout<<"You have already searched the bed, closet, and drawer."<<std::endl;
            std::cout<<"So, go find other rooms!"<<std::endl;
        }

}
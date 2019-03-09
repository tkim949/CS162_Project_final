//
// Created by Taekyoung Kim on 2019-03-05.
//

#include "Game.h"
#include <iostream>
#include "helper.h"
#include "Restroom.h"
#include "Bedroom.h"
#include "Studyroom.h"
#include "Kitchen.h"
#include "Character.h"
#include <climits>
#include "Inventory.h"
#include <vector>

//Game::Game() = default;
Game::Game(){

    you = new Character("you", 20);
    sMom = new Character("Mother", 30);
    sBro = new Character("Brother", 20);
    rtRoom1 = new Restroom;
    rtRoom1->setName("Restroom1");
    rtRoom2 = new Restroom;
    rtRoom2->setName("Restroom2");
    bdRoom1 = new Bedroom;
    bdRoom1->setName("Bedroom1");
    bdRoom2 = new Bedroom;
    bdRoom2->setName("Bedroom2");
    sdRoom1 = new Studyroom;
    sdRoom1->setName("Studyroom1");
    sdRoom2 = new Studyroom;
    sdRoom2->setName("Studyroom2");
    kitchen = new Kitchen;
    kitchen->setName("Kitchen");

}

Game::~Game() = default;

void Game::play(){

    int playAg;
    double goPlay;
    int goPl;
    Inventory item;
    double roomChoice;
    int roomCh;
    double afterChoice;
    int afChoice;
    Inventory list;


    std::cout << "***************************************************" <<std::endl;
    std::cout << "** Welcome to the Game of Receiving Inheritance! **" << std::endl;
    std::cout << "***************************************************" <<std::endl;
    std::cout << "Do you want to play Game? " << std::endl;
    std::cout << "1. Play" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cin >> goPlay;
    goPl = inputVal(goPlay);


    do {

        if (goPl == 2) {
            std::cout << "So you don't want to play. Good bye!" << std::endl;
        } else {

            //Where is USB
            int dice = randomNum(5);
            std::cout << "random number for the USB: " << dice << std::endl;

            switch (dice) {

                case 1:
                    bdRoom1->setIsUSB(true);
                    std::cout<<"when case1(bdroom1): "<<bdRoom1->getIsUSB()<<std::endl;
                    break;

                case 2:
                    bdRoom2->setIsUSB(true);
                    std::cout<<"when case2(bdroom2): "<<bdRoom2->getIsUSB()<<std::endl;
                    break;

                case 3:
                    sdRoom1->setIsUSB(true);
                    std::cout<<"when case3(sdroom1): "<<sdRoom1->getIsUSB()<<std::endl;
                    break;

                case 4:
                    sdRoom2->setIsUSB(true);
                    std::cout<<"when case4(sdroom2): "<<sdRoom2->getIsUSB()<<std::endl;
                    break;

                case 5:
                    kitchen->setIsUSB(true);
                    std::cout<<"when case5(kitchen): "<<kitchen->getIsUSB()<<std::endl;
                    break;

                default:
                    break;

            }
            int hiddenUSB = randomNum(3);

            std::cout<<"The hidden number for USB: "<< hiddenUSB <<std::endl;

            std::cout << "\n================================="<< std::endl;
            std::cout << "              START!"              << std::endl;
            std::cout << "=================================" <<std::endl;
            std::cout << "Great! You start the game. Then, I will tell you something." << std::endl;
            std::cout << "Your father died a few weeks ago, and you have a step mother and step brother" << std::endl;
            std::cout << "They said that your father hadn't have fortune and didn't leave anything to you."<< std::endl;
            std::cin.clear();
            //std::cin.ignore(INT_MAX, '\n');
            std::cout << "\nPress ENTER to Continue....\n";
            std::cin.get();

            std::cout << "But, that's weird because your father was an old screw but a man of means." << std::endl;
            std::cout << "And you know he stored his assets' info in a USB and that USB is somewhere in the house.";
            std::cout << "\nYou need to find that USB in limited time" << std::endl;
            std::cout << "\nPress ENTER to Continue....\n";
            std::cin.get();

            std::cout << "There are 5 rooms; bedroom1, bedroom2, study room1, study room2, kitchen"<< std::endl;
            std::cout << "And each room has three places that You need to search" << std::endl;
            std::cout<< "Whenever entering the room, you can find only one place. Choose carefully."<<std::endl;
            std::cout<< "Also, some stuff is hidden, good one or bad one besides the USB."<<std::endl;
            std::cout << "\nPress ENTER to Continue....\n";
            std::cin.get();

            std::cout << "Also, there are two restrooms that you can take a rest and get strength" << std::endl;
            std::cout << "You start from the rest room 1 in the first floor." << std::endl;
            std::cout << "Seeing the map is easier to understand. "<<std::endl;
            current = rtRoom1;
            std::cout << "\nPress ENTER to Continue....\n";
            std::cin.get();

            std::cout << "Here is the map. '*' represents you.\n"<< std::endl;
            showMap(10, 16);

            std::cout << "\nPress ENTER to Continue....\n";
            std::cin.get();

            std::cout << "\nYour full strength is 20, and strength 1 will be deducted for each room search."<<std::endl;
            std::cout<<"Also, if you see your step mother after your first move,"<<std::endl;
            std::cout <<"strength will be deducted between 1 and 5 randomly" <<std::endl;
            theyGo(sMom);
            std::cout<<"\nNow your mother is: "<<sMom->getLocate()->getName()<<std::endl;
            std::cout << "Then, if you see your step brother, your strength will be deducted "<<std::endl;
            std::cout<< "randomly between 1 and 3. They are moving in the house."<<std::endl;
            theyGo(sBro);
            std::cout<<"\nNow your brother is: "<<sBro->getLocate()->getName()<<std::endl;
            std::cout << "\nPress ENTER to Continue....\n";
            std::cin.get();

            std::cout << "But there is a way that you escape their attack." << std::endl;
            std::cout << "You can find jewelry in the house and put it into your container. "<<std::endl;
            std::cout << "Then If you give them the jewelry when ran into them, you can avoid deduction." << std::endl;
            std::cout << "More importantly, you need to keep a password for the USB in the container."<<std::endl;
            std::cout << "You should put this first and your container only keep 3 items."<<std::endl;

            item.addItem("*PASSWORD*");

            std::cout << "\nPress ENTER to Continue....\n";
            std::cin.get();
            std::cout << "Also, you have 15 chances to change rooms, so be careful! " << std::endl;
            std::cout<< "Now start!"<<std::endl;

            int step = 1;
            do {

                std::cout << "\n=========================="<<std::endl;
                std::cout << "  Number of step: " << step << std::endl;
                std::cout << "========================="<<std::endl;
                std::cout <<"\nYour current strength is: "<< you->getStrength() <<std::endl;
                //std::cout << "===========================================" <<std::endl;
                std::cout << "=== Go to the next Room! ==="<<std::endl;
                //std::cout << "===========================================" <<std::endl;
                std::cout << "\nYou are currently at " << current->getName() << std::endl;
                std::cout << "Now you can go to Top, Right, Left, Bottom." << std::endl;
                std::cout << "1. Top" << std::endl;
                std::cout << "2. Right" << std::endl;
                std::cout << "3. Left" << std::endl;
                std::cout << "4. Bottom" << std::endl;
                std::cout << "5. Exit Game" << std::endl;
                std::cin.clear();
                //std::cin.ignore(INT_MAX, '\n');
                std::cin >> roomChoice;
                roomCh = inputVal(roomChoice);

                if (roomCh == 5) {
                    std::cout << "So, you want to stop. Let's stop!" << std::endl;

                } else {

                    whereTo(current, roomCh);
                    std::cout << std::endl;

                    if (current == rtRoom1) {
                        showMap(10, 16);
                    } else if (current == rtRoom2) {
                        showMap(4, 16);
                    } else if (current == bdRoom1) {
                        showMap(4, 6);
                    } else if (current == bdRoom2) {
                        showMap(4, 26);
                    } else if (current == sdRoom1) {
                        showMap(10, 6);
                    } else if (current == sdRoom2) {
                        showMap(2, 6);
                    } else if (current == kitchen) {
                        showMap(10, 26);
                    }

                    std::cout << "\nNow you moved to " << current->getName() << std::endl;
                    list.writeList(current->getName());


                    //When meet step mother or brother
                    if (current == sMom->getLocate()) {

                        std::cout << "\nOh, bad! You ran into your step mother. She's nagging you" << std::endl;
                        std::cout << "If you have a item, you can give her the item and keep of it" << std::endl;
                        std::cout << "\nPress ENTER to Continue....\n";
                        std::cin.get();

                        //std::cout << "The number of items: " << item.count() << std::endl;
                        if (item.count() >= 2) {

                            std::cout << "You have 2 or more items so you can give it to her." << std::endl;
                            item.removeItem();
                        } else {
                            std::cout << "You don't have items to give her. Need to keep the PASSWORD for the USB."
                                      << std::endl;
                            std::cout << "Now, you will lose your strength because of her. Sorry" << std::endl;
                            int mDamage = randomNum(5);
                            you->setStrength(you->getStrength() - mDamage);
                            std::cout << "Now your strength is: " << you->getStrength() << std::endl;
                            sMom->setStrength(sMom->getStrength() - 1);

                        }
                        theyGo(sMom);
                    }

                    if (current == sBro->getLocate()) {

                        std::cout << "\nOh, bad! Your step brother is here. He is bullying you" << std::endl;
                        std::cout << "If you have a item, you can give him the item and keep of it" << std::endl;
                        std::cout << "\nPress ENTER to Continue....\n";
                        std::cin.get();
                        if (item.count() >= 2) {

                            std::cout << "You have 2 or more items so you can give it to him." << std::endl;
                            item.removeItem();
                        } else {
                            std::cout << "You don't have items to give her. Need to keep the PASSWORD for the USB."
                                      << std::endl;
                            std::cout << "Now, you will lose your strength because of him. Sorry" << std::endl;
                            int bDamage = randomNum(3);
                            you->setStrength(you->getStrength() - bDamage);
                            sBro->setStrength(sBro->getStrength() - 1);

                        }
                        theyGo(sBro);
                        std::cout<<std::endl;
                    }
                    std::cout<<std::endl;
                    current->description(you, hiddenUSB);

                    if (current->getIsItem()) {
                        if (current == bdRoom1 || current == bdRoom2) {
                            std::cout << "Now you can put that GOLD into the container." << std::endl;
                            item.addItem("GOLD");
                        } else if (current == sdRoom1 || current == sdRoom2) {
                            std::cout << "Now you can try to put the SILVER into the container." << std::endl;
                            item.addItem("SILVER");
                        } else if (current == rtRoom1 || current == rtRoom2) {
                            std::cout << "Now you can put that OPAL into the container." << std::endl;
                            item.addItem("OPAL");

                        } else if (current == kitchen) {
                            std::cout << "Now you can put the PEARL into the container." << std::endl;
                            item.addItem("PEARL");
                        }
                        current->setIsItem(false);
                        std::cout << std::endl;
                    }

                    you->setStrength(you->getStrength() - 1);

                    if(you->getHasUSB()) {
                        std::cout<<"\nNow, you need to go outside quietly"<<std::endl;

                    }
                    else {
                        std::cout << "\nNow your job in this room is done. Please choose what to do next" << std::endl;

                        do {
                            std::cout << "\n********************************" << std::endl;
                            std::cout << "          Let's choose" << std::endl;
                            std::cout << "********************************" << std::endl;
                            std::cout << "\n1. Go to the next room." << std::endl;
                            std::cout << "2. See items in your container." << std::endl;
                            std::cout << "3. Show your Path." << std::endl;
                            std::cout << "4. Check your strength."<<std::endl;
                            std::cout << "5. Check your number of steps."<<std::endl;
                            std::cin.clear();
                            //std::cin.ignore(INT_MAX, '\n');
                            std::cin >> afterChoice;
                            afChoice = inputVal(afterChoice);

                            switch (afChoice) {
                                case 1:
                                    std::cout << "\nNow Let's choose the next room!" << std::endl;
                                    break;
                                case 2:
                                    std::cout << "You want to see your items." << std::endl;
                                    item.showItem();
                                    break;
                                case 3:
                                    std::cout << "So you want to see your path!" << std::endl;
                                    list.showItem();
                                    break;
                                case 4:
                                    std::cout<<"You want to check your strength."<<std::endl;
                                    std::cout<<"Your strength: "<<you->getStrength()<<std::endl;
                                    break;
                                case 5:
                                    std::cout<<"You want to check your number of steps."<<std::endl;
                                    std::cout<<"Your number of steps: "<<step<<std::endl;

                                default:
                                    break;
                            }
                            std::cout << std::endl;

                        } while (afChoice != 1);
                    }

                }
                step++;

            } while (you->getStrength() > 0 && roomCh !=5 && step < 16 && !(you->getHasUSB()));

            if (you->getHasUSB()) {
                std::cout <<"\nWow, you got it! You left the house without being caught" << std::endl;
                std::cout<<"Now, You need to open the USB using the Password!"<<std::endl;
                std::cout<<"Take it from the container!"<<std::endl;
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "\nPress ENTER to Continue....\n";
                std::cin.get();

                item.hasLast();

                std::cout<<"\n**************************"<<std::endl;
                std::cout<<"    CONGRATULATIONS!       "<<std::endl;
                std::cout<<"**************************"<<std::endl;
                std::cout << "Now you will be rich." << std::endl;

            } else if (step >= 16) {
                std::cout<<"&&&&&&&&&&&&&&&&&"<<std::endl;
                std::cout<<"    GAME OVER    "<<std::endl;
                std::cout<<"&&&&&&&&&&&&&&&&&"<<std::endl;
                std::cout << "So sorry, your step exceeds the limits, Good bye!" << std::endl;

            } else if (you->getStrength() <= 0) {
                std::cout<<"&&&&&&&&&&&&&&&&&"<<std::endl;
                std::cout<<"    GAME OVER    "<<std::endl;
                std::cout<<"&&&&&&&&&&&&&&&&&"<<std::endl;
                std::cout << "Dame it. You lost your strength all and need to go to the hospital." << std::endl;
            }

        }

        std::cout << "\nDo you want to play again? If so, input 1. Otherwise click any keys" << std::endl;
        std::cin >> playAg;

    }while(playAg == 1);

    delete rtRoom1;
    delete rtRoom2;
    delete bdRoom1;
    delete bdRoom2;
    delete sdRoom1;
    delete sdRoom2;
    delete kitchen;
    delete you;
    delete sMom;
    delete sBro;
}

void Game::whereTo(Space *room, int choice) {

    double oChoice;


    if (room == rtRoom1) {

        if (choice == 1 || choice == 2 || choice == 3) {
            if (choice == 1) {
                room->setTop(rtRoom2);
                current = room->getTop();

            } else if (choice == 2) {
                room->setRight(kitchen);
                current = room->getRight();

            } else {
                room->setLeft(sdRoom1);
                current = room->getLeft();

            }
        } else {
            do {
                std::cout << "You chose the dead-end. Please choose again referring to the map : ";
                std::cin >> oChoice;
                choice = inputVal(oChoice);
                if (choice == 1) {
                    room->setTop(rtRoom2);
                    current = room->getTop();

                } else if (choice == 2) {
                    room->setRight(kitchen);
                    current = room->getRight();

                } else {
                    room->setLeft(sdRoom1);
                    current = room->getLeft();

                }
            } while (!(choice == 1 || choice == 2 || choice == 3));
        }
    } else if (room == rtRoom2) {
        if (choice == 2 || choice == 3 || choice == 4) {
            if (choice == 2) {
                room->setRight(bdRoom2);
                current = room->getRight();

            } else if (choice == 3) {
                room->setLeft(bdRoom1);
                current = room->getLeft();

            } else {
                room->setBottom(rtRoom1);
                current = room->getBottom();

            }
        } else {
            do {
                std::cout << "You chose the dead-end. Please choose again referring to the map: ";
                std::cin >> oChoice;
                choice = inputVal(oChoice);

                if (choice == 2) {
                    room->setRight(bdRoom2);
                    current = room->getRight();

                } else if (choice == 3) {
                    room->setLeft(bdRoom1);
                    current = room->getLeft();

                } else {
                    room->setBottom(rtRoom1);
                    current = room->getBottom();

                }

            } while (!(choice == 2 || choice == 3 || choice == 4));
        }
    } else if (room == bdRoom1) {

        if (choice == 1 || choice == 2 || choice == 4) {
            if (choice == 1) {
                room->setTop(sdRoom2);
                current = room->getTop();

            } else if (choice == 2) {
                room->setRight(rtRoom2);
                current = room->getRight();

            } else {
                room->setBottom(sdRoom1);
                current = room->getBottom();

            }
        } else {
            do {
                std::cout << "You chose the dead-end. Please choose again referring to the map: ";
                std::cin >> oChoice;
                choice = inputVal(oChoice);

                if (choice == 1) {
                    room->setTop(sdRoom2);
                    current = room->getTop();

                } else if (choice == 2) {
                    room->setRight(rtRoom2);
                    current = room->getRight();

                } else {
                    room->setBottom(sdRoom1);
                    current = room->getBottom();

                }
            } while (!(choice == 1 || choice == 2 || choice == 4));
        }
    } else if (room == bdRoom2) {
        if (choice == 3 || choice == 4) {
            if (choice == 3) {
                room->setLeft(rtRoom2);
                current = room->getLeft();

            } else {
                room->setBottom(kitchen);
                current = room->getBottom();

            }
        } else {
            do {
                std::cout << "You chose the dead-end. Please choose again referring to the map: ";
                std::cin >> oChoice;
                choice = inputVal(oChoice);

                if (choice == 3) {
                    room->setLeft(rtRoom2);
                    current = room->getLeft();

                } else {
                    room->setBottom(kitchen);
                    current = room->getBottom();
                }

            } while (!(choice == 3 || choice == 4));
        }
    } else if (room == sdRoom1) {
        if (choice == 1 || choice == 2) {
            if (choice == 1) {
                room->setTop(bdRoom1);
                current = room->getTop();

            } else {
                room->setRight(rtRoom1);
                current = room->getRight();

            }
        } else {
            do {
                std::cout << "You chose the dead-end. Please choose again referring to the map: ";
                std::cin >> oChoice;
                choice = inputVal(oChoice);

                if (choice == 1) {
                    room->setTop(bdRoom1);
                    current = room->getTop();

                } else {
                    room->setRight(rtRoom1);
                    current = room->getRight();
                }
            } while (!(choice == 1 || choice == 2));

        }

    }else if(room == sdRoom2) {
        if(choice == 4) {
            room->setBottom(bdRoom1);
            current = room->getBottom();
        }
        else {
            do {
                std::cout << "You chose the dead-end. Please choose again referring to the map: ";
                std::cin >> oChoice;
                choice = inputVal(oChoice);

                room->setBottom(bdRoom1);
                current = room->getBottom();

            }while(choice != 4);
        }
    }else if(room == kitchen) {
        if (choice == 1 || choice == 3) {
            if(choice == 1) {
                room->setTop(bdRoom2);
                current = room->getTop();

            } else{
                room->setLeft(rtRoom1);
                current = room->getLeft();

            }
        } else {
            do {
                std::cout << "You chose the dead-end. Please choose again referring to the map: ";
                std::cin >> oChoice;
                choice = inputVal(oChoice);
                if(choice == 1) {
                    room->setTop(bdRoom2);
                    current = room->getTop();

                } else{
                    room->setLeft(rtRoom1);
                    current = room->getLeft();

                }
            }while(!(choice == 1 || choice == 3));
        }
    }
}

void Game::theyGo(Character *cha){

    int place = randomNum(7);

    switch(place) {

        case 1:
            cha->setLocate(bdRoom1);
            break;
        case 2:
            cha->setLocate(bdRoom2);
            break;
        case 3:
            cha->setLocate(sdRoom1);
            break;
        case 4:
            cha->setLocate(sdRoom2);
            break;
        case 5:
            cha->setLocate(kitchen);
            break;
        case 6:
            cha->setLocate(rtRoom1);
            break;
        case 7:
            cha->setLocate(rtRoom2);
            break;
        default:
            break;
    }

}
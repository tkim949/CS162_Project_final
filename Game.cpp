//
// Created by Taekyoung Kim on 2019-03-05.
//

#include "Game.h"
#include <iostream>
#include "helper.h"
#include <stack>
#include "Restroom.h"
#include "Bedroom.h"
#include "Studyroom.h"
#include "Kitchen.h"
#include "Character.h"

//Game::Game() = default;
Game::Game(){

    you = new Character("you", 20, 15);
    rtRoom1 = new Restroom;
    rtRoom1->setName("Restroom1");
    rtRoom1->isOpen = true;
    rtRoom2 = new Restroom;
    rtRoom2->setName("Restroom2");
    rtRoom2->isOpen = true;
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
    double showWant;
    int showW;
    std::stack<std::string> myKeys;
    std::stack<int> money;

    double roomChoice;
    int roomCh;

    std::cout << "###################################################" <<std::endl;
    std::cout << "## Welcome to the Game of Receiving Inheritance! ##" << std::endl;
    std::cout << "###################################################" <<std::endl;
    std::cout << "Do you want to play Game? " << std::endl;
    std::cout << "1. Play" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cin >> goPlay;
    goPl = inputVal(goPlay);


    do {

        //For roof
        const int RSIZE = 7;
        char **roof;

        roof = new char *[RSIZE];

        for (int i = 0; i < RSIZE; i++) {
            roof[i] = new char[RSIZE];
        }

        for (int i = 0; i < RSIZE; i++) {
            for (int j = 0; j < RSIZE * 2 - 1; j++) {
                roof[i][j] = ' ';
            }
        }
        //For House
        const int HSIZE = 20;
        char **house;

        house = new char *[HSIZE];

        for (int i = 0; i < HSIZE; i++) {
            house[i] = new char[HSIZE];
        }

        for (int i = 0; i < HSIZE; i++) {
            for (int j = 0; j < 32; j++) {
                house[i][j] = ' ';
            }
        }

        if (goPl == 2) {
            std::cout << "So you don't want to play. Good bye!" << std::endl;
        } else {

            //Where is USB
            int dice = randomNum(5);
            std::cout << "random number for the USB: " << dice << std::endl;

            switch (dice) {

                case 1:
                    bdRoom1->hasUSB = true;
                    break;

                case 2:
                    bdRoom2->hasUSB = true;
                    break;

                case 3:
                    sdRoom1->hasUSB = true;
                    break;

                case 4:
                    sdRoom2->hasUSB = true;
                    break;

                case 5:
                    kitchen->hasUSB = true;
                    break;

                default:
                    break;

            }

            std::cout << "\n================================="<< std::endl;
            std::cout << "              START!"              << std::endl;
            std::cout << "=================================" <<std::endl;
            std::cout << "Great! You start the game. Then, I will tell you something." << std::endl;
            std::cout << "Your father died a few weeks ago, and you have a step mother and step brother" << std::endl;
            std::cout << "They said that your father didn't have any assets so you won't receive anything."
                      << std::endl;
            std::cout << "But, that's weird because your father was an old screw but a man of means." << std::endl;
            std::cout << "And you know he stored his assets' info in a USB and that USB is somewhere in the house."
                      << std::endl;
            std::cout << "You need to find that USB in limited time" << std::endl;
            std::cout << "There are 5 rooms; bedroom1, bedroom2, study room1, study room2, kitchen"<< std::endl;
            /******************************************
            std::cout<<"To enter the rooms, you need to use a key except the restrooms."<<std::endl;
            std::cout<<"You only have 4 multipurpose keys, so choose carefully where to go."<<std::endl;
            myKeys.push("key1");
            myKeys.push("key2");
            myKeys.push("key3");
            myKeys.push("key4");
            std::cout<<"\nIf once the door is opened, you can go there without a key afterwards"<<std::endl;
            ********************************************/
            std::cout << "And each space has three places that You need to search" << std::endl;
            std::cout << "Also, there are two restrooms that you can take a rest and get strength" << std::endl;
            std::cout << "You start from the rest room 1 in the first floor." << std::endl;
            //you->setLocate(rtRoom1);
            current = rtRoom1;

            std::cout << "Seeing the map is easier to understand. Here is the map. '*' represents you."<< std::endl;
            std::cout << "Do you want to see the map? if Yes, input 1. if No, input 2" << std::endl;
            std::cin >> showWant;
            showW = inputVal(showWant);

            if (showW == 1) {
                showMap(roof, house, RSIZE, HSIZE, 14, 16);
                std::cout << "Now you can see the Map and the location of each rooms." << std::endl;
            } else {
                std::cout << "You don't want to see a map. Okay. After you move, the map will appear anyway."
                          << std::endl;
            }

            std::cout << "\nYour full strength is 20, and if you see your step mother, 4 points will be deducted."
                      << std::endl;
            std::cout << "If you see your step brother, 3 points will deducted. They are moving in the house."
                      << std::endl;
            std::cout << "But don't worry. You have a wallet with 3 * $100." << std::endl;
            money.push(100);
            money.push(100);
            money.push(100);
            std::cout << "If you give them $100, they won't bother you and no deduction." << std::endl;
            std::cout << "Also, you have 6 chances to change rooms, so be careful! " << std::endl;

            int step = 1;
            do {
                std::cout << "\n====================="<<std::endl;
                std::cout << "  Number of step: " << step << std::endl;
                std::cout << "====================="<<std::endl;
                std::cout << "\nYour are currently at " << current->getName() << std::endl;
                std::cout << "Now you can go to Top, Right, Left, Bottom." << std::endl;
                std::cout << "1. Top" << std::endl;
                std::cout << "2. Right" << std::endl;
                std::cout << "3. Left" << std::endl;
                std::cout << "4. Bottom" << std::endl;
                std::cout << "5. Exit Game" << std::endl;
                std::cin >> roomChoice;
                roomCh = inputVal(roomChoice);

                if (roomCh == 5) {
                    std::cout << "So, you want to stop. Let's stop!" << std::endl;
                } else {

                    if (current == rtRoom1) {
                        house[14][16] = ' ';
                    } else if (current == rtRoom2) {
                        house[5][16] = ' ';
                    } else if (current == bdRoom1) {
                        house[5][6] = ' ';
                    } else if (current == bdRoom2) {
                        house[5][26] = ' ';
                    } else if (current == sdRoom1) {
                        house[14][6] = ' ';
                    } else if (current == sdRoom2) {
                        roof[3][6] = ' ';
                    } else if (current == kitchen) {
                        house[14][26] = ' ';
                    }
                    /**************************************
                    if (you->getLocate() == rtRoom1) {
                        house[14][16] = ' ';
                    } else if (you->getLocate() == rtRoom2) {
                        house[5][16] = ' ';
                    } else if (you->getLocate() == bdRoom1) {
                        house[5][6] = ' ';
                    } else if (you->getLocate() == bdRoom2) {
                        house[5][26] = ' ';
                    } else if (you->getLocate() == sdRoom1) {
                        house[14][6] = ' ';
                    } else if (you->getLocate() == sdRoom2) {
                        roof[3][6] = ' ';
                    } else if (you->getLocate() == kitchen) {
                        house[14][26] = ' ';
                    }
                    *********************************/
                    whereTo(current,roomCh);
                    //whereTo(you->getLocate(), roomCh);
                    std::cout << std::endl;

                    if (current == rtRoom1) {
                        showMap(roof, house, RSIZE, HSIZE, 14, 16);
                    } else if (current == rtRoom2) {
                        showMap(roof, house, RSIZE, HSIZE, 5, 16);
                    } else if (current == bdRoom1) {
                        showMap(roof, house, RSIZE, HSIZE, 5, 6);
                    } else if (current == bdRoom2) {
                        showMap(roof, house, RSIZE, HSIZE, 5, 26);
                    } else if (current == sdRoom1) {
                        showMap(roof, house, RSIZE, HSIZE, 14, 6);
                    } else if (current == sdRoom2) {
                        showMap(roof, house, RSIZE, HSIZE, 3, 6);
                    } else if (current == kitchen) {
                        showMap(roof, house, RSIZE, HSIZE, 14, 26);
                    }

                   /************************************************
                    if (you->getLocate() == rtRoom1) {
                        showMap(roof, house, RSIZE, HSIZE, 14, 16);
                    } else if (you->getLocate() == rtRoom2) {
                        showMap(roof, house, RSIZE, HSIZE, 5, 16);
                    } else if (you->getLocate() == bdRoom1) {
                        showMap(roof, house, RSIZE, HSIZE, 5, 6);
                    } else if (you->getLocate() == bdRoom2) {
                        showMap(roof, house, RSIZE, HSIZE, 5, 26);
                    } else if (you->getLocate() == sdRoom1) {
                        showMap(roof, house, RSIZE, HSIZE, 14, 6);
                    } else if (you->getLocate() == sdRoom2) {
                        showMap(roof, house, RSIZE, HSIZE, 3, 6);
                    } else if (you->getLocate() == kitchen) {
                        showMap(roof, house, RSIZE, HSIZE, 14, 26);
                    }
                    ************************************************/
                    std::cout << "Now you moved to " << current->getName() << std::endl;
                    current->description(you);
                    //you->getLocate()->description(you);
                    std::cout << std::endl;

                }
                step++;
                you->setStrength(you->getStrength() - 1);

            } while (you->getStrength() > 0 && roomCh != 5 && step < 7 && !(you->gotUSB));

            if (you->gotUSB) {

                std::cout<<"**************************"<<std::endl;
                std::cout<<"    CONGRATULATIONS!       "<<std::endl;
                std::cout<<"**************************"<<std::endl;
                std::cout << "Wow, you got it! You left the house without being interrupted" << std::endl;
                std::cout << "Congratulations! Now you will be rich." << std::endl;

            } else if (step >= 7) {
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

        for (int k = 0; k < RSIZE; k++) {
            delete[] roof[k];
        }
        delete[] roof;

        for (int m = 0; m < HSIZE; m++) {
            delete[] house[m];
        }
        delete[] house;

        std::cout << "\nDo you want to play again? If so, input 1. Otherwise click any keys" << std::endl;
        std::cin >> playAg;

    }while(playAg == 1);

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
                std::cout << "You chose the dead-end. Please choose again: ";
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
                std::cout << "You chose the dead-end. Please choose again: ";
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
                std::cout << "You chose the dead-end. Please choose again: ";
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
                std::cout << "You chose the dead-end. Please choose again: ";
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
                std::cout << "You chose the dead-end. Please choose again: ";
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
                std::cout << "You chose the dead-end. Please choose again: ";
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
                std::cout << "You chose the dead-end. Please choose again: ";
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
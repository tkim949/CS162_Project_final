//
// Created by Taekyoung Kim on 2019-03-05.
//

#ifndef FP_GAME_H
#define FP_GAME_H
#include "Space.h"
#include "Character.h"

class Game {

private:
    Character *you;
    Character *sMom;
    Character *sBro;
    Space *rtRoom1;
    Space *rtRoom2;
    Space *bdRoom1;
    Space *bdRoom2;
    Space *sdRoom1;
    Space *sdRoom2;
    Space *kitchen;
    Space *current;

public:

    Game();
    ~Game();
    //void drawMap(char& **r, char& **h, int RSIZE, int HSIZE);
    void play();
    void whereTo(Space *room, int choice);

};


#endif //FP_GAME_H

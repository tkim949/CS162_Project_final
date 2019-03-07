//
// Created by Taekyoung Kim on 2019-03-05.
//

#ifndef FP_SPACE_H
#define FP_SPACE_H
#include <iostream>
#include "Character.h"
class Character;

class Space {

protected:
    std::string sName;
    Space *top = nullptr;
    Space *right = nullptr;
    Space *left = nullptr;
    Space *bottom = nullptr;

    //std::string description;


public:
    Space();
    virtual ~Space();
    Space* getTop();
    Space* getBottom();
    Space* getRight();
    Space* getLeft();
    virtual std::string getName() const;
    virtual void setTop(Space *ptr);
    virtual void setBottom(Space *ptr);
    virtual void setRight(Space *ptr);
    virtual void setLeft(Space *ptr);
    virtual void setName(std::string na);
    virtual void description(Character *cha) = 0;

    bool isOpen = false;
    bool hasUSB = false;
};


#endif //FP_SPACE_H

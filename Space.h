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
    bool isUSB = false;
    bool isItem = false;


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
    virtual void description(Character *cha, int num) = 0;
    virtual bool getIsUSB();
    virtual void setIsUSB(bool usb);
    virtual bool getIsItem();
    virtual void setIsItem(bool item);


};


#endif //FP_SPACE_H

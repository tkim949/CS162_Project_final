//
// Created by Taekyoung Kim on 2019-03-05.
//

#ifndef FP_BEDROOM_H
#define FP_BEDROOM_H
#include "Space.h"
#include "Character.h"

class Bedroom :
        public Space
{

private:
    bool doneF = false;
    bool doneS = false;
    bool doneT = false;

public:
    Bedroom();
    ~Bedroom() override;
    void description(Character *cha, int hiddenP) override;

};


#endif //FP_BEDROOM_H

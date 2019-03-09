//
// Created by Taekyoung Kim on 2019-03-05.
//

#ifndef FP_KITCHEN_H
#define FP_KITCHEN_H
#include "Space.h"
#include "Character.h"

class Kitchen :
        public Space

{
private:

    bool doneF = false;
    bool doneS = false;
    bool doneT = false;

public:
    Kitchen();
    ~Kitchen() override;
    void description(Character *cha, int hiddenP) override;
};

#endif //FP_KITCHEN_H

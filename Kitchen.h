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

public:
    Kitchen();
    ~Kitchen() override;
    void description(Character *cha) override;
};


#endif //FP_KITCHEN_H

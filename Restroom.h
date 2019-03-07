//
// Created by Taekyoung Kim on 2019-03-05.
//

#ifndef FP_RESTROOM_H
#define FP_RESTROOM_H
#include "Space.h"
#include "Character.h"

class Restroom :
        public Space
{
private:

public:
    Restroom();
    ~Restroom() override;
    void description(Character *cha) override;
};


#endif //FP_RESTROOM_H

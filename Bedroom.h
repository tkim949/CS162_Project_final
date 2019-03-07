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

public:
    Bedroom();
    ~Bedroom() override;
    void description(Character *cha) override;

};


#endif //FP_BEDROOM_H

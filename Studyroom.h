//
// Created by Taekyoung Kim on 2019-03-05.
//

#ifndef FP_STUDYROOM_H
#define FP_STUDYROOM_H
#include "Space.h"
#include "Character.h"

class Studyroom :
        public Space
{

private:

public:
    Studyroom();
    ~Studyroom() override;
    void description(Character *cha) override;

};


#endif //FP_STUDYROOM_H

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
    bool doneF =false;
    bool doneS = false;
    bool doneT = false;

public:
    Studyroom();
    ~Studyroom() override;
    void description(Character *cha, int hiddenP) override;

};


#endif //FP_STUDYROOM_H

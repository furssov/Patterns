//
// Created by user on 28.02.23.
//

#ifndef LAB4_STAR_H
#define LAB4_STAR_H


#include "Figure.h"

class Star : public Figure{
public:
    Star(float x, float y);

    Figure *clone() override;
};


#endif //LAB4_STAR_H

//
// Created by user on 28.02.23.
//

#ifndef LAB4_LINE_H
#define LAB4_LINE_H


#include "Figure.h"

class Line : public Figure{
public:
    Line(float w, float y);

    Figure *clone() override;
};


#endif //LAB4_LINE_H

//
// Created by user on 09.02.23.
//

#ifndef LAB4_RECTANGLE_H
#define LAB4_RECTANGLE_H

#include "Figure.h"



class Rectangle : public Figure{



public:

    Rectangle(float w, float h);

    Figure *clone() override;
};
#endif //LAB4_RECTANGLE_H

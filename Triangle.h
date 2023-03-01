//
// Created by user on 09.02.23.
//

#ifndef LAB4_TRIANGLE_H
#define LAB4_TRIANGLE_H


#include "Figure.h"

class Triangle : public Figure{



public:

    Triangle(float w1, float h1);

    Figure *clone() override;


};


#endif //LAB4_TRIANGLE_H

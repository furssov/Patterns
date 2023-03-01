//
// Created by user on 08.02.23.
//

#ifndef LAB4_CIRCLE_H
#define LAB4_CIRCLE_H
#include "Figure.h"


class Circle : public Figure{


public:
    Circle(float w1, float h1);

    Figure *clone()  override;

};



#endif //LAB4_CIRCLE_H

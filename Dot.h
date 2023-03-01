//
// Created by user on 28.02.23.
//

#ifndef LAB4_DOT_H
#define LAB4_DOT_H


#include "Figure.h"

class Dot : public Figure{

public:
    Dot(float w, float h);

    Figure *clone()  override;
};


#endif //LAB4_DOT_H

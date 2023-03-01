//
// Created by user on 01.03.23.
//

#ifndef LAB4_SNAPSHOT_H
#define LAB4_SNAPSHOT_H


#include "Figure.h"

class Snapshot {
private:
    Figure *figure;

    bool isCopy;

    Shape *shape = NULL;

    bool selected;

    float x;
    float y;

    bool scale = true;

    bool m_isStopped;
    sf::Vector2f m_direction;

public:


    void restore();

    Snapshot(Figure figure, bool b, Shape *pShape, bool b1, float d, float d1, bool b2, bool b3, Vector2f vector2);
};


#endif //LAB4_SNAPSHOT_H

//
// Created by user on 01.03.23.
//

#include "Snapshot.h"



void Snapshot::restore() {
    figure->set_copy(isCopy);
    figure->set_shape(shape);
    if (selected) figure->select();
    else figure->deselect();
    figure->setX(x);
    figure->setY(y);
    figure->setScale(scale);
    figure->setStopped(m_isStopped);
    figure->setMDirection(m_direction);

}



Snapshot::Snapshot(Figure figure, bool b, Shape *pShape, bool b1, float d, float d1, bool b2, bool b3,
                   Vector2f vector2) {

}

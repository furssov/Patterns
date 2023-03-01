//
// Created by user on 09.02.23.
//

#include "Triangle.h"



Triangle::Triangle(float w1, float h1) : Figure(w1, h1) {
    set_shape(new CircleShape(50, 3));
    get_shape()->setFillColor(Color::White);

    deselect();
    get_shape()->setPosition(w1, h1);

}

Figure *Triangle::clone()  {
    Triangle *t =new Triangle(*this);
    t->set_shape(new CircleShape(50, 3));
    t->deselect();
    t->get_shape()->setPosition(get_shape()->getPosition().x, get_shape()->getPosition().y);
    t->get_shape()->setFillColor(get_shape()->getFillColor());
    return t;
}





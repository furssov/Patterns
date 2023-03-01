//
// Created by user on 08.02.23.
//

#include "Circle.h"

Circle::Circle(float w1, float h1) : Figure(w1, h1) {

    set_shape(new CircleShape(50));
    get_shape()->setFillColor(Color::White);
    get_shape()->setPosition(w1, h1);

    deselect();

}

Figure *Circle::clone()  {
    Circle *c = new Circle(*this);
    c->set_shape(new CircleShape(50));
    c->get_shape()->setPosition(get_shape()->getPosition().x, get_shape()->getPosition().y);
    c->deselect();
    c->get_shape()->setFillColor(get_shape()->getFillColor());
    return c;
}

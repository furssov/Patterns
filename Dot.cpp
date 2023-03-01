//
// Created by user on 28.02.23.
//

#include "Dot.h"

Dot::Dot(float w, float h) : Figure(w, h) {
    set_shape(new CircleShape(5));
    get_shape()->setFillColor(Color::White);

    get_shape()->setPosition(w, h);
    deselect();
}

Figure *Dot::clone()  {
    Dot *d = new Dot(*this);
    d->set_shape(new CircleShape(5));
    d->deselect();
    d->get_shape()->setPosition(get_shape()->getPosition().x, get_shape()->getPosition().y);
    d->get_shape()->setFillColor(get_shape()->getFillColor());
    d->get_shape()->setFillColor(get_shape()->getFillColor());

    return d;
}

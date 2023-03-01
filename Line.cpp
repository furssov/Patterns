//
// Created by user on 28.02.23.
//

#include "Line.h"

Line::Line(float w, float y) : Figure(w, y) {
    set_shape(new RectangleShape(Vector2f(100, 10)));
    get_shape()->setFillColor(Color::White);

    get_shape()->setPosition(w, y);
    deselect();
}

Figure *Line::clone()  {
    Line *l = new Line(*this);
    l->set_shape(new RectangleShape(Vector2f(100, 10)));
    l->deselect();
    l->get_shape()->setPosition(get_shape()->getPosition().x, get_shape()->getPosition().y);
    l->get_shape()->setFillColor(get_shape()->getFillColor());

    return l;
}

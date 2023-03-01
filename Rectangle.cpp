//
// Created by user on 09.02.23.
//

#include "Rectangle.h"


Rectangle::Rectangle(float w1, float h1) : Figure(w1, h1) {
    set_shape(new RectangleShape(Vector2f(50, 60)));
    get_shape()->setPosition(w1, h1);
    get_shape()->setFillColor(Color::White);

    deselect();

}

Figure *Rectangle::clone()  {
    Rectangle *r = new Rectangle(*this);
    r->set_shape(new RectangleShape(Vector2f(50, 60)));
    r->deselect();
    r->get_shape()->setPosition(get_shape()->getPosition().x, get_shape()->getPosition().y);
    r->get_shape()->setFillColor(get_shape()->getFillColor());

    return r;
}

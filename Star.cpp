//
// Created by user on 28.02.23.
//

#include "Star.h"

Star::Star(float x, float y) : Figure(x, y) {
    set_shape(new ConvexShape());
    dynamic_cast<ConvexShape*>(get_shape())->setPointCount(10);
    dynamic_cast<ConvexShape*>(get_shape())->setPoint(0, sf::Vector2f(60, 0));
    dynamic_cast<ConvexShape*>(get_shape())->setPoint(1, sf::Vector2f(72, 40));
    dynamic_cast<ConvexShape*>(get_shape())->setPoint(2, sf::Vector2f(110, 40));
    dynamic_cast<ConvexShape*>(get_shape())->setPoint(3, sf::Vector2f(80, 60));
    dynamic_cast<ConvexShape*>(get_shape())->setPoint(4, sf::Vector2f(100, 100));
    dynamic_cast<ConvexShape*>(get_shape())->setPoint(5, sf::Vector2f(60, 70));
    dynamic_cast<ConvexShape*>(get_shape())->setPoint(6, sf::Vector2f(20, 100));
    dynamic_cast<ConvexShape*>(get_shape())->setPoint(7, sf::Vector2f(40, 60));
    dynamic_cast<ConvexShape*>(get_shape())->setPoint(8, sf::Vector2f(10, 40));
    dynamic_cast<ConvexShape*>(get_shape())->setPoint(9, sf::Vector2f(48, 40));

    get_shape()->setFillColor(Color::White);
    get_shape()->setPosition(x, y);


}

Figure *Star::clone()  {
    Star *s = new Star(*this);
    s->set_shape(new ConvexShape());
    dynamic_cast<ConvexShape*>(s->get_shape())->setPointCount(10);
    dynamic_cast<ConvexShape*>(s->get_shape())->setPoint(0, sf::Vector2f(60, 0));
    dynamic_cast<ConvexShape*>(s->get_shape())->setPoint(1, sf::Vector2f(72, 40));
    dynamic_cast<ConvexShape*>(s->get_shape())->setPoint(2, sf::Vector2f(110, 40));
    dynamic_cast<ConvexShape*>(s->get_shape())->setPoint(3, sf::Vector2f(80, 60));
    dynamic_cast<ConvexShape*>(s->get_shape())->setPoint(4, sf::Vector2f(100, 100));
    dynamic_cast<ConvexShape*>(s->get_shape())->setPoint(5, sf::Vector2f(60, 70));
    dynamic_cast<ConvexShape*>(s->get_shape())->setPoint(6, sf::Vector2f(20, 100));
    dynamic_cast<ConvexShape*>(s->get_shape())->setPoint(7, sf::Vector2f(40, 60));
    dynamic_cast<ConvexShape*>(s->get_shape())->setPoint(8, sf::Vector2f(10, 40));
    dynamic_cast<ConvexShape*>(s->get_shape())->setPoint(9, sf::Vector2f(48, 40));
    s->deselect();
    s->get_shape()->setPosition(get_shape()->getPosition().x, get_shape()->getPosition().y);
    s->get_shape()->setFillColor(get_shape()->getFillColor());

    return s;
}

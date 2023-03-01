//
// Created by user on 08.02.23.
//

#include <fstream>
#include "Figure.h"

void Figure::add(Figure *f) {

}

Figure::Figure(float w, float h) {
    x = w;
    y = h;
    m_isStopped = false;
}

void Figure::visible() {
    shape->setOutlineThickness(10);
    shape->setFillColor(Color::Green);
}

void Figure::not_visible() {
    shape->setFillColor(Color::Black);
    shape->setOutlineThickness(0);
}

void Figure::change_color(Color color) {
    shape->setFillColor(color);
}

void Figure::set_first_pos() {
    shape->setPosition(x, y);
}

void Figure::draw(RenderWindow *window) {
    window->draw(*shape);
}

float Figure::getX() const {
    return x;
}

void Figure::setX(float x) {
    Figure::x = x;
}

float Figure::getY() const {
    return y;
}

void Figure::setY(float y) {
    Figure::y = y;
}

void Figure::select() {
    selected = true;
    shape->setOutlineThickness(10);
    shape->setOutlineColor(Color::Red);
}

void Figure::deselect() {
    selected = false;
    shape->setOutlineThickness(0);
}

void Figure::move(float x, float y) {
    if (!m_isStopped) {
        sf::Vector2f currentPosition = shape->getPosition();
        sf::Vector2f newPosition = currentPosition + sf::Vector2f(x, y);

        bool hitEdge = false;
        if (newPosition.x < 0) {
            newPosition.x = 0;
            hitEdge = true;
        } else if (newPosition.x > m_windowWidth - shape->getGlobalBounds().width) {
            newPosition.x = m_windowWidth - shape->getGlobalBounds().width;
            hitEdge = true;
        }
        if (newPosition.y < 0) {
            newPosition.y = 0;
            hitEdge = true;
        } else if (newPosition.y > m_windowHeight - shape->getGlobalBounds().height) {
            newPosition.y = m_windowHeight - shape->getGlobalBounds().height;
            hitEdge = true;
        }

        if (hitEdge) {
            if (m_direction == sf::Vector2f(1.f, 0.f)) {
                m_direction = sf::Vector2f(0.f, 1.f);
            } else if (m_direction == sf::Vector2f(0.f, 1.f)) {
                m_direction = sf::Vector2f(-1.f, 0.f);
            } else if (m_direction == sf::Vector2f(-1.f, 0.f)) {
                m_direction = sf::Vector2f(0.f, -1.f);
            } else {
                m_direction = sf::Vector2f(1.f, 0.f);
            }
        }

        shape->setPosition(newPosition);
    }
}

int Figure::getMWindowWidth() const {
    return m_windowWidth;
}

int Figure::getMWindowHeight() const {
    return m_windowHeight;
}

Shape *Figure::get_shape() {
    return shape;
}

bool Figure::isSelected() {
    return selected;
}

void Figure::set_shape(Shape *s) {
    shape = s;
}

void Figure::set_copy(bool c) {
    isCopy = c;
}

void Figure::remove(Figure *f) {

}

void Figure::deformation() {
    Vector2f v=shape->getScale();
    if(scale == true) {
        shape->setScale(2, 1);
        scale = false;
    } else{
        shape->setScale(1, 1);
        scale = true;
    }

}

Figure *Figure::make_trace() {
    Figure *f = this->clone();
    f->set_copy(true);
    return f;
}

bool Figure::intersects(Figure *other) {
    bool x = false ;
    if (other->get_shape() != NULL) {
        return this->get_shape()->getGlobalBounds().intersects(other->get_shape()->getGlobalBounds());
    } else if (other->get_shape() == NULL)
    {
        for (Figure *in : *other->getFigures())
        {
            if (in->get_shape() == NULL)
            {
                if (intersects(in)) x = true;
                else
                {
                    continue;
                }
            }
            else  if ( this->get_shape()->getGlobalBounds().intersects(in->get_shape()->getGlobalBounds()))
            {
                return true;
            }
        }
        return x;
    }

    return false;

}

bool Figure::change_color_if_intersect(std::list<Figure *> figures) {
    bool intersected = false;
    for (Figure* other : figures) {
        if (this != other && this->intersects(other)) {
            intersected = true;
            break;
        }
    }
    if (intersected) {
        change_color(Color::Yellow);
    }
    return intersected;
}

std::list<Figure *> *Figure::getFigures() {
    return nullptr;
}

void Figure::setStopped(bool b) {
    m_isStopped = b;
}

Figure::~Figure() {
    delete shape;
}

bool Figure::isScale() const {
    return scale;
}

void Figure::setScale(bool scale) {
    Figure::scale = scale;
}

 Vector2f Figure::getMDirection()  {
    return m_direction;
}

void Figure::setMDirection(const Vector2f &mDirection) {
    m_direction = mDirection;
}

Snapshot* Figure::make_snapshot() {
    return new Snapshot(this, isCopy, shape, selected, x, y, scale, m_isStopped, m_direction);
}

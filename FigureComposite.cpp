//
// Created by user on 20.02.23.
//

#include "FigureComposite.h"


void FigureComposite::remove(Figure *f) {
    figures->clear();
}
/*
Figure *FigureComposite::clone() {
    FigureComposite *clone = new FigureComposite(10,10);
    for (Figure *f : *getFigures())
    {
        clone->getFigures()->push_back(f->clone());
    }
    return clone;
}
 */

void FigureComposite::add(Figure *f) {
    figures->push_back(f);
}

void FigureComposite::move(float x, float y) {
    bool hitEdge = false;
    for (Figure* f : *getFigures()) {
        if (f->get_shape() == nullptr) {
            FigureComposite* composite = dynamic_cast<FigureComposite*>(f);
            composite->move(x, y);
            continue;
        }

        sf::Vector2f currentPosition = f->get_shape()->getPosition();
        sf::Vector2f newPosition = currentPosition + sf::Vector2f(x, y);

        float left = newPosition.x;
        float top = newPosition.y;
        float right = left + f->get_shape()->getGlobalBounds().width;
        float bottom = top + f->get_shape()->getGlobalBounds().height;

        // Check if the figure is outside the screen boundaries
        if (left < 0 || right > getMWindowWidth() || top < 0 || bottom > getMWindowHeight()) {
            hitEdge = true;

            // Check if the figure is crossing the left or right edge of the screen
            if ((left < 0 && x > 0) || (right > getMWindowWidth() && x < 0)) {
                x = -x;
            }

            // Check if the figure is crossing the top or bottom edge of the screen
            if ((top < 0 && y > 0) || (bottom > getMWindowHeight() && y < 0)) {
                y = -y;
            }
        }
        f->move(x, y);
    }

    // Stop the movement of all figures if at least one of them reaches the edge of the screen
    stop_all(hitEdge, *getFigures());
}

void FigureComposite::stop_all(bool b, list<Figure*> figures)
{
    for (Figure* f : figures ) {
        if (f->get_shape() != NULL)
        f->setStopped(b);
        else
            stop_all(b, *f->getFigures());
    }
}

list<Figure *> *FigureComposite::getFigures()  {
    return figures;
}

void FigureComposite::draw(RenderWindow *window) {
    for (Figure *f : *getFigures())
    {
        f->draw(window);
    }
}

void FigureComposite::select() {
    for (Figure *f : *getFigures())
    {
        f->select();
    }
}

void FigureComposite::deselect() {
    for (Figure *f : *getFigures())
    {
        f->deselect();
    }
}

void FigureComposite::change_color(Color color) {
    for (Figure *f : *getFigures())
    {
        f->change_color(color);
    }
}
/*
Figure *FigureComposite::make_trace() {
    FigureComposite *trace = new FigureComposite(10, 10);
    for (Figure *f : *getFigures())
    {
        trace->getFigures()->push_back(f->make_trace());
    }
    return trace;
}
 */



void FigureComposite::setFigures(list<Figure *> *figures) {
    FigureComposite::figures = figures;
}

Figure * FigureComposite::clone() {
    FigureComposite *figureComposite = new FigureComposite(*this);
    figureComposite->setFigures(nullptr);
    list<Figure *> *l = new list<Figure *>();
    for (Figure *f : *getFigures())
    {
        l->push_back(f->clone());
    }
    figureComposite->setFigures(l);
    return figureComposite;
}

void FigureComposite::deformation() {
    for (Figure *f : *getFigures())
    {
        f->deformation();
    }
}

void FigureComposite::visible() {
    for (Figure *f : *getFigures())
    {
        f->visible();
    }
}

void FigureComposite::not_visible() {
    for (Figure *f : *getFigures())
    {
        f->not_visible();
    }
}

void FigureComposite::set_first_pos() {
    for (Figure *f : *getFigures())
    {
        f->set_first_pos();
    }
}

Figure *FigureComposite::make_trace() {
    FigureComposite *f = dynamic_cast<FigureComposite *>(this->clone());
    f->set_copy(true);

    return f;
}

FigureComposite::FigureComposite(float w, float h) : Figure(w, h) {
    figures = new list<Figure*>();
}

bool FigureComposite::intersects(Figure *other) {
    if (this->get_shape() == NULL && other->get_shape() == NULL) {
        for (Figure* in1 : *this->getFigures()) {
            for (Figure* in2 : *other->getFigures()) {
                if (in1->intersects(in2)) {
                    // При пересечении меняем цвет на желтый
                    this->change_color(Color::Yellow);
                    return true;
                }
            }
        }
        return false;
    } else if (this->get_shape() == NULL && other->get_shape() != NULL) {
        for (Figure* in : *this->getFigures()) {
            if (in->intersects(other)) {
                // При пересечении меняем цвет на желтый
                this->change_color(Color::Yellow);
                return true;
            }
        }
        return false;
    } else if (this->get_shape() != NULL && other->get_shape() == NULL) {
        for (Figure* in : *other->getFigures()) {
            if (this->intersects(in)) {
                // При пересечении меняем цвет на желтый
                this->change_color(Color::Yellow);
                return true;
            }
        }
        return false;
    } else {
        if (this->get_shape()->getGlobalBounds().intersects(other->get_shape()->getGlobalBounds())) {
            // При пересечении меняем цвет на желтый
            this->change_color(Color::Yellow);
            return true;
        }
        return false;
    }
}

FigureComposite::~FigureComposite() {
    delete figures;
}

Snapshot *FigureComposite::create_snap() {
    return new Snapshot(this);
}

void FigureComposite::set_figures(list<Figure *> *l) {
    figures = l;
}

bool FigureComposite::isSelected() {
    return figures->front()->isSelected();
}










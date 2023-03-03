//
// Created by user on 08.02.23.
//

#ifndef LAB4_FIGURE_H
#define LAB4_FIGURE_H
#include <SFML/Graphics.hpp>

#include <list>
#include <fstream>


using namespace sf;
using namespace std;


class Snapshot;

class Figure {
private:
    bool isCopy;

    Shape *shape = NULL;

    bool selected;

    float x;
    float y;

    bool scale = true;

    bool m_isStopped;
    Vector2f m_direction;
    int m_windowWidth = 1000;
    int m_windowHeight = 1000;

public:

     Vector2f getMDirection() ;

    void setMDirection(const Vector2f &mDirection);

    bool isScale() const;

    void setScale(bool scale);

    virtual void add(Figure *f) ;

    Figure(float w, float h) ;

    virtual void visible();

    virtual void not_visible() ;

    virtual void change_color(Color color);

    virtual void set_first_pos() ;

    virtual void draw(RenderWindow *window);

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    virtual void select();

    virtual void deselect();

    virtual void move(float x, float y);

    int getMWindowWidth() const ;

    int getMWindowHeight() const;

     Shape *get_shape();

    virtual bool isSelected();

    void set_shape(Shape *s);


    void set_copy(bool c);


    virtual void remove(Figure *f);

    virtual void deformation();

    virtual Figure* clone() = 0;

    virtual Figure *make_trace();

    virtual bool intersects(Figure* other) ;

    virtual bool change_color_if_intersect(std::list<Figure*> figures);

    virtual std::list<Figure*> *getFigures();

    void setStopped(bool b);

    virtual ~Figure();

    virtual Snapshot* create_snap();

    virtual void set_figures(list<Figure*> *l){}
};

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
    list<Figure*> *composites = nullptr;

public:

    Figure *get_figure()
    {
        return figure;
    }

    void restore()
    {       if (figure->getFigures() == nullptr) {
            figure->set_copy(isCopy);
            figure->set_shape(shape);
            if (selected)
                figure->select();
            else figure->deselect();
            figure->setX(x);
            figure->setY(y);
            figure->setScale(scale);
            figure->setStopped(m_isStopped);
            figure->setMDirection(m_direction);
            figure->get_shape()->setPosition(m_direction.x, m_direction.y);
        } else
        {
            this->figure->set_figures(composites);
        }


    }

    Snapshot(Figure *f)
    {
        if (f->getFigures() != nullptr)
        {
            composites = new list<Figure*>();
            this->figure = f;
            for (Figure *child : *figure->getFigures())
            {
                Figure *c = child->clone();
                if (child->isSelected()) c->select();
                composites->push_front(c);
            }
        }
    }


    Snapshot(Figure *figure, bool isCopy, Shape *shape, bool selected, float x, float y, bool scale, bool mIsStopped,
             const Vector2f &mDirection)
    {
        this->figure = figure;
        this->isCopy = isCopy;
        this->shape = shape;
        this->selected = selected;
        this->x = x;
        this->y = y;
        this->scale = scale;
        this->m_isStopped = mIsStopped;
        this->m_direction = mDirection;
    }




};


#endif //LAB4_FIGURE_H

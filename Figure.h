//
// Created by user on 08.02.23.
//

#ifndef LAB4_FIGURE_H
#define LAB4_FIGURE_H
#include <SFML/Graphics.hpp>

#include <list>
#include "Snapshot.h"


using namespace sf;
using namespace std;
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

     Snapshot* make_snapshot();

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

    bool isSelected();

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

};


#endif //LAB4_FIGURE_H

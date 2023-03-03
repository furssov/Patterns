//
// Created by user on 20.02.23.
//

#ifndef LAB4_FIGURECOMPOSITE_H
#define LAB4_FIGURECOMPOSITE_H
#include "Figure.h"

using namespace std;
class FigureComposite : public Figure{
private:
    list<Figure*> *figures;
public:
    Snapshot *create_snap() override;

    ~FigureComposite() override;

    FigureComposite(float w, float h) ;

    void set_first_pos() override;

    void visible() override;

    void not_visible() override;

    void deformation() override;

    void remove(Figure *f) override;

    Figure *make_trace() override;

    void add(Figure *f) override;

    void select() override;

    void set_figures(list<Figure *> *l) override;

    bool isSelected() override;

    void deselect() override;

    void move(float x, float y) override;

    list<Figure *> *getFigures() override;

    void draw(RenderWindow *window) override;

    void change_color(Color color) override;

    void setFigures(list<Figure *> *figures);

    virtual bool intersects(Figure* other) ;

    void stop_all(bool b, list<Figure *> figures);

    Figure * clone() override;
};


#endif //LAB4_FIGURECOMPOSITE_H

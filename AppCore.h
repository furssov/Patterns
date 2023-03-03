//
// Created by user on 08.02.23.
//

#ifndef LAB4_APPCORE_H
#define LAB4_APPCORE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "FigureComposite.h"
#include "Dot.h"
#include "Line.h"
#include "Star.h"

using namespace sf;
using namespace std;
class AppCore {
public:



    void start();

    virtual ~AppCore() ;

    AppCore(AppCore *another) = delete;

    void operator=(const AppCore a) = delete;

    static AppCore *get_instance(int w, int h);


protected:
    AppCore(int w, int h);

    static AppCore* appCore;

private:

   // list<Snapshot*> *snapshots;

    RenderWindow *window;

    list<Figure*> *alive_figures;

    unordered_map<int , Figure*> *unordered_map_of_prototypes;

    Figure *trace = NULL;


    Figure *current = NULL;

    FigureComposite *figureComposite;

    void take_snapshots();

    void rollback();

    bool is_in_composite = false;

    bool select(list<Figure *> *figures);

    void update(int e);

    void move_current_figure();

    void add(Figure *f);

    void remove(Figure *f);

    void draw();

    void create_figure_by_prototype();



};


#endif //LAB4_APPCORE_H

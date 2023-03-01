//
// Created by user on 08.02.23.
//

#include "AppCore.h"


AppCore *AppCore::get_instance(int w, int h) {
    if (appCore == nullptr)
    {
        appCore = new AppCore(w, h);
    }
    return appCore;
}
AppCore *AppCore::appCore = nullptr;

void AppCore::create_figure_by_prototype() {
    Figure *f = current->clone();
    add(f);
}

void AppCore::remove(Figure *f) {
    f->deselect();
    if (f == figureComposite)
    {
        figureComposite->remove(f);
    }
    alive_figures->remove(f);
    trace = NULL;
}

void AppCore::move_current_figure() {
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        current->move(-0.1, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        current->move(0, -0.1);
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        current->move(0, 0.1);
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        current->move(0.1, 0);
    }
}

void AppCore::add(Figure *f) {
    alive_figures->push_back(f);
}

void AppCore::draw() {
    window->clear();

    for (Figure *f : *alive_figures)
    {
        f->draw(window);
    }

    if(figureComposite!=NULL)
        figureComposite->draw(window);

    if (trace != NULL) {
        trace->draw(window);
    }

    window->display();
}
    bool AppCore::select(list<Figure *> *figures) {
        Vector2i pixel_pos = Mouse::getPosition(*window);
        Vector2f pos = window->mapPixelToCoords(pixel_pos);
        for (Figure *f : *figures)
        {
            if (f->get_shape() == NULL)
            {
                if (select(f->getFigures()))
                {
                    current = f;
                    current->select();
                    return true;
                }
            }
            else
            {
                if (f->get_shape()->getGlobalBounds().contains(pos.x,pos.y))
                {
                    if (!f->isSelected() && current == NULL)
                    {
                        current = f;
                        current->select();
                        return true;
                    }
                    else
                    {
                        current->deselect();
                        current=NULL;
                        return false;
                    }
                }
            }
        }
        return false;
}



    void AppCore::update(int e)
    {
        Event ev;
        Vector2i pixel_pos = Mouse::getPosition(*window);
        Vector2f  pos = window->mapPixelToCoords(pixel_pos);
        int key = 0;


        while (window->pollEvent(ev))
        {
            if (ev.type == Event::Closed)
            {
                window->close();
            }

            if (ev.type == Event::MouseButtonPressed) {
                if (ev.key.code == Mouse::Left) {
                    select(alive_figures);
                }
            }


            if (Keyboard::isKeyPressed(Keyboard::Enter)) {

            }

            if (Keyboard::isKeyPressed(Keyboard::RShift)) {

            }


            //LEAF
            if (ev.type == Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::C) {
                    Circle *c = new Circle(pos.x, pos.y);
                    add(c);
                    unordered_map_of_prototypes->insert(make_pair(key++, c));

                }
            }


            if (ev.type == Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::R) {
                    Rectangle *r = new Rectangle(pos.x, pos.y);
                    add(r);
                    unordered_map_of_prototypes->insert(make_pair(key++, r));


                }
            }
            if (ev.type == Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::T) {
                    Triangle *t = new Triangle( pos.x, pos.y);
                    add(t);
                    unordered_map_of_prototypes->insert(make_pair(key++, t));


                }
            }
            if (ev.type == Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::D) {
                    Dot *d = new Dot( pos.x, pos.y);
                    add(d);
                    unordered_map_of_prototypes->insert(make_pair(key++, d));
                }
            }
            if (ev.type == Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::L) {
                    Line *l = new Line( pos.x, pos.y);
                    add(l);
                    unordered_map_of_prototypes->insert(make_pair(key++, l));

                }
            }
            if (ev.type == Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::P) {
                    Star *s = new Star( pos.x, pos.y);
                    add(s);
                    unordered_map_of_prototypes->insert(make_pair(key++, s));

                }
            }

        }

        if (current != NULL ) {
            //COMPOSITE

            if (Keyboard::isKeyPressed(Keyboard::A) && !is_in_composite) {
                is_in_composite = true;
                figureComposite = new FigureComposite(100, 100);
            }
            if (ev.type == Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::Escape) {
                    add(figureComposite);
                    is_in_composite = false;
                }
            }

            if (is_in_composite)
            {
                if (ev.type == Event::KeyReleased) {
                    if (ev.key.code == sf::Keyboard::F){
                        Figure *f = current->clone();
                        f->deselect();
                        figureComposite->add(f);
                    }}
            }
            current->change_color_if_intersect(*alive_figures);


            if (Keyboard::isKeyPressed(Keyboard::Numpad1)) {
                current->change_color(Color::Magenta);
            }


            if (Keyboard::isKeyPressed(Keyboard::Numpad2)) {
                current->change_color(Color::Yellow);
            }

            if (Keyboard::isKeyPressed(Keyboard::Numpad3)) {
                current->change_color(Color::Blue);
            }
            if (Keyboard::isKeyPressed(Keyboard::Numpad4)) {
                current->change_color(Color::Green);
            }




            if (ev.type == Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::S) {
                    trace = current->make_trace();
                }
            }

            if (ev.type == Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::F12) {
                    trace = NULL;
                }
            }

            if (ev.type == Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::Comma) {
                    create_figure_by_prototype();

                }
            }

            if (ev.type == Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::Delete) {
                    remove(current);
                }
            }

            if (ev.type == Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::B) {
                    current->deformation();
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::V)) {
                current->visible();
            }

            if (Keyboard::isKeyPressed(Keyboard::N)) {
                current->not_visible();
            }

            if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
                current->set_first_pos();
            }

            move_current_figure();
        }

    }

void AppCore::start() {
    Clock clock;
    while (window->isOpen())
    {
        int e = clock.restart().asMilliseconds();
        update(e);

        draw();
    }
}

AppCore::~AppCore() {
    delete window;
    delete trace;
    delete figureComposite;
    delete alive_figures;
}

AppCore::AppCore(int w, int h) {
    window = new RenderWindow(VideoMode(w, h), "App");
    alive_figures = new list<Figure*>();
    unordered_map_of_prototypes = new unordered_map<int, Figure*>();
}



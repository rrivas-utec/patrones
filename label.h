//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_LABEL_H
#define PATRONES_LABEL_H

#include "componente.h"
#include "render.h"
#include <SFML/Graphics.hpp>

class label_t: public componente_t {

public:
    using componente_t::componente_t;
    void draw () override {
        auto& canvas = render<sf::RenderWindow>::get_instance(
                sf::VideoMode(800, 600),
                "Patrones")->get();
        sf::RectangleShape shape({width, height});
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::Yellow);
        canvas->draw(shape);
    }

};


#endif //PATRONES_LABEL_H

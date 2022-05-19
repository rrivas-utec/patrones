//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_TEXT_BOX_H
#define PATRONES_TEXT_BOX_H

#include "componente.h"
#include "abstract_component.h"
#include "render.h"
#include <SFML/Graphics.hpp>

class text_box_t: public componente_t {

public:
    using componente_t::componente_t;
    void draw () override {
        auto canvas = render<sf::RenderWindow>::get_instance(
                sf::VideoMode(800, 600),
                "Patrones")->get();
        sf::RectangleShape shape({width, height});
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::Green);
        canvas->draw(shape);
    }
};


#endif //PATRONES_TEXT_BOX_H

//
// Created by rudri on 5/21/2022.
//

#ifndef PATRONES_SDL_BUTTON_H
#define PATRONES_SDL_BUTTON_H


#include "componente.h"
#include "render.h"
#include "SFML/Graphics.hpp"

class sdl_button_t: public componente_t {
    sf::Color color = sf::Color::White;
public:
    using componente_t::componente_t;
    void draw() override {
        auto& canvas = render<sf::RenderWindow>::get_instance()->get();
        sf::RectangleShape shape({width, height});
        shape.setPosition(x, y);
        shape.setFillColor(color);

        // Seleccionar el Fonts y crear el texto
        sf::Font font;
        sf::Text txt;
        if (font.loadFromFile("./Oxanium-Regular.ttf"))
        {
            txt.setFont(font);
            txt.setFillColor(sf::Color::Blue);
            txt.setCharacterSize(20);
            txt.setString(text);
            txt.setPosition(x , y);
            // Para centrar el texto en el recuadro
            const auto bounds(txt.getLocalBounds());
            const auto box(shape.getSize());
            txt.setOrigin((bounds.width - box.x) / 2 + bounds.left, (bounds.height - box.y) / 2 + bounds.top);
        }
        canvas->draw(shape);
        canvas->draw(txt);
    }
};

#endif //PATRONES_SDL_BUTTON_H

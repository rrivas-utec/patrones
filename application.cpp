//
// Created by rrivas on 18/05/2022.
//

#include <iostream>
#include <fstream>
#include "application.h"
#include "render.h"
#include "componente.h"
#include "abstract_factory.h"
#include "creator.h"

//#define SFML_PORTAL
#define SDL_PORTAL
#if defined(SFML_PORTAL)
    #include "sfml_factory.h"
#elif defined(SDL_PORTAL)
    #include "sdl_factory.h"
#endif

void application::run() {
    auto &window = render<sf::RenderWindow>::get_instance(sf::VideoMode(800, 600), "Patrones")->get();

    float prior_x = 0, prior_y = 0;
    float actual_x = 0, actual_y = 0;

    while (window->isOpen()) {
        sf::Event event{};
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    for (auto &[k, c]: componentes)
                        c->keypress_event({static_cast<char>('A' + event.key.code)});
                    break;
                case sf::Event::MouseMoved:
                    actual_x = static_cast<float>(event.mouseMove.x);
                    actual_y = static_cast<float>(event.mouseMove.y);
                    for (auto &[k, c]: componentes) {
                        if (c->is_on_bound(actual_x, actual_y))
                            c->mouse_enter_event({actual_x, actual_y});
                        else if (c->is_on_bound(prior_x, prior_y))
                            c->mouse_leave_event({actual_x, actual_y});
                    }
                    prior_x = actual_x;
                    prior_y = actual_y;
                    break;
                case sf::Event::MouseButtonPressed:
                    for (auto &[k, c]: componentes)
                        if (c->is_on_bound(prior_x, prior_y))
                            c->click_pressed_event({prior_x, prior_y});
                    break;
                case sf::Event::MouseButtonReleased:
                    for (auto &[k, c]: componentes)
                        if (c->is_on_bound(prior_x, prior_y))
                            c->click_released_event({prior_x, prior_y});
                    break;
                default:
                    break;
            }
        }
        window->clear(sf::Color::Blue);
        for (auto &[k, c]: componentes)
            c->draw();
        window->display();
    }

}

application::application() {
#define FACTORY
#if defined(ABSTRACT_FACTORY)
    build_components();
#elif defined(FACTORY)
    read_components();
#endif
}

void application::add_component(const string &key, const shared_ptr<componente_t> &com) {
    componentes.insert({key, com});
}

shared_ptr<abstract_factory> application::create_abstract_factory() {
#if defined(SFML_PORTAL)
    return make_shared<sfml_factory>();
#elif defined(SDL_PORTAL)
    return make_shared<sdl_factory>();
#endif

}

void application::build_components() {
    auto factory = create_abstract_factory();
    add_component("bnt1", factory->create_button("Button 1", 100, 100, 200, 60));
    add_component("lbl1", factory->create_label("Texto 1", 100, 400, 200, 60));
}

void application::read_components() {
    ifstream file("components.txt");
    string type, key, text;
    float x = 0, y = 0, w = 0, h = 0;
    auto factory = creator_t::get_instance();
    while (file >> type >> key >> text >> x >> y >> w >> h)
        add_component(key, factory->create(type, text, x, y, w, h));
}

void application::setup_events() {

}

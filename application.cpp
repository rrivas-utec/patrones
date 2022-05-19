//
// Created by rrivas on 18/05/2022.
//

#include "application.h"
#include "render.h"
#include "componente.h"
#include "button.h"
#include "text_box.h"
#include "label.h"

void application::run() {
    // create the window
    auto canvas = render<sf::RenderWindow>::get_instance(
            sf::VideoMode(800, 600),
            "Patrones")->get();
    // run the program as long as the window is open
    while (canvas->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (canvas->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                canvas->close();
        }
        // clear the window with black color
        canvas->clear(sf::Color::Blue);

        for (const auto& c: componentes)
            c->draw();
        // end the current frame
        canvas->display();
    }
}

application::application() {
    componentes.push_back(new button_t(100, 100, 200, 60));
    componentes.push_back(new label_t(100, 400, 200, 60));
    componentes.push_back(new text_box_t(400, 100, 200, 60));

}

//
// Created by rudri on 5/21/2022.
//

#ifndef PATRONES_SDL_FACTORY_H
#define PATRONES_SDL_FACTORY_H


#include "abstract_factory.h"
#include "sdl_button.h"
#include "sdl_label.h"

class sdl_factory: public abstract_factory{
    shared_ptr<componente_t> create_label(
            const string& text, float x, float y, float w, float h) override
    {
        return make_shared<sdl_label_t>(text, x, y, w, h);
    }
    shared_ptr<componente_t> create_button(
            const string& text, float x, float y, float w, float h) override
    {
        return make_shared<sdl_button_t>(text, x, y, w, h);
    }
};

#endif //PATRONES_SDL_FACTORY_H

//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_ABSTRACT_COMPONENT_H
#define PATRONES_ABSTRACT_COMPONENT_H

#include "componente.h"

struct abs_label_t: public componente_t {
    virtual void draw() = 0;
    using componente_t::componente_t;
};

struct abs_text_box_t: public componente_t {
    virtual void draw() = 0;
    using componente_t::componente_t;
};

struct abs_button_t: public componente_t {
    virtual void draw() = 0;
    using componente_t::componente_t;
};

#endif //PATRONES_ABSTRACT_COMPONENT_H

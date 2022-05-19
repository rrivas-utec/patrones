//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_GUI_FACTORY_H
#define PATRONES_GUI_FACTORY_H

#include "abstract_component.h"

struct gui_factory_t {
    virtual abs_text_box_t* create_text_box() = 0;
    virtual abs_label_t* create_label() = 0;
    virtual abs_button_t* create_button() = 0;
    virtual ~gui_factory_t() = default;
};
class gui_factory {

};


#endif //PATRONES_GUI_FACTORY_H

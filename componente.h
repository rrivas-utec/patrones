//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_COMPONENTE_H
#define PATRONES_COMPONENTE_H


class componente_t {
protected:
    float x = 0;
    float y = 0;
    float width = 0;
    float height = 0;
public:
    componente_t(float x, float y, float w, float h): x(x), y(y), width(w), height(h) {}
    virtual void draw() = 0;
};



#endif //PATRONES_COMPONENTE_H

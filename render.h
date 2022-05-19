//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_RENDER_H
#define PATRONES_RENDER_H

#include <SFML/Graphics.hpp>

template <typename T>
class render {
    // Atributo de objeto
    T* data = nullptr;

    // 1. Atributo de clase
    inline static render<T>* instance {};

    // 2. Ocultar el constructor
    template <typename ...Params>
    render(Params... params) {
        data = new T(params...);
    }

public:
    // 3. Crear o utilizar una instancia existe
    // Metodo de Clase --> Una sola puerta de acceso
    template <typename ...Params>
    static render<T>* get_instance(Params ...params) {
        if (instance == nullptr) instance = new render<T>(params...);
        return instance;
    }

    // Metodo de Objeto
    T* get() { return data; }
};


#endif //PATRONES_RENDER_H

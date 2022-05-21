//
// Created by rudri on 5/21/2022.
//

#ifndef PATRONES_FACTORY_H
#define PATRONES_FACTORY_H

#include <functional>
#include <string>
#include <unordered_map>
#include "componente.h"
#include "sfml_label.h"
#include "sfml_button.h"
using namespace std;

// Alias
using callback_t = function<shared_ptr<componente_t>(string, float, float, float, float)>;

// Factory
class factory_t {
private:
    unordered_map<string, callback_t> callbacks;
    inline static factory_t* instance {};
protected:
    factory_t() = default;
public:
    bool attach(const string& key, const callback_t& createFn) noexcept {
        return callbacks.insert({key, createFn}).second;
    }
    shared_ptr<componente_t> create(const string& key, const string& text,
                                    float left, float top,
                                    float width, float height) {
        return callbacks.at(key)(text, left, top, width, height);
    }

    // Metodo que reemplaza al constructor
    static factory_t* get_instance() noexcept {
        if (instance == nullptr) instance = new factory_t();
        return instance;
    }
};

// Registro de familia de Factories
namespace {
    auto f = factory_t::get_instance();

    auto rl = f->attach("label", [](const string& text,
                                    float left, float top, float width, float height) {
        return make_shared<sfml_label_t>(text, left, top, width, height); });

    auto rb = f->attach("button", [](const string& text,
                                     float left, float top, float width, float height) {
        return make_shared<sfml_button_t>(text, left, top, width, height); });
}

#endif //PATRONES_FACTORY_H

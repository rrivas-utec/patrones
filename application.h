//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_APPLICATION_H
#define PATRONES_APPLICATION_H

#include <memory>
#include <string>
#include <unordered_map>
#include "componente.h"
#include "abstract_factory.h"
using namespace std;

class application {
    unordered_map<string, shared_ptr<componente_t>> componentes;
public:
    application();
    void run();

    // Soporte para el abstract factory y factory
    void add_component(const string& key, const shared_ptr<componente_t>& com);

    // Patron Abstract Factory
    shared_ptr<abstract_factory> create_abstract_factory();
    void build_components();

    // Patron Factory
    void read_components();

    // Patron observer
    void setup_events();
};


#endif //PATRONES_APPLICATION_H

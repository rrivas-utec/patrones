//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_APPLICATION_H
#define PATRONES_APPLICATION_H

#include "componente.h"
#include <vector>
using namespace std;

class application {
    vector<componente_t*> componentes;
public:
    application();
    void run();
};


#endif //PATRONES_APPLICATION_H

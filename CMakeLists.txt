cmake_minimum_required(VERSION 3.19)
project(patrones)

set(CMAKE_CXX_STANDARD 17)

# Instrucciones para ubicar la libreria
set(SFML_ROOT "C:/SFML/v32/SFML-2.5.1")
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

# Buscar un nuevo paquete
find_package(SFML COMPONENTS graphics audio REQUIRED)

add_executable(patrones main.cpp render.cpp render.h application.cpp application.h componente.h button.cpp button.h label.cpp label.h text_box.cpp text_box.h gui_factory.cpp gui_factory.h abstract_component.cpp abstract_component.h)
target_link_libraries(patrones sfml-graphics sfml-audio)

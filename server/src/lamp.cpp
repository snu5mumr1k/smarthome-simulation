#include <src/lamp.h>

#include <iostream>

Lamp::Lamp(bool is_initially_on)
    : is_on_(is_initially_on)
{
}

void Lamp::DoStep() {
    if (is_on_) {
        std::cerr << "Lamp is on!" << std::endl;
    } else {
        std::cerr << "Lamp is off!" << std::endl;
    }
    is_on_ = !is_on_;
}

#include <lib/device/lamp.h>

#include <iostream>

Lamp::Lamp(bool is_initially_on)
    : is_on_(is_initially_on)
{
}

void Lamp::DumpState() const {
    if (is_on_) {
        std::cerr << "Lamp is on!" << std::endl;
    } else {
        std::cerr << "Lamp is off!" << std::endl;
    }
}

void Lamp::DoStep() {
    is_on_ = !is_on_;
}

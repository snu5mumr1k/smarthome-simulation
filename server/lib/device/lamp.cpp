#include "lamp.h"

#include <iostream>
#include <iomanip>

namespace {
    const Lamp::Voltage kVoltageLow = 0.0;
    const Lamp::Voltage kVoltageHigh = 220.0;

    const Lamp::Temperature kRoomTemperature = 22.5;
} //namespace

Lamp::Lamp()
    : is_on_(false)
    , voltage_(kVoltageLow)
    , temperature_(kRoomTemperature)
{
}

void Lamp::DumpState() const {
    std::cout << is_on_ << "\t";
    std::cout << temperature_ << std::endl;
}

void Lamp::DoStep() {
    if (is_on_) {
        voltage_ = kVoltageHigh;
        temperature_ += 1.0;
    } else {
        voltage_ = kVoltageLow;
        temperature_ -= 0.5;
    }
}

void Lamp::Handle() {
}

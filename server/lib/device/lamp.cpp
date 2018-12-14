#include <lib/device/lamp.h>

#include <iostream>

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
    if (is_on_) {
        std::cerr << "Lamp is on! ";
    } else {
        std::cerr << "Lamp is off! ";
    }
    std::cerr << "Temperature is " << temperature_ << std::endl;
}

void Lamp::DoStep() {
    is_on_ = !is_on_;
    if (is_on_) {
        voltage_ = kVoltageHigh;
        temperature_ += 1.0;
    } else {
        voltage_ = kVoltageLow;
        temperature_ -= 0.5;
    }
}

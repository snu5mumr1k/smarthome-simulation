#include <lib/device/kettle.h>

#include <cstdlib>
#include <iostream>

#define UNUSED(x) (void)x;

namespace {
    constexpr Kettle::Temperature kRoomTemperature = 22.5;
    constexpr Kettle::Temperature kBoilingPoint = 100.0;
} // namespace

Kettle::Kettle(Volume volume, Temperature temperature)
    : volume_(volume)
    , boiling_degrees_per_second_(2.0)
    , cooling_degrees_per_second_(0.5)
    , temperature_(temperature)
    , is_boiling_(false)
{
    UNUSED(volume_);
}

void Kettle::DoStep() {
    if (is_boiling_) {
        temperature_ += boiling_degrees_per_second_;
        if (temperature_ > kBoilingPoint) {
            is_boiling_ = false;
            temperature_ = kBoilingPoint;
        }
    } else {
        temperature_ -= cooling_degrees_per_second_;
        temperature_ = std::max(temperature_, kRoomTemperature);
    }
}

void Kettle::DumpState() const {
    std::cerr << is_boiling_ << "\t";
    std::cerr << temperature_ << std::endl;
}

void Kettle::Handle() {
    is_boiling_ = true;
}

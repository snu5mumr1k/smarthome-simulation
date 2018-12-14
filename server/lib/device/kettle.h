#pragma once

#include <lib/device/device.h>

#include <stdint.h>

class Kettle final : public Device {
public:
    // Represents Volume in millilitres
    using Volume = int64_t;
    // Represents Temperature in Celsius means
    using Temperature = double;

    Kettle(Volume volume, Temperature temperature);

    void DoStep() final;
    void DumpState() const final;

private:
    void LogState() const;

    const Volume volume_;
    const Temperature boiling_degrees_per_second_;
    const Temperature cooling_degrees_per_second_;

    Temperature temperature_;
    bool is_boiling_;
};

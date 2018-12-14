#pragma once

#include <lib/device/device.h>

class Lamp final : public Device {
public:
    using Temperature = double;
    using Voltage = double;

    Lamp();

    void DoStep() final;
    void DumpState() const final;

private:
    bool is_on_;

    Voltage voltage_;
    Temperature temperature_;
};

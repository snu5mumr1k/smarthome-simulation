#pragma once

#include <lib/device/device.h>

class Lamp final : public Device {
public:
    explicit Lamp(bool is_initially_on);

    void DoStep() final;

private:
    bool is_on_;
};

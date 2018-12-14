#pragma once

class Device {
public:
    virtual ~Device() = default;

    virtual void DoStep() = 0;
};

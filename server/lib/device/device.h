#pragma once

class Device {
public:
    enum class Type {
        kettle,
        lamp,
    };

    virtual ~Device() = default;

    virtual void DoStep() = 0;
    virtual void DumpState() const = 0;

    virtual void Handle() = 0;

    virtual Type GetType() const = 0;
};

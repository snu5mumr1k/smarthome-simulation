#pragma once

#include <chrono>
#include <memory>
#include <vector>

#include <lib/device/device.h>

class Simulator {
public:
    explicit Simulator(const std::chrono::seconds& min_cycle_duration);

    void Run();
    void AddDevice(std::unique_ptr<Device> device);

private:
    void DoStep() const;
    void ObtainMetrics() const;

    const std::chrono::seconds min_cycle_duration_;
    std::vector<std::unique_ptr<Device>> devices_;
};

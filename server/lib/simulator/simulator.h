#pragma once

#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include <lib/device/device.h>

class Simulator {
public:
    Simulator(const std::chrono::seconds& min_cycle_duration, std::string commands_file);

    void Run();
    void AddDevice(std::unique_ptr<Device> device);

private:
    void DoStep() const;
    void ObtainMetrics() const;
    bool ProcessCommands();

    const std::string commands_file_;

    const std::chrono::seconds min_cycle_duration_;
    std::vector<std::unique_ptr<Device>> devices_;
};

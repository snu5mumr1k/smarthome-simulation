#include <lib/simulator/simulator.h>

#include <thread>

#include <lib/device/device.h>

Simulator::Simulator(const std::chrono::seconds& min_cycle_duration)
    : min_cycle_duration_(min_cycle_duration)
    , devices_()
{
}

void Simulator::Run() {
    while (true) {
        const auto iteration_start = std::chrono::system_clock::now();

        DoStep();

        const auto time_passed = std::chrono::system_clock::now() - iteration_start;
        const auto time_to_sleep = min_cycle_duration_ - time_passed;
        std::this_thread::sleep_for(time_to_sleep);
    }
}

void Simulator::DoStep() {
    for (const auto& device : devices_) {
        device->DoStep();
    }
}

void Simulator::AddDevice(std::unique_ptr<Device> device_ptr) {
    devices_.emplace_back(std::move(device_ptr));
}

#include "simulator.h"

#include <fstream>
#include <thread>

#include <lib/device/device.h>

#define UNUSED(x) (void)x;

Simulator::Simulator(const std::chrono::seconds& min_cycle_duration, std::string commands_file)
    : commands_file_(commands_file)
    , min_cycle_duration_(min_cycle_duration)
    , devices_()
{
}

void Simulator::Run() {
    bool quit = false;
    while (!quit) {
        const auto iteration_start = std::chrono::system_clock::now();

        DoStep();
        ObtainMetrics();
        quit = ProcessCommands();

        const auto time_passed = std::chrono::system_clock::now() - iteration_start;
        const auto time_to_sleep = min_cycle_duration_ - time_passed;
        std::this_thread::sleep_for(time_to_sleep);
    }
}

void Simulator::DoStep() const {
    for (const auto& device : devices_) {
        device->DoStep();
    }
}

void Simulator::ObtainMetrics() const {
    for (const auto& device : devices_) {
        device->DumpState();
    }
}

bool Simulator::ProcessCommands() {
    bool quit = false;
    {
        std::ifstream commands(commands_file_);
        std::string command;
        for (std::getline(commands, command); commands; std::getline(commands, command)) {
            if (command == "stop") {
                quit = true;
            } else if (command == "Boil") {
                for (const auto& device : devices_) {
                    if (device->GetType() == Device::Type::kettle) {
                        device->Handle();
                    }
                }
            }
        }
    }
    std::ofstream{commands_file_} << "";
    return quit;
}

void Simulator::AddDevice(std::unique_ptr<Device> device_ptr) {
    devices_.emplace_back(std::move(device_ptr));
}

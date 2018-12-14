#include <iostream>

#include <lib/device/device.h>
#include <lib/device/kettle.h>
#include <lib/device/lamp.h>
#include <lib/simulator/simulator.h>

int main() {
    using namespace std::chrono_literals;

    Simulator simulator(1s, "commands");
    simulator.AddDevice(std::make_unique<Lamp>());
    simulator.AddDevice(std::make_unique<Kettle>(20, 30.5));
    simulator.Run();
}

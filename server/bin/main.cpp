#include <iostream>

#include <lib/device/device.h>
#include <lib/device/lamp.h>
#include <lib/simulator/simulator.h>

int main() {
    using namespace std::chrono_literals;

    Simulator simulator(2s);
    simulator.AddDevice(std::make_unique<Lamp>(/* is_initially_on = */ true));
    simulator.Run();
}

#include <iostream>

#include <src/device.h>
#include <src/lamp.h>
#include <src/simulator.h>

int main() {
    using namespace std::chrono_literals;

    Simulator simulator(2s);
    simulator.AddDevice(std::make_unique<Lamp>(/* is_initially_on = */ true));
    simulator.Run();
}

add_executable(
    smarthome-simulator

    main.cpp
)

target_link_libraries(
    smarthome-simulator

    Device
    Simulator
)

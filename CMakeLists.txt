cmake_minimum_required(VERSION 3.0)

# Set the project name
project (RL-Simulation)

# Create some variables for the files to compile
set(SRCS
    main.cpp
    simulator.cpp
    robot.cpp
    utils.cpp
    laser.cpp
    ray.cpp
    )

set(HEADERS
    simulator.h
    robot.h
    utils.h
    laser.h
    ray.h
    )

add_executable(simulation ${SRCS} ${HEADERS})

# Load the file ImagineConfig.cmake which contains commands, as
# ImagineUseModules
find_package(Imagine REQUIRED)

# Do two things : show where to search for the #include and tell to link
# the library libImageGraphics.a
ImagineUseModules(simulation Graphics)
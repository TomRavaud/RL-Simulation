cmake_minimum_required(VERSION 3.0.2)

# Set the project name
project(librobotsim)

# Load the file ImagineConfig.cmake which contains commands, as
# ImagineUseModules
find_package(Imagine REQUIRED)

# Create some variables with the files to compile
set(SRCS
    main.cpp
    simulator.cpp
    robot.cpp
    utils.cpp
    laser.cpp
    ray.cpp
    )

set(HEADERS
    simulator.hpp
    robot.hpp
    utils.hpp
    laser.hpp
    ray.hpp
    )

# Find python and Boost - both are required dependencies
# find_package(PythonLibs REQUIRED)
# find_package(Boost COMPONENTS python REQUIRED)

# Without this, any build libraries automatically have names "lib{x}.so"
# set(CMAKE_SHARED_MODULE_PREFIX "")

# Add a shared module - modules are intended to be imported at runtime.
# - This is where you add the source files
# add_library(robotsim MODULE robotsim.cpp ${SRCS} ${HEADERS})

# Set up the libraries and header search paths for this target
# target_link_libraries(robotsim ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
# target_include_directories(robotsim PRIVATE ${PYTHON_INCLUDE_DIRS})
# ImagineUseModules(robotsim Graphics)

# Generate an executable
# add_executable(simulation ${SRCS} ${HEADERS})

# Generate a library
add_library(robotsim ${SRCS} ${HEADERS})

# Indicate that the linker language is C++
set_target_properties(robotsim PROPERTIES LINKER_LANGUAGE CXX)

# Does two things : shows where to search for the #include and tells to link
# the library libImageGraphics.a
# ImagineUseModules(simulation Graphics)
ImagineUseModules(robotsim Graphics)

# Code files can include headers of the robotsim library using
# their name instead of the relative path to their location
target_include_directories(robotsim PUBLIC .)
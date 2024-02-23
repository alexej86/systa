cmake_minimum_required(VERSION 3.0)

project(systa)

# Set the CPP standard to C11
set(CMAKE_CPP_STANDARD 11)

# Define the executable
add_executable(systa main.cpp systa.cpp SystaCompact_II.cpp udp.cpp mqtt.cpp)
target_link_libraries(systa mosquitto)

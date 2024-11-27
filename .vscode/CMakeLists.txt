cmake_minimum_required(VERSION 3.10)  # Set minimum CMake version
project(NeuralNetwork)  # Set your project name

# Add source files
add_executable(main main.cpp)  # This specifies the executable to be built

# If you use libraries, you can link them like this:
# target_link_libraries(main Boost::Boost)

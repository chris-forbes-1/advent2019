#CMAKE 
cmake_minimum_required(VERSION 3.14.2)

#C++ opts
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(advent)

set(SOURCES Advent.cc 
src/Module.cc 
src/RocketFuelCalculator.cc 
src/OpcodeParser.cc
src/IntCodeMachine.cc
headers/Module.hpp 
headers/RocketFuelCalculator.hpp
headers/Opcodes.hpp
headers/OpcodeParser.hpp
headers/IntCodeMachine.hpp
headers/Opcodes.hpp
headers/OperatorFunctions.hpp)
add_executable(advent ${SOURCES})
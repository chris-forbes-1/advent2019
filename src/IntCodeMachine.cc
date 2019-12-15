#include "../headers/IntCodeMachine.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include "../headers/Opcodes.hpp"
#include "../headers/OperatorFunctions.hpp"
namespace advent
{
    int* program_memory;

    IntCodeMachine::IntCodeMachine(std::vector<int> program)
    {
        bootstrap_machine(program, program_memory);
    }
    int IntCodeMachine::run(int desired_memory_location)
    {
        auto pc = 0; // program counter

        return pc;
    }
    IntCodeMachine::~IntCodeMachine()
    {
        delete[] program_memory;
    }
    void IntCodeMachine::bootstrap_machine(std::vector<int> program, int *memory)
    {
        std::cout << "Determining how much memory the program needs" << std::endl;
        double max_value = *std::max_element(std::begin(program), std::end(program));
        std::cout << "Program needs " << max_value + 1 << std::endl;
        memory = {new int[ ((int)max_value) + 1]{}};
    }

    void IntCodeMachine::run_program(std::vector<int> program, int* memory)
    {

    }
}
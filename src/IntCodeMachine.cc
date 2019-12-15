#include "../headers/IntCodeMachine.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include "../headers/Opcodes.hpp"
#include "../headers/OperatorFunctions.hpp"
namespace advent
{
    int* program_memory;
    std::vector<int> user_program;

    IntCodeMachine::IntCodeMachine(std::vector<int> program)
    {
        bootstrap_machine(program, program_memory);
    }
    int IntCodeMachine::run(int desired_memory_location)
    {
        auto pc = 0; // program counter

        while(pc < user_program.size() -1)
        {
            std::function<int(int, int)> function = determine_opcode(pc);
            if(program_memory[pc] == FINISHED)
            {
                break;
            }
            if(function)
            {
                ++pc;
                auto value_one = program_memory[pc];
                ++pc;
                auto value_two = program_memory[pc];
                ++pc;
                auto address_location = program_memory[pc];
                program_memory[address_location] = function(value_one, value_two);
            }
            else
            {
                std::cout << "Termination hit" << std::endl;
            }
        }
        return pc; // get shot of that
    }
    std::function<int(int, int)> IntCodeMachine::determine_opcode(int program_counter)
    {
        int instruction = program_memory[program_counter];
        switch(instruction)
        {
            case ADD:
                return F_ADD;
            case MULTIPLY:
                return F_MULTIPLY;
        }
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
        std::swap(program, user_program);
    }

    void IntCodeMachine::run_program(std::vector<int> program, int* memory)
    {

    }
}
#ifndef INC_MACHINE_H
#define INC_MACHINE_H

#include <vector>
#include <functional>
namespace advent 
{
    class IntCodeMachine
    {
        public:
            IntCodeMachine(std::vector<int> program);
            int run(int desired_memory_location = -1);
            ~IntCodeMachine();
        private:
            void bootstrap_machine(std::vector<int> program, int *memory);
            void run_program(std::vector<int> program, int* memory);
            std::function<int(int, int)> determine_opcode(int program_counter);
    };
};
#endif
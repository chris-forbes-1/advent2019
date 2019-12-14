#ifndef OPCODE_PARSER_H
#define OPCODE_PARSER_H
#include <string>
#include <vector>
namespace advent
{
    class OpcodeParser
    {
        public:
            OpcodeParser();
            int execute_file(std::string input_file_path, int desired_location = -1);
            ~OpcodeParser();
        private:
            std::vector<int> parse_program_file(std::string input_file_path);
    };
};
#endif
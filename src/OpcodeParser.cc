#include "../headers/OpcodeParser.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

namespace advent
{
    OpcodeParser::OpcodeParser()
    {
        //noop
    }

    int OpcodeParser::execute_file(std::string input_file_path, int desired_location)
    {

        return 0;        
    }

    std::vector<int> OpcodeParser::parse_program_file(std::string input_file_path)
    {
        std::vector<int> parsed_intcodes;
        std::ifstream input(input_file_path);
        if(input.is_open())
        {
            std::string line;
            while(getline(input, line))
            {
                std::cout<< "Data line" << line << std::endl;
            }
        }
        return parsed_intcodes;
    }

    OpcodeParser::~OpcodeParser()
    {

    }
};
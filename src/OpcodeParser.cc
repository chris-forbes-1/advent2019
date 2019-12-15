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

    std::vector<int> OpcodeParser::parse_program_file(std::string input_file_path)
    {
        std::vector<int> parsed_program;
        std::ifstream input(input_file_path);
        if(input.is_open())
        {
            std::string line;
            while(getline(input, line))
            {
                std::cout<< "Splitting Data line: [" << line << "]" << std::endl;
                std::stringstream string_stream(line);
                while(string_stream.good())
                {
                    std::string temp_;
                    getline(string_stream,temp_, ',');
                    parsed_program.push_back(std::stoi(temp_));
                }
            }
        }
        input.close();
        return parsed_program;
    }

    OpcodeParser::~OpcodeParser()
    {
    }
};   
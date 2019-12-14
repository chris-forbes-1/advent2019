#include <iostream>
#include <string>
#include <getopt.h>
#include <stdlib.h>
#include "headers/RocketFuelCalculator.hpp"
#include "headers/OpcodeParser.hpp"

std::string file_path = "";
int test_num = -1;
bool opcode_mode = false;

void print_help()
{
    std::cout <<
            "advent of code 2019:\n" <<
            "Arguments:\n" <<
            "-f <fname>: File to Read\n";
    exit(EXIT_FAILURE);
}

void process_args(int argc, char** argv)
{
    const char* const short_opts = "f:t:o:";
    const option long_opts[] = {
        {"file", optional_argument, nullptr,'f'},
        {"test", optional_argument, nullptr, 't'},
        {"opcode", optional_argument, nullptr, 'o'}
        };
    while(true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);
        if(-1 == opt)
        {
            break;
        }
        switch(opt)
        {
            case 'f':
                file_path = optarg;
                break;
            case 't':
                test_num = std::atoi(optarg);
                break;
            case 'o':
                file_path = optarg;
                opcode_mode = true;
                break;
            case 'h':
                print_help();
                break;
            default:
                print_help();
                break;
        }
    }
}

int main(int argc, char** argv)
{
    
    process_args(argc, argv);

    advent::RocketFuelCalculator rocket_fuel_service;
    
    if(file_path.empty() && test_num> -1)
    {
        rocket_fuel_service.test_calculations(test_num);
    }
    else if(opcode_mode)
    {
        advent::OpcodeParser parser;
        parser.execute_file(file_path);
    }
    else
    {
        rocket_fuel_service.load_file(file_path);
        std::cout << "Done, calculated fuel requirements are: "<<  
        rocket_fuel_service.get_fuel_requirements() << std::endl;
    }
    
}
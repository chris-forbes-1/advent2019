#include "../headers/RocketFuelCalculator.hpp"
#include "../headers/Module.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
namespace advent
{

        RocketFuelCalculator::RocketFuelCalculator()
        {
            //noop
        }
        void RocketFuelCalculator::load_file(std::string input_file)
        {
            std::cout << "Loading input file " << input_file << std::endl;
            std::ifstream input(input_file);
            if(input.is_open())
            {
                std::string line;
                while(getline(input, line))
                {
                    Module new_module(std::stoi(line));
                    modules.push_back(new_module);
                }
            }
            input.close();
        }

        void RocketFuelCalculator::test_calculations(int test_number)
        {
            Module test_module (test_number);
            modules.push_back(test_module);
            auto fuel_required = get_fuel_requirements();
            std::cout << "Fuel required:" << fuel_required << std::endl;
        }

        int RocketFuelCalculator::get_fuel_requirements()
        {
            auto sum = 0;
            for(auto &current_module: modules)
            {
                auto module_fuel = fuel_calculation(current_module.get_mass());  
                sum += module_fuel;
                while(module_fuel > 0)
                {
                    module_fuel = fuel_calculation(module_fuel);
                    if(module_fuel > 0)
                        sum += module_fuel;
                }
            }
            return sum;
        }
        RocketFuelCalculator::~RocketFuelCalculator()
        {
            //noop
        }
  
};
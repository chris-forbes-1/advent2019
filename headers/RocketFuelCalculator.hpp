#ifndef ROCKET_FUEL_H
#define ROCKET_FUEL_H
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include "../headers/Module.hpp"

namespace advent
{
    class RocketFuelCalculator
    {
        private:
            std::vector<Module> modules;
            std::function<int(int)> fuel_calculation = [=](int a)->int{return (floor(a/3))-2;};
        public:
            RocketFuelCalculator();
            void load_file(std::string input_file);
            void test_calculations(int test_number);
            int get_fuel_requirements();
            ~RocketFuelCalculator();
    };
};
#endif
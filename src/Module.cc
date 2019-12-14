#include "../headers/Module.hpp"
namespace advent 
{
    Module::Module(int mass)
    {
        module_mass = mass;
    }
    int Module::get_mass()
    {
        return module_mass;
    }
    Module::~Module()
    {
            
    }
};
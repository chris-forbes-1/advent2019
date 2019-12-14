#ifndef MODULE_H
#define MODULE_H

namespace advent
{
    class Module 
    {
        private:
            int module_mass;

        public:
            Module(int mass);
            int get_mass();
            ~Module();
    };
};
#endif
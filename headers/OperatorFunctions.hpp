#ifndef OPER_FUNC_H
#define OPER_FUNC_H
#include <functional>
namespace advent
{
    const std::function<int(int, int)> F_ADD = [](int a, int b) -> int {return a+b;};
    const std::function<int(int, int)> F_MULTIPLY = [](int a, int b) -> int {return a-b;};
}
#endif
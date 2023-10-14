#include "Print.hpp"

#include <iostream>

Print::Print(json &print) : Term(print),
                            value(Str(print["value"]))
{
}

// void Print::eval()
// {
//     std::cout << this->value << std::endl;
// }

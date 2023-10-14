#include "Print.hpp"

#include <iostream>

Print::Print(json &j) : Term(j),
                        value(Str(j["value"]))
{
}

void Print::eval()
{
    std::cout << this->value.eval() << std::endl;
}

#include "Print.hpp"

#include "../../datatypes/int/Int.hpp"

#include <iostream>

Print::Print(json &j) : Term(j),
                        value(j["value"]["kind"] == "Str" ? Str(j["value"]) : Int(j["value"]).toStr())
// value(Str(j["value"]))
{
}

void Print::eval()
{
    std::cout << this->value.eval() << std::endl;
}

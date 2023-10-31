#include "Str.hpp"

Str::Str(json &str) : Term(str),
                      value(str["value"])
{
}

const std::string &Str::eval()
{
    return this->value;
}

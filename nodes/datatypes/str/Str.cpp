#include "Str.hpp"

Str::Str(json &str) : value(str["value"]),
                      location(Location(str["location"]))
{
}

const std::string &Str::eval()
{
    return this->value;
}

const std::string &Str::getKind()
{
    return this->kind;
}

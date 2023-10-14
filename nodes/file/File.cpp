#include <iostream>

#include "File.hpp"

#include "../../logger/Logger.hpp"

File::File(json &root) : expression(Term(root["expression"])),
                         name(root["name"]),
                         location(Location(root["location"]))
{
}

std::string File::getName()
{
    return this->name;
}

void File::eval()
{
    expression.eval();
}
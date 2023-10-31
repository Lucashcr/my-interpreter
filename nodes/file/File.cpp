#include <iostream>

#include "File.hpp"

#include "../statements/print/Print.hpp"

#include "../../logger/Logger.hpp"

File::File(json &root) : name(root["name"]),
                         location(Location(root["location"]))
{
    if (root["expression"]["kind"] == "Print")
    {
        this->expression = new Print(root["expression"]);
    }
    else
    {
        Logger logger = Logger("TESTE");
        logger.error("Termo desconhecido ou inválido: " + root["expression"].get<std::string>());
        exit(1);
    }
}

std::string File::getName()
{
    return this->name;
}

void File::eval()
{
    if (((Print *)this->expression)->getKind() == "Print")
    {
        ((Print *)this->expression)->eval();
        return;
    }
    else
    {
        Logger logger = Logger("TESTE");
        logger.error("Termo desconhecido ou inválido: " + ((Term *)this->expression)->getKind());
        exit(1);
    }
}
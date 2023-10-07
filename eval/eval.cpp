#include <iostream>
#include <string>

#include "eval.hpp"

int eval_int(json term)
{
    if (term["kind"] == "Int")
        return term["value"];
    else
        throw std::runtime_error("Falha ao interpretar o valor como um inteiro!");
}

std::string eval_string(json term)
{
    if (term["kind"] == "Str")
        return term["value"];
    else if (term["kind"] == "Int")
        return std::to_string(int(term["value"]));
    else
        throw std::runtime_error("Falha ao interpretar o valor como uma string!");
}

void eval(json expression)
{
    std::cout << std::endl;

    if (expression["kind"] == "Print")
        std::cout << eval_string(expression["value"]) << std::endl;

    std::cout << std::endl;
}
#include "Term.hpp"

#include <iostream>

#include "../datatypes/str/Str.hpp"
#include "../datatypes/int/Int.hpp"
#include "../statements/print/Print.hpp"

Term::Term(json &j) : kind(j["kind"]),
                      location(Location(j["location"]))
{
    if (this->kind == "Print")
    {
        if (j["value"]["kind"] == "Str")
            this->value = (void *)new Str(j["value"]);
        else if (j["value"]["kind"] == "Int")
            this->value = (void *)new Int(j["value"]);
        else
            std::cout << "Unknown term kind: " << this->kind << std::endl;
        // this->value = (void *)new Str(j["value"]);
    }
    else
    {
        std::cout << "Unknown term kind: " << this->kind << std::endl;
    }
}

std::string &Term::getKind()
{
    return this->kind;
}

void Term::eval()
{
    if (this->kind == "Print")
    {
        if (this->value == nullptr)
        {
            std::cout << "" << std::endl;
            return;
        }
        else if (((Int *)this->value)->getKind() == "Int")
        {
            Int *integer = (Int *)this->value;
            std::cout << integer->eval() << std::endl;
            return;
        }
        else if (((Str *)this->value)->getKind() == "Str")
        {
            Str *str = (Str *)this->value;
            std::cout << str->eval() << std::endl;
            return;
        }
    }
    else
    {
        std::cout << "Unknown term kind: " << this->kind << std::endl;
    }
}

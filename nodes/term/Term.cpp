#include "Term.hpp"

#include <iostream>

#include "../datatypes/str/Str.hpp"
#include "../statements/print/Print.hpp"

Term::Term(json &j) : kind(j["kind"]),
                      location(Location(j["location"]))
{
    if (this->kind == "Print")
    {
        const Str *str = new Str(j["value"]);
        this->value = (void *)str;
    }
    else
    {
        std::cout << "Unknown term kind: " << this->kind << std::endl;
    }
}

void Term::eval()
{
    if (this->kind == "Print")
    {
        Str *str = (Str *)this->value;
        std::cout << str->eval() << std::endl;
    }
    else
    {
        std::cout << "Unknown term kind: " << this->kind << std::endl;
    }
}

Term::~Term()
{
    if (this->kind == "Print")
    {
        // free(this->value);
    }
    else
    {
        std::cout << "Unknown term kind: " << this->kind << std::endl;
    }
}
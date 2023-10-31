#include "Term.hpp"

#include <iostream>

#include "../datatypes/str/Str.hpp"
#include "../datatypes/int/Int.hpp"
#include "../statements/print/Print.hpp"

Term::Term(json &j) : kind(j["kind"]),
                      location(Location(j["location"]))
{
}

const std::string &Term::getKind() const
{
    return this->kind;
}

const Location &Term::getLocation() const
{
    return this->location;
}

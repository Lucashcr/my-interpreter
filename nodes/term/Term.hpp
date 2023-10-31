#ifndef __TERM_HPP__
#define __TERM_HPP__

#include "../location/Location.hpp"

class Term
{
private:
    const std::string kind;
    Location location;

public:
    Term(json &j);
    const std::string &getKind() const;
    const Location &getLocation() const;
};

#endif // __TERM_HPP__

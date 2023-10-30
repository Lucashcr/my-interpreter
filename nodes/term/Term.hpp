#ifndef __TERM_HPP__
#define __TERM_HPP__

#include "../location/Location.hpp"

class Term
{
private:
    std::string kind;
    Location location;
    void *value = nullptr;

public:
    Term(json &j);
    void eval();
    std::string &getKind();
};

#endif // __TERM_HPP__

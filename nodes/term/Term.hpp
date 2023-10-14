#ifndef __TERM_HPP__
#define __TERM_HPP__

#include "../location/Location.hpp"

class Term
{
protected:
    std::string kind;

private:
    Location location;
    void *value = nullptr;

public:
    Term(json &j);
    void eval();
};

#endif // __TERM_HPP__

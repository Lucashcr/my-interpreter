#ifndef __FILE_HPP__
#define __FILE_HPP__

#include <string>

#include "../term/Term.hpp"

class File final
{
private:
    std::string name;
    void *expression;
    Location location;

public:
    File(json &expression);
    std::string getName();
    void eval();
};

#endif // __FILE_HPP__

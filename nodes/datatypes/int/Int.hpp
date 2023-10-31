#ifndef __INT_HPP__
#define __INT_HPP__

#include <string>

#include "../../term/Term.hpp"
#include "../str/Str.hpp"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Int final : Term
{
private:
    int value;

public:
    Int(json &int_);
    const int &eval();
    const Str toStr();
};

#endif // __INT_HPP__

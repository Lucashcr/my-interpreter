#ifndef __INT_HPP__
#define __INT_HPP__

#include <string>

#include "../str/Str.hpp"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "../../location/Location.hpp"

class Int
{
private:
    const std::string kind = "Int";
    Location location;
    int value;

public:
    Int() = default;
    Int(json &int_);
    const std::string &getKind();
    const int &eval();
    const Str toStr();
};

#endif // __INT_HPP__

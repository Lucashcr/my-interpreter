#ifndef __STR_HPP__
#define __STR_HPP__

#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "../../location/Location.hpp"

class Str
{
private:
    const std::string kind = "Str";
    Location location;
    std::string value;

public:
    Str() = default;
    Str(json &str);
    const std::string &getKind();
    const std::string &eval();
};

#endif // __STR_HPP__

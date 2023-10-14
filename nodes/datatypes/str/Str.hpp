#ifndef __STR_HPP__
#define __STR_HPP__

#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "../../location/Location.hpp"

class Str
{
protected:
    const std::string kind = "Str";

private:
    Location location;
    std::string value;

public:
    Str() = default;
    Str(json &str);
    const std::string &eval();
};

#endif // __STR_HPP__

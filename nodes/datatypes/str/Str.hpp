#ifndef __STR_HPP__
#define __STR_HPP__

#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "../../term/Term.hpp"
#include "../../location/Location.hpp"

class Str final : Term
{
private:
    std::string value;

public:
    Str(json &str);
    const std::string &eval();
};

#endif // __STR_HPP__

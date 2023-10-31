#ifndef __PRINT_HPP__
#define __PRINT_HPP__

#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "../../term/Term.hpp"
#include "../../datatypes/str/Str.hpp"

class Print final : public Term
{
private:
    const std::string kind = "Print";
    Str value;

public:
    Print(json &j);
    void eval();
};

#endif // __PRINT_HPP__

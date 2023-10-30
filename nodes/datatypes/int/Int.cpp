#include "Int.hpp"

Int::Int(json &int_) : value(int_["value"]),
                       location(Location(int_["location"]))
{
}

const int &Int::eval()
{
    return this->value;
}

const std::string &Int::getKind()
{
    return this->kind;
}

const Str Int::toStr()
{
    json j;
    j["kind"] = "Str";
    j["value"] = std::to_string(this->value);
    json loc;
    loc["start"] = this->location.GetStart();
    loc["end"] = this->location.GetEnd();
    loc["filename"] = this->location.GetFilename();
    j["location"] = loc;
    return Str(j);
}
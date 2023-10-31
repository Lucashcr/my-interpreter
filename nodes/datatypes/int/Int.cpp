#include "Int.hpp"

Int::Int(json &int_) : Term(int_),
                       value(int_["value"])
{
}

const int &Int::eval()
{
    return this->value;
}

const Str Int::toStr()
{
    json j;
    j["kind"] = "Str";
    j["value"] = std::to_string(this->value);

    Location location = this->getLocation();

    json loc;
    loc["start"] = location.GetStart();
    loc["end"] = location.GetEnd();
    loc["filename"] = location.GetFilename();

    j["location"] = loc;
    return Str(j);
}
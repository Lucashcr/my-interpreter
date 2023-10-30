#ifndef __LOCATION_HPP__
#define __LOCATION_HPP__

#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Location
{
private:
    int start;
    int end;
    std::string filename;

public:
    Location(json &j);
    const int GetStart();
    const int GetEnd();
    const std::string &GetFilename();
};

#endif // __LOCATION_HPP__

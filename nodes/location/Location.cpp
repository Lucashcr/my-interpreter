#include "Location.hpp"

Location::Location(json &j)
{
    j.at("start").get_to(this->start);
    j.at("end").get_to(this->end);
    j.at("filename").get_to(this->filename);
}
#include <nlohmann/json.hpp>
using json = nlohmann::json;

std::string eval_string(json term);
int eval_int(json term);
void eval(json expression);
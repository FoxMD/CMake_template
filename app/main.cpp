#include <iostream>

#include <nlohmann/json.hpp>
#include "config.hpp"

int main()
{
    std::cout << project_name <<std::endl;
    std::cout << "JSON Lib version" << NLOHMANN_JSON_VERSION_MAJOR << "." << NLOHMANN_JSON_VERSION_MINOR << "." << NLOHMANN_JSON_VERSION_PATCH << "." << std::endl;
    return 0;
}
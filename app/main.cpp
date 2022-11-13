#include <iostream>

#include <nlohmann/json.hpp>
#include "config.hpp"
#include <spdlog/spdlog.h>
#include <fmt/format.h>

int main()
{
    std::cout << project_name <<std::endl;
    std::cout << "JSON Lib version" << NLOHMANN_JSON_VERSION_MAJOR << "." << NLOHMANN_JSON_VERSION_MINOR << "." << NLOHMANN_JSON_VERSION_PATCH << "." << std::endl;
    
    spdlog::info(fmt::format("Welcome to {} v{}\n", project_name, project_version));
    
    return 0;
}
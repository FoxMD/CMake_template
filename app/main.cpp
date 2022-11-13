#include <iostream>

#include <nlohmann/json.hpp>
#include "config.hpp"
#include <spdlog/spdlog.h>
#include <fmt/format.h>
#include <cxxopts.hpp>

int main(int argc, char **argv)
{
    std::cout << project_name <<std::endl;
    std::cout << "JSON Lib version" << NLOHMANN_JSON_VERSION_MAJOR << "." << NLOHMANN_JSON_VERSION_MINOR << "." << NLOHMANN_JSON_VERSION_PATCH << "." << std::endl;
    
    spdlog::info(fmt::format("Welcome to {} v{}\n", project_name, project_version));
    
    cxxopts::Options options(project_name.data());
    options.add_options("arguments")("h,help", "Print usage");

    auto result = options.parse(argc, argv);
    if(result.count("help"))
    {
        std::cout << options.help() << std::endl;
    } 

    return 0;
}
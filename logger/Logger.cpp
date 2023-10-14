#include <string>

#include "Logger.hpp"

const std::string Logger::BOLD = "\033[1m";
const std::string Logger::OKCYAN = "\033[96m";
const std::string Logger::OKGREEN = "\033[92m";
const std::string Logger::WARNING = "\033[93m";
const std::string Logger::FAIL = "\033[91m";
const std::string Logger::ENDC = "\033[0m";

Logger::Logger(std::string app_name, Level level) : APP_NAME(app_name), LEVEL(level)
{
}

void Logger::log(std::string message, std::string color, bool bold)
{
    if (bold)
    {
        color += Logger::BOLD;
    }
    std::cout << color << "[" << APP_NAME << "]: " << message << Logger::ENDC << std::endl;
}

void Logger::error(std::string message)
{
    if (LEVEL >= Logger::ERROR)
        Logger::log(message, Logger::FAIL, true);
}

void Logger::warn(std::string message)
{
    if (LEVEL >= Logger::WARN)
        Logger::log(message, Logger::WARNING, true);
}

void Logger::info(std::string message)
{
    if (LEVEL >= Logger::INFO)
        Logger::log(message, Logger::OKCYAN, true);
}

void Logger::debug(std::string message)
{
    if (LEVEL >= Logger::DEBUG)
        Logger::log(message);
}

void Logger::success(std::string message)
{
    Logger::log(message, Logger::OKGREEN, true);
}

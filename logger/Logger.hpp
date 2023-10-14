#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <iostream>
#include <string>

class Logger
{
public:
    enum Level
    {
        ERROR,
        WARN,
        INFO,
        DEBUG,
        SUCCESS,
    };

    Logger(std::string app_name, Level level = Level::INFO);

    void error(std::string message);
    void warn(std::string message);
    void info(std::string message);
    void debug(std::string message);
    void success(std::string message);

private:
    static const std::string OKCYAN;
    static const std::string OKGREEN;
    static const std::string WARNING;
    static const std::string FAIL;
    static const std::string ENDC;
    static const std::string BOLD;

    void log(std::string message, std::string color = "", bool bold = false);

    const std::string APP_NAME;
    const Level LEVEL;
};

#endif // __LOGGER_HPP__

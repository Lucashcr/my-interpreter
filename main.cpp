#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "logger/logger.hpp"

int main(int argc, char *argv[])
{
    Logger logger = Logger("TESTE", Logger::Level::DEBUG);
    logger.info("Iniciando programa...");

    std::stringstream message;
    message << "Tentando abrir " << argv[1] << "!";
    logger.info(message.str());

    if (!argv[1])
    {
        logger.error("Arquivo não especificado!");
        return 1;
    }

    if (!std::filesystem::exists(argv[1]))
    {
        std::stringstream message;
        message << "Arquivo " << argv[1] << " não existe!";
        logger.error(message.str());
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::stringstream message;
        message << "Não foi possível abrir o arquivo " << argv[1] << "!";
        logger.error(message.str());
        return 1;
    }

    json program = json::parse(file);
    // logger.debug("Executando programa " + program["expresion"].dump(4) + " ...");

    logger.success("Programa executado com sucesso!");

    file.close();

    return 0;
}

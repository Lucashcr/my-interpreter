#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "logger/Logger.hpp"
#include "nodes/Nodes.hpp"

int main(int argc, char *argv[])
{
    Logger logger = Logger("TESTE", Logger::Level::DEBUG);
    logger.info("Iniciando programa...");

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

    std::stringstream message;
    message << "Abrindo \"" << argv[1] << "\"!";
    logger.info(message.str());

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::stringstream message;
        message << "Não foi possível abrir o arquivo " << argv[1] << "!";
        logger.error(message.str());
        return 1;
    }

    json j = json::parse(file);

    try
    {
        File program = File(j);
        program.eval();
    }
    catch (std::exception &e)
    {
        std::stringstream message;
        message << "Erro ao executar o programa \"" << j["name"] << "\"!";
        logger.error(message.str());
        logger.error(e.what());
        return 1;
    }

    logger.success("Programa executado com sucesso!");

    file.close();

    return 0;
}

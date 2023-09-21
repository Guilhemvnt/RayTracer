/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** testParsing
*/

#include "main.hpp"

int TestParsing(int ac, char **av)
{
    std::shared_ptr<Parsing> parser = std::make_shared<Parsing>(ac, av);

    if (parser->fillData() == 84)
        return 84;

    printData(parser);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** main
*/

#include "main.hpp"

int main (int ac, char **av)
{
    if (testCamera(ac, av) == 84)
        return 84;
    // if (TestFile(av) == 84)
    //     return 84;
    std::cout << "CPU go brrrr" << std::endl;
    return 0;
}
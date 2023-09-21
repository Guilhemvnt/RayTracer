/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Screen
*/

#include "../include/Screen.hpp"

Screen::Screen(Res res, ScreenSize size)
{
    _res.x = res.x;
    _res.y = res.y;
    _size.x = size.x;
    _size.y = size.y;
}

Screen::~Screen()
{
}

Res Screen::getRes() const
{
    return (_res);
}

ScreenSize Screen::getSize() const
{
    return (_size);
}

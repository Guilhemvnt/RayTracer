/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Screen
*/

#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include "Point3D.hpp"

struct Res
{
    int x;
    int y;
};

struct ScreenSize
{
    int x;
    int y;
};

class Screen {
    public:
        Screen(Res, ScreenSize);
        ~Screen();
        Res getRes() const;
        ScreenSize getSize() const;
    protected:
        Res _res;
        ScreenSize _size;
    private:
};

#endif /* !SCREEN_HPP_ */

/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** utility
*/

#ifndef UTILITY_HPP_
    #define UTILITY_HPP_

    #include <cmath>
    #include <limits>
    #include <memory>

    const double infinity = std::numeric_limits<double>::infinity();

    const double pi = 3.1415926535897932385;

    inline double degrees_to_radians(double deg) {
        return deg * pi / 180.0;
    }

    inline double clamp(double x, double min, double max) {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }
#endif /* !UTILITY_HPP_ */
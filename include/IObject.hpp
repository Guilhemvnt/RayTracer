/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-Vector3Dtracer-guilhem.vinet
** File description:
** IObject
*/

#ifndef IOBJECT_HPP_
    #define IOBJECT_HPP_
    #include <vector>
    #include <iostream>
    #include <cmath>
    #include "Material.hpp"

    class IObject {
        public:
            virtual bool collide(const Ray&r, double t_min, double t_max, hit_record& rec) const = 0;
    };

#endif /* !IOBJECT_HPP_ */

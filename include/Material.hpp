/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Material
*/

#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_
    #include "RandomUnits.hpp"
    #include "hitReccord.hpp"
    #include "Ray.hpp"

    class Material {
        public:
            virtual bool scatter(const Ray&, const hit_record&, Vector3D&, Ray&) const = 0;
            virtual Vector3D emitted(double u, double v, const Point3D& p) const {
                return Vector3D(0,0,0);
            }
    };

#endif /* !MATERIAL_HPP_ */

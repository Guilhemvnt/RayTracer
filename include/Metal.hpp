/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Metal
*/

#ifndef METAL_HPP_
#define METAL_HPP_

    #include "Material.hpp"

    class Metal : virtual public Material {
        public:
            Metal(const Vector3D& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

            virtual bool scatter(const Ray& r_in, const hit_record& rec, Vector3D& attenuation, Ray& scattered) const;
        public:
            Vector3D albedo;
            double fuzz;
    };

#endif /* !METAL_HPP_ */

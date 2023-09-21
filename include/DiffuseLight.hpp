/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** DiffuseLight
*/

#ifndef DIFFUSELIGHT_HPP_
#define DIFFUSELIGHT_HPP_

#include "Material.hpp"
#include <iostream>

class DiffuseLight : public Material {
    public:
        DiffuseLight(shared_ptr<texture> a) : emit(a) {}
        DiffuseLight(Vector3D a) : emit(std::make_shared<solid_color>(c)) {}

        bool scatter(
            const Ray& r_in, const hit_record& rec, Vector3D& attenuation, Ray& scattered
        ) const {
            return false;
        }

        virtual Vector3D emitted(double u, double v, const Point3D& p) const override {
            return emit->value(u, v, p);
        }

    public:
        shared_ptr<texture> emit;
};

#endif /* !DIFFUSELIGHT_HPP_ */

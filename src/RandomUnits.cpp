/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Random_Units
*/

#include "RandomUnits.hpp"

Vector3D random_in_unit_sphere() {
    while (true) {
        auto p = Vector3D(random_double(-1,1), random_double(-1,1), random_double(-1,1));
        if (p.length_sqrt() >= 1) continue;
        return p;
    }
}

Vector3D random_in_hemisphere(const Vector3D& normal) {
    Vector3D in_unit_sphere = random_in_unit_sphere();
    if (dot(in_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return in_unit_sphere;
    else
        return -in_unit_sphere;
}

Vector3D unit_vector(Vector3D v) {
    return v / v.length();
}

Vector3D random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}


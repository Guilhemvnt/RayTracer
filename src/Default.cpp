/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Default
*/

#include "Default.hpp"

bool Default::scatter(const Ray &, const hit_record &rec, Vector3D &attenuation, Ray &scattered) const
{
    auto scatter_direction = rec.normal + random_unit_vector();
    if (scatter_direction.near_zero())
        scatter_direction = rec.normal;
    scattered = Ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}


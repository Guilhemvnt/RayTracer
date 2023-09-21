/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Metal
*/

#include "Metal.hpp"

bool Metal::scatter(const Ray& r_in, const hit_record& rec, Vector3D& attenuation, Ray& scattered) const
{
    Vector3D reflected = reflect(unit_vector(r_in.getDirection()), rec.normal);
    scattered = Ray(rec.p, reflected + fuzz*random_in_unit_sphere());
    attenuation = albedo;
    return (dot(scattered.getDirection(), rec.normal) > 0);
}

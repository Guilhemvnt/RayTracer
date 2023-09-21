/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** RandomUnits
*/

#ifndef RANDOMUNITS_HPP_
#define RANDOMUNITS_HPP_

#include "Vector3D.hpp"

Vector3D random_in_unit_sphere();
Vector3D random_in_hemisphere(const Vector3D& normal);
Vector3D random_unit_vector();
Vector3D unit_vector(Vector3D v);

#endif /* !RANDOMUNITS_HPP_ */

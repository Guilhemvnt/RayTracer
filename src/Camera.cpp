/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Camera
*/

#include "../include/Camera.hpp"

Camera::Camera(std::map<std::string, std::string> camData, double time0, double time1)
{
    auto aspect_ratio = (double)std::stod(camData["width"]) / (double)std::stod(camData["height"]);
    FOV = std::stoi(camData["fieldOfView"]);
    auto fov_radians = degrees_to_radians(FOV);
    auto h = tan(fov_radians/2);
    auto viewport_height = 2.0 * h;
    auto viewport_width = aspect_ratio * viewport_height;
    _time0 =  time0;
    _time1 = time1;


    _origin = Point3D(std::stod(camData["posX"]), std::stod(camData["posY"]), std::stod(camData["posZ"]));
    Point3D lookat = Point3D(std::stod(camData["dirX"]), std::stod(camData["dirY"]), std::stod(camData["dirZ"]));
    Vector3D vup = Vector3D(std::stod(camData["vupX"]), std::stod(camData["vupY"]), std::stod(camData["vupZ"]));

    auto w = unit_vector(_origin - lookat);
    auto u = unit_vector(cross(vup, w));
    auto v = cross(w, u);

    horizontal = viewport_width * u;
    vertical = viewport_height * v;
    left_corner = _origin - horizontal/2 - vertical/2 - w;
}

Camera::~Camera()
{
}

Point3D Camera::getOrigin() const
{
    return (_origin);
}

Ray Camera::getRay(double u, double v) const
{
    return Ray(_origin, left_corner + u*horizontal + v*vertical - _origin);
}

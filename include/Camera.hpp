/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_
    #include <vector>
    #include "Screen.hpp"
    #include <cmath>
    #include <iostream>
    #include <memory>
    #include "Parsing.hpp"
    #include "Ray.hpp"
    #include "utility.hpp"
    #include "RandomUnits.hpp"

    class Camera {
        public:
            Camera(std::map<std::string, std::string> camData, double _time0 = 0.0, double _time1 = 0.0);
            ~Camera();
            Vector3D *getViewRect() const;
            Point3D getOrigin() const;
            Ray getRay(double, double) const;

        protected:
            Point3D _origin;
            double FOV = 60.0;
            Vector3D horizontal;
            Vector3D vertical;
            Point3D left_corner;
            double _time0 = 0.0;
            double _time1 = 0.0;
        private:
    };

#endif /* !CAMERA_HPP_ */

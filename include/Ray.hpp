/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-Vector3Dtracer-guilhem.vinet
** File description:
** Ray
*/

#ifndef Vector3D_HPP_
    #define Vector3D_HPP_
    #include "Point3D.hpp"
    #include "Vector3D.hpp"

    class Ray {
        protected:
            Point3D origin;
            Vector3D direction;
            double _t;

        public:
            Ray() {};
            Ray(const Point3D &o, const Vector3D &d, double t = 0.0) { origin = o; direction = d; _t = t; }
            ~Ray() {};

            Point3D pointAt(double t) const { return origin + (direction * t); }
            Point3D getOrigin() const { return origin; }
            Vector3D getDirection() const { return direction; }
            double time() const    { return t; }

    };

#endif /* !Vector3D_HPP_ */

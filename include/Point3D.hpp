/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-Vector3Dtracer-guilhem.vinet
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
    #define POINT3D_HPP_

    #include <iostream>
    #include <cmath>

    class Point3D {
        public:
            Point3D() = default;
            Point3D(double _x, double _y, double _z) { x = _x; y = _y; z = _z;}
            Point3D(const Point3D& point) = default;
            ~Point3D() = default;
            double x;
            double y;
            double z;

            Point3D operator=(const Point3D &point) {
                x = point.x;
                y = point.y;
                z = point.z;
                return Point3D(x, y, z);
            }
            Point3D operator-(const Point3D &vec) {
                x -= vec.x;
                y -= vec.y;
                z -= vec.z;
                return Point3D(x, y, z);
            }
            Point3D operator*(const Point3D &point) {
                x *= point.x;
                y *= point.y;
                z *= point.z;
                return Point3D(x, y, z);
            }

    };

#endif /* !POINT3D_HPP_ */

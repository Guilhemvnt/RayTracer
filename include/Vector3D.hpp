/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include "Point3D.hpp"

inline double random_double() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}

class Vector3D {
    public:
        Vector3D() = default;
        Vector3D(double _x, double _y, double _z) { x = _x; y = _y; z = _z;};
        Vector3D(const Vector3D& vector) = default;
        Vector3D(const Point3D& p) { x = p.x; y = p.y; z = p.z;};
        ~Vector3D() {};
        double x;
        double y;
        double z;

        void normalize() {
            double mag = sqrt(x * x + y * y + z * z);
            if (mag > 0) {
                x /= mag;
                y /= mag;
                z /= mag;
            }
        }
        bool near_zero() const {
            const auto s = 1e-8;
            return (fabs(x) < s) && (fabs(y) < s) && (fabs(z) < s);
        }
        Vector3D operator-() const { return Vector3D(-x, -y, -z); }
        Vector3D &operator=(const Vector3D &vector) {
            x = vector.x;
            y = vector.y;
            z = vector.z;
            return *this;
        }

        Vector3D &operator+=(const Vector3D &vector) {
            x += vector.x;
            y += vector.y;
            z += vector.z;
            return *this;
        }
        Vector3D &operator*=(const double _x) {
            x *= _x;
            y *= _x;
            z *= _x;
            return *this;
        }
        Vector3D &operator-= (const Vector3D &vector) {
            x -= vector.x;
            y -= vector.y;
            z -= vector.z;
            return *this;
        }
        Vector3D operator/(const double x) {
            return Vector3D(this->x / x, this->y / x, this->z / x);
        }

        double length() const {
            return sqrt(length_sqrt());
        }

        double length_sqrt() const {
            return x * x + y * y + z * z;
        }

        inline static Vector3D random() {
            return Vector3D(random_double(), random_double(), random_double());
        }

        inline static Vector3D random(double min, double max) {
            return Vector3D(random_double(min,max), random_double(min,max), random_double(min,max));
        }
};

inline double dot(const Vector3D &vector1, const Vector3D &vector2) {
    return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}

inline std::ostream &operator<<(std::ostream &out, const Vector3D *vector) {
    out << "Vector3D(" << vector->x << ", " << vector->y << ", " << vector->z << ")";
    return out;
}

inline bool operator!=(const Vector3D &vector1, const Vector3D &vector2) {
    if (vector1.x != vector2.x || vector1.y != vector2.y || vector1.z != vector2.z)
        return true;
    return false;
}

inline Vector3D operator+(const Vector3D &vector1, const Vector3D &vector2) {
    return Vector3D(vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z);
}

inline Vector3D operator-(const Vector3D &vector1, const Vector3D &vector2) {
    return Vector3D(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z);
}

inline Vector3D operator*(const Vector3D &vector1, const Vector3D &vector2) {
    return Vector3D(vector1.x * vector2.x, vector1.y * vector2.y, vector1.z * vector2.z);
}

inline Vector3D operator*(const Vector3D &vector, const double x) {
    return Vector3D(vector.x * x, vector.y * x, vector.z * x);
}

inline Vector3D operator*(const double x, const Vector3D &vector) {
    return vector * x;
}

inline Vector3D operator/(const Vector3D &vector, const double x) {
    return vector * (1 / x);
}

inline Vector3D cross(const Vector3D &vector1, const Vector3D &vector2) {
    return Vector3D(vector1.y * vector2.z - vector1.z * vector2.y,
        vector1.z * vector2.x - vector1.x * vector2.z,
        vector1.x * vector2.y - vector1.y * vector2.x);
}

inline Point3D operator+(Point3D p, Vector3D v) {
    return Point3D(p.x + v.x, p.y + v.y, p.z + v.z);
}

inline Point3D operator-(Point3D p, Vector3D v) {
    return Point3D(p.x - v.x, p.y - v.y, p.z - v.z);
}

inline Vector3D operator+(const Point3D &vector1, const Point3D &vector2) {
    return Vector3D(vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z);
}

inline Vector3D operator-(const Point3D &vector1, const Point3D &vector2) {
    return Vector3D(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z);
}

inline Vector3D reflect(const Vector3D& v, const Vector3D u) {
    return (v - 2 * dot(v, u) * u);
}

#endif /* !VECTOR3D_HPP_ */

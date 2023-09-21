/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** hitReccord
*/

#ifndef HITRECCORD_HPP_
    #define HITRECCORD_HPP_


    #include "Ray.hpp"
    #include <memory>
    #include "Material.hpp"

    class Material;
    struct hit_record {
        Point3D p;
        Vector3D normal;
        std::shared_ptr<Material> mat_ptr;
        double u;
        double v;
        double t;
        bool front_face;

        inline void set_face_normal(const Ray& r, const Vector3D& outward_normal) {
            front_face = dot(r.getDirection(), outward_normal) < 0;
            normal = front_face ? outward_normal :-outward_normal;
        }
    };

#endif /* !HITRECCORD_HPP_ */

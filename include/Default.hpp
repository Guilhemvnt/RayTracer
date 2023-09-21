/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Default
*/

#ifndef Default_hhp
#define Default_hhp
    #include "Material.hpp"

    class Default : virtual public Material {
        public:
            Default(const Vector3D& a) : albedo(a) {}

            virtual bool scatter(const Ray& r_in, const hit_record& rec, Vector3D& attenuation, Ray& scattered) const;
        public:
            Vector3D albedo;
    };

#endif /* !Default_hpp */

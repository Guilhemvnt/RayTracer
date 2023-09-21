/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-Vector3Dtracer-guilhem.vinet
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "IObject.hpp"

    class Sphere : virtual public IObject {
        public:
            Sphere(Point3D cen, double r, std::shared_ptr<Material> m)
            : center(cen), radius(r), mat_ptr(m) {};
            ~Sphere() {};

            bool collide(const Ray&r, double t_min, double t_max, hit_record& rec) const;
            // void translate(float, float) {};
            // void rotate(float) {};
            // Point3D *pointAt(double, double) { return this->_center; };

        public:
            Point3D center;
            double radius;
            std::shared_ptr<Material> mat_ptr;
    };

    // class SphereBuilder : public IObjectBuilder {
    //     public:
    //         SphereBuilder();
    //         ~SphereBuilder();

    //         void buildObjet();

    //         void setParam(std::string nameValue, std::string value);

    //         std::shared_ptr<IObject> getObjet() const;

    //     private:
    //     protected:
    //         double _radius;
    //         double _x;
    //         double _y;
    //         double _z;
    //         std::shared_ptr<Sphere> objet;
    // };

    // class SphereFactory : public IObjectFactory {
    //     public:
    //         SphereFactory();
    //         ~SphereFactory();

    //         std::shared_ptr<IObjectBuilder> createObjectBuilder();

    //     private:
    //     protected:
    // };

#endif /* !SPHERE_HPP_ */

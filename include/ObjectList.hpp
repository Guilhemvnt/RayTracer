/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** listOject
*/

#ifndef LISTOJECT_HPP_
    #define LISTOJECT_HPP_

    #include "IObject.hpp"
    #include "Parsing.hpp"
    #include "Sphere.hpp"
    #include "Default.hpp"
    #include "Metal.hpp"

    class ObjectList : virtual public IObject {
        public:
            ObjectList() {};
            ObjectList(std::shared_ptr<IObject> object) {add(object);}

            void clear() {objects.clear();}
            void add(std::shared_ptr<IObject> object) {objects.push_back(object);}

            bool collide(const Ray&r, double t_min, double t_max, hit_record& rec) const;

        public:
            //Vector3D color;
            std::vector<std::shared_ptr<IObject>> objects;
    };

    ObjectList createObjectList(std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> primData);
#endif /* !LISTOJECT_HPP_ */

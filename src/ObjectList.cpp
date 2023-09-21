/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** ObjectList
*/

#include "ObjectList.hpp"

bool ObjectList::collide(const Ray&r, double t_min, double t_max, hit_record& rec) const
{
    hit_record temp_rec;
    auto hit_anything = false;
    auto closets_so_far = t_max;

    for (const auto& object : objects) {
        if (object->collide(r, t_min, closets_so_far, temp_rec)) {
            hit_anything = true;
            closets_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

ObjectList createObjectList(std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> primData)
{
    ObjectList world;

    for (auto type : primData) {
        for (auto num : type.second) {
            if (num.second["material"] == "D") {
                world.add(std::make_shared<Sphere> (
                        Point3D (std::stod(num.second["posX"]), std::stod(num.second["posY"]), std::stod(num.second["posZ"])),
                        type.first == "spheres" ? std::stod(num.second["radius"]) : 100,
                        std::make_shared<Default> (
                            Vector3D (std::stod(num.second["colorR"]), std::stod(num.second["colorG"]), std::stod(num.second["colorB"]))
                        )
                    )
                );
            } else {
                world.add(std::make_shared<Sphere> (
                        Point3D (std::stod(num.second["posX"]), std::stod(num.second["posY"]), std::stod(num.second["posZ"])),
                        type.first == "spheres" ? std::stod(num.second["radius"]) : 100,
                        std::make_shared<Metal> (
                            Vector3D (std::stod(num.second["colorR"]), std::stod(num.second["colorG"]), std::stod(num.second["colorB"])),
                            std::stod(num.second["fuzz"])
                        )
                    )
                );
            }
        }
    }
    return world;
}

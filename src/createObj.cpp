/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** createObj
*/

#include "Sphere.hpp"
#include "Parsing.hpp"
#include "File.hpp"

// std::vector<std::shared_ptr<IObject>> createObj(std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> prim)
// {
//     std::vector<std::shared_ptr<IObject>> objectList;

//     for (const auto& [objetType, objNumMap] : prim) {
//         for (const auto& [objNum, obj] : objNumMap) {

//             std::shared_ptr<IObjectFactory> factory;
//             if (objetType == "spheres") {
//                 factory = std::make_shared<SphereFactory>();
//             } else if (objetType == "planes") {
//                 factory = std::make_shared<Rectangle3DFactory>();
//             } else {
//                 std::cerr << "Type : " << objetType << " Unknown, can't create objects" <<std::endl;
//                 return std::vector<std::shared_ptr<IObject>>();
//             }

//             std::shared_ptr<IObjectBuilder> builder;
//             builder = factory->createObjectBuilder();
//             for (const auto& [objDataName, objDataValue] : obj) {
//                 builder->setParam(objDataName, objDataValue);
//             }
//             builder->buildObjet();

//             std::shared_ptr<IObject> objet;
//             objet = builder->getObjet();
//             objectList.push_back(objet);
//         }
//     }
//     return objectList;
// }

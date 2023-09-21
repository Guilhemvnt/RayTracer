/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Parsing
*/

#include "Parsing.hpp"

// ------------------------------ Outside of class Parsing ------------------------------

void printData(std::shared_ptr<Parsing> parser)
{
    std::cout << "Camera Data:" << std::endl;
    for (const auto& camera_data : parser->getCameraData()) {
        std::cout << "\t" << camera_data.first << ":" << camera_data.second << std::endl;
    }

    std::cout << "Primitives Data:" << std::endl;
    for (auto const& primitive_type : parser->getPrimitivesData()) {
        std::cout << "\tPrimitive Type: " << primitive_type.first << std::endl;
        for (auto const& primitive_num : primitive_type.second) {
            std::cout << "\t\tPrimitive Num: " << primitive_num.first << std::endl;
            for (auto const& primitive_data : primitive_num.second) {
                std::cout << "\t\t\t" << primitive_data.first << " : " << primitive_data.second << std::endl;
            }
        }
    }
}

// ------------------------------ Inside of class Parsing ------------------------------

// ------------------------------ Public Part ------------------------------

Parsing::Parsing(int ac, char **av)
{
    _argError = argsManagement(ac, av);
    libconfig::Config cfg;
    if ( _argError != 84)
        _fileName = av[1];
}

Parsing::~Parsing()
{
}

int Parsing::fillData()
{
    if ( _argError == 84)
        return 84;
    else if ( _argError == 1)
        return 0;
    else if (openConfigFile(_fileName) == 84)
        return 84;
    try {
        fillCameraData();
        fillPrimitivesData();
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Erreur lors de l'accès à la valeur de configuration : " << nfex.what() << std::endl;
        return 84;
    } catch (...) {
        std::cerr << "Une erreur inattendue est survenue. Veuillez vérifier votre fichier de configuration :" << _fileName << std::endl;
        return 84;
    }
    return 0;
}

std::map<std::string, std::string> Parsing::getCameraData() const
{
    return _camera;
}

std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> Parsing::getPrimitivesData() const
{
    return _primitives;
}

int Parsing::getArgError() const
{
    return _argError;
}

// ------------------------------ Private Part ------------------------------

int Parsing::argsManagement (int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Bad arguments, try --help" << std::endl;
        return 84;
    }
    if (strcmp(av[1], "--help") == 0) {
        std::cout << "USAGE: ./raytracer <SCENE_FILE>\n  SCENE_FILE: scene configuration" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string extension = ".cfg";
    if (filename.length() >= extension.length()  && filename.substr(filename.length() - extension.length()) == extension)
        return 0;
    else {
        std::cerr << "Bad file extension, try --help" << std::endl;
        return 84;
    }
}

int Parsing::openConfigFile(std::string file)
{
    try {
        cfg.readFile(file.c_str());
    } catch(const libconfig::FileIOException &fioex) {
        std::cerr << "Erreur lors de la lecture du fichier de configuration : " << fioex.what() << std::endl;
        return 84;
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Erreur lors de l'analyse du fichier de configuration à la ligne " << pex.getLine() << " : " << pex.getError() << std::endl;
        return 84;
    }
    return 0;
}

void Parsing::fillCameraData()
{
    const libconfig::Setting& camera = cfg.lookup("camera");
    fillCameraResolutionData(camera);
    fillCameraPositionData(camera);
    fillCameraDirectionData(camera);
    fillCameraVupData(camera);
    fillCameraFOVData(camera);
}

void Parsing::fillCameraResolutionData(const libconfig::Setting& camera)
{
    const libconfig::Setting& resolution = camera.lookup("resolution");
    int resolutionH, resolutionW;
    resolution.lookupValue("width", resolutionW);
    resolution.lookupValue("height", resolutionH);
    _camera.insert({"height", std::to_string(resolutionH)});
    _camera.insert({"width", std::to_string(resolutionW)});
}

void Parsing::fillCameraPositionData(const libconfig::Setting& camera)
{
    const libconfig::Setting& position = camera.lookup("position");
    double posX, posY, posZ;
    position.lookupValue("x", posX);
    position.lookupValue("y", posY);
    position.lookupValue("z", posZ);
    _camera.insert({"posX", std::to_string(posX)});
    _camera.insert({"posY", std::to_string(posY)});
    _camera.insert({"posZ", std::to_string(posZ)});
}

void Parsing::fillCameraDirectionData(const libconfig::Setting& camera)
{
    const libconfig::Setting& direction = camera.lookup("direction");
    double dirX, dirY, dirZ;
    direction.lookupValue("x", dirX);
    direction.lookupValue("y", dirY);
    direction.lookupValue("z", dirZ);
    _camera.insert({"dirX", std::to_string(dirX)});
    _camera.insert({"dirY", std::to_string(dirY)});
    _camera.insert({"dirZ", std::to_string(dirZ)});
}

void Parsing::fillCameraVupData(const libconfig::Setting& camera)
{
    const libconfig::Setting& vup = camera.lookup("view_up");
    double vupX, vupY, vupZ;
    vup.lookupValue("x", vupX);
    vup.lookupValue("y", vupY);
    vup.lookupValue("z", vupZ);
    _camera.insert({"vupX", std::to_string(vupX)});
    _camera.insert({"vupY", std::to_string(vupY)});
    _camera.insert({"vupZ", std::to_string(vupZ)});
}

void Parsing::fillCameraFOVData(const libconfig::Setting& camera)
{
    float fieldOfView;
    camera.lookupValue("fieldOfView", fieldOfView);
    _camera.insert({"fieldOfView", std::to_string(fieldOfView)});
}

void Parsing::fillPrimitivesData()
{
    const libconfig::Setting& primitives = cfg.lookup("primitives");
    fillPrimitivesSpheresData(primitives);
    fillPrimitivesPlanesData(primitives);
}

void Parsing::fillPrimitivesSpheresData(const libconfig::Setting& primitives)
{
    const libconfig::Setting& spheres = primitives.lookup("spheres");
    for (double i = 0, sphereX, sphereY, sphereZ, sphereR, colorR, colorG, colorB, fuzz; i < spheres.getLength(); i++) {
        const libconfig::Setting& sphere = spheres[i];
        std::string key = "sphere_" + std::to_string(i);

        sphereX = sphere["x"];
        sphereY = sphere["y"];
        sphereZ = sphere["z"];
        sphereR = sphere["r"];
        std::string mat = sphere["material"];
        colorR = sphere["color"]["r"];
        colorG = sphere["color"]["g"];
        colorB = sphere["color"]["b"];

        if (sphere.exists("fuzz")) {
            fuzz = sphere["fuzz"];
            _primitives["spheres"][key]["fuzz"] = std::to_string(fuzz);
        }
        _primitives["spheres"][key]["posX"] = std::to_string(sphereX);
        _primitives["spheres"][key]["posY"] = std::to_string(sphereY);
        _primitives["spheres"][key]["posZ"] = std::to_string(sphereZ);
        _primitives["spheres"][key]["material"] = mat;
        _primitives["spheres"][key]["radius"] = std::to_string(sphereR);
        _primitives["spheres"][key]["colorR"] = std::to_string(colorR);
        _primitives["spheres"][key]["colorG"] = std::to_string(colorG);
        _primitives["spheres"][key]["colorB"] = std::to_string(colorB);
    }
}

void Parsing::fillPrimitivesPlanesData(const libconfig::Setting& primitives)
{
    const libconfig::Setting& planes = primitives.lookup("planes");
    for (double i = 0, planeX, planeY, planeZ, colorR, colorG, colorB, fuzz; i < planes.getLength(); i++) {
        const libconfig::Setting& plane = planes[i];
        std::string key = "plane_" + std::to_string(i);

        planeX = plane["x"];
        planeY = plane["y"];
        planeZ = plane["z"];
        std::string mat = plane["material"];
        colorR = plane["color"]["r"];
        colorG = plane["color"]["g"];
        colorB = plane["color"]["b"];

        if (plane.exists("fuzz")) {
            fuzz = plane["fuzz"];
            _primitives["planes"][key]["fuzz"] = std::to_string(fuzz);
        }
        _primitives["planes"][key]["posX"] = std::to_string(planeX);
        _primitives["planes"][key]["posY"] = std::to_string(planeY);
        _primitives["planes"][key]["posZ"] = std::to_string(planeZ);
        _primitives["planes"][key]["material"] = mat;
        _primitives["planes"][key]["colorR"] = std::to_string(colorR);
        _primitives["planes"][key]["colorG"] = std::to_string(colorG);
        _primitives["planes"][key]["colorB"] = std::to_string(colorB);
    }
}

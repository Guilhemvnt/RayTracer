/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** File
*/

#include "File.hpp"

// ------------------------------ Outside of class Parsing ------------------------------

int ***createColorTab(int height, int width)
{
    int ***tableau = new int**[height];
    for (int i = 0; i != height; i++) {
        tableau[i] = new int*[width];
        for (int j = 0; j != width; j++)
            tableau[i][j] = new int[3];
    }
    return tableau;
}

void destroyColorTab(double ***tableau, double height, double width)
{
    for (int i = 0; i != height; i++) {
        for (int j = 0; j != width; j++)
            delete[] tableau[i][j];
        delete[] tableau[i];
    }
    delete[] tableau;
}

// ------------------------------ Inside of class Parsing ------------------------------

// ------------------------------ Public Part ------------------------------

File::File(std::string fileName, int height, int width)
{
    _fileName = extractFilename(fileName);
    _height = height;
    _width = width;
}

File::~File()
{
}

std::string File::getFileName() const
{
    return _fileName;
}

int File::getHeight() const
{
    return _height;
}

int File::getWidth() const
{
    return _width;
}

void File::setFileName(std::string fileName)
{
    _fileName = fileName;
}

void File::setHeight(int height)
{
    _height = height;
}

void File::setWidth(int width)
{
    _width = width;
}

int File::createFile()
{
    file.open(_fileName);
    printf("%s\n", _fileName.c_str());
    if (file) {
        file << "P3" << std::endl;
        file << _width << " " << _height << std::endl;
        file << "255" << std::endl;
        //
        // for (int i = 0; i < _width; i++) {
        //     for (int j = 0; j < _height; j++) {
        //         for (int k = 0; k < 3; k++) {
        //             file << _color[i][j][k] << " ";
        //         }
        //     }
        //     file << std::endl;
        // }

        // file.close();
    } else {
        std::cout << "Erreur: impossible d'ouvrir le fichier :" << _fileName << std::endl;
        return 84;
    }
    return 0;
}

double clamp(double value, double min, double max)
{
    if (value < min) {
        return min;
    }
    if (value > max)
        return max;
    return value;
}

void File::setCase(int x, int y, Vector3D color, int samples)
{
    auto r = color.x;
    auto g = color.y;
    auto b = color.z;

    auto scale = 1.0 / samples;

    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);
    file << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << " "
         << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << " "
         << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << " ";

    if (y <= 0 && x >= _width - 1) {
        file.close();
    } else if (x >= _width - 1) {
        file << std::endl;
    }
}

// ------------------------------ Private Part ------------------------------

std::string File::extractFilename(std::string filename) {
    filename.pop_back();
    filename.pop_back();
    filename.pop_back();
    size_t lastSlash = filename.find_last_of("/\\");
    filename = filename.substr(lastSlash + 1);
    filename = "screenshots/" + filename + "ppm";
    return filename;
}

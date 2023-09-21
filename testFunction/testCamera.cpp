/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** testCamera
*/

#include "main.hpp"

Vector3D ray_color(const Ray& r, const Vector3D &background ,const ObjectList &world, int depth)
{
    hit_record rec;

    if (depth <= 0)
        return Vector3D(0,0,0);

    if (world.collide(r, 0.001, infinity, rec))
        return background;

    Ray scattered;
    Vector3D attenuation;
    Vector3D emitted = rec.mat_ptr->emitted(rec.u, rec.v, rec.p);

    if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
        return emitted;
    return emitted + attenuation * ray_color(scattered, background, world, depth-1);
}

int testCamera(int ac, char **av)
{
    auto parser = std::make_shared<Parsing>(ac, av);
    if (parser->fillData() == 84)
        return 84;

    printData(parser);

    auto camData = parser->getCameraData();

    const int image_width = std::stoi(camData["width"]);
    const int image_height = std::stoi(camData["height"]);

    Camera cam(camData);

    const int samples_per_pixel = 10;
    const int max_depth = 50;

    std::shared_ptr<File> outputFile = std::make_shared<File>(av[1], image_height, image_width);
    if (outputFile->createFile() == 84)
        return 84;

    Vector3D background(0,0,0);

    auto primData = parser->getPrimitivesData();

    ObjectList world = createObjectList(primData);

    for (int j = image_height - 1; j >= 0 ; j--) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            Vector3D pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + random_double()) / (image_width - 1);
                auto v = (j + random_double()) / (image_height - 1);
                Ray r = cam.getRay(u, v);
                pixel_color += ray_color(r, background, world, max_depth);
            }
            outputFile->setCase(i, j, pixel_color, samples_per_pixel);
        }
    }
    std::cerr << "\nDone\n";
    return 0;
}


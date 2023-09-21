/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** File
*/

#ifndef FILE_HPP_
    #define FILE_HPP_

    #include <iostream>
    #include <fstream>
    #include <memory>
    #include "Ray.hpp"

    class File {
        public:
            // Constructor and Desestuctor functions
            File(std::string fileName, int height, int width);
            ~File();

            // Get functions
            std::string getFileName() const;
            int getHeight() const;
            int getWidth() const;

            // Set functions
            void setFileName(std::string fileName);
            void setHeight(int height);
            void setWidth(int width);
            void setCase(int x, int y, Vector3D color, int samples);

            // Fill file with data
            int createFile();

        private:
            //from cfg to ppm filename
            std::string extractFilename(std::string path);

        protected:
            std::string _fileName;
            int _height;
            int _width;
            std::ofstream file;
    };

    int ***createColorTab(int height, int width);
    void destroyColorTab(int ***tableau, int height, int width);

#endif /* !FILE_HPP_ */

/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
    #define PARSING_HPP_

    #include <iostream>
    #include <libconfig.h++>
    #include <cstring>
    #include <map>
    #include <memory>
    #include <cmath>

    class Parsing {
        public:
            // Constructor and Desestuctor functions
            Parsing(int ac, char **av);
            ~Parsing();

            // Parsing file function
            int fillData();

            // Get functions
            std::map<std::string, std::string> getCameraData() const;
            std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> getPrimitivesData() const;
            int getArgError() const;

        private:
            // Managing argument
            int argsManagement (int ac, char **av);

            // Read file function
            int openConfigFile(std::string file);

            // Get Camera informations
            void fillCameraData();
            void fillCameraResolutionData(const libconfig::Setting& camera);
            void fillCameraPositionData(const libconfig::Setting& camera);
            void fillCameraDirectionData(const libconfig::Setting& camera);
            void fillCameraVupData(const libconfig::Setting& camera);
            void fillCameraFOVData(const libconfig::Setting& camera);

            // Get Primitives informations
            void fillPrimitivesData();
            void fillPrimitivesSpheresData(const libconfig::Setting& primitives);
            void fillPrimitivesPlanesData(const libconfig::Setting& primitives);

        protected:
            libconfig::Config cfg;
            std::map<std::string, std::string> _camera;
            std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> _primitives;
            int _argError;
            std::string _fileName;
    };

    // Print Data
    void printData(std::shared_ptr<Parsing> parser);

#endif /* !PARSING_HPP_ */

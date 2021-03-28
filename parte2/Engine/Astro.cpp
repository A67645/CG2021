#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <list>

#include "Astro.h"

std::string filename;
std::list <float> points;
float translateX;
float translateY;
float translateZ;
float rotateAngle;
float rotateX;
float rotateY;
float rotateZ;
float scaleX;
float scaleY;
float scaleZ;
float red;
float green;
float blue;

    Astro::Astro(){
        filename = "sol.3d";
        Astro::readFile();
        translateX = 0.0f;
        translateY = 0.0f;
        translateZ = 0.0f;
        rotateAngle = 0.0f;
        rotateX = 0.0f;
        rotateY = 0.0f;
        rotateZ = 0.0f;
        scaleX = 1.0f;
        scaleY = 1.0f;
        scaleZ = 1.0f;
        red = 0.99f;
        green = 0.72f;
        blue = 0.07f;
    }

    Astro::Astro(std::string file, float tX, float tY, float tZ, float a, float rX, float rY, float rZ, float sX, float sY, float sZ, float r, float g, float b){
        filename = file;
        Astro::readFile();
        translateX = tX;
        translateY = tY;
        translateZ = tZ;
        rotateAngle = a;
        rotateX = rX;
        rotateY = rY;
        rotateZ = rZ;
        scaleX = sX;
        scaleY = sY;
        scaleZ = sZ;
        red = r;
        green = g;
        blue = b;
    }

    std::string Astro::getFilename(){ return filename; }

    std::list <float> Astro::getPoints() {
        std::list <float> res;
        for(float p : points){
            res.push_back(p);
        }
        return res;
    }

    float Astro::getTranslateX(){ return translateX; }
    float Astro::getTranslateY(){ return translateY; }
    float Astro::getTranslateZ(){ return translateZ; }
    float Astro::getAngle(){ return rotateAngle; }
    float Astro::getRotateX(){ return rotateX; }
    float Astro::getRotateY(){ return rotateY; }
    float Astro::getRotateZ(){ return rotateZ; }
    float Astro::getScaleX(){ return scaleX; }
    float Astro::getScaleY(){ return scaleY; }
    float Astro::getScaleZ(){ return scaleZ; }
    float Astro::getRed(){ return red; }
    float Astro::getGreen(){ return green; }
    float Astro::getBlue(){ return blue; }

    void Astro::readFile() {

        std::ifstream infile(filename);
        float x, y, z;

        if (!infile) {
            std::cout << "Ocorreu um erro na leitura do ficheiro." << std::endl;
            return;
        }

        while (infile >> x >> y >> z) {
            points.push_back(x);
            points.push_back(y);
            points.push_back(z);
        }
    }
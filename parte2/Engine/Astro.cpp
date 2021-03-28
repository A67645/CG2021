//
// Created by mel on 27/03/2021.
//
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <list>

#include "Astro.h"

using namespace std;

class Astro{
public:
    string filename;
    list <float> points;
    float translateX;
    float translateY;
    float translateZ;
    float angle;
    float rotateX;
    float rotateY;
    float rotateZ;
    float scaleX;
    float scaleY;
    float scaleZ;

    Astro(){
        filename = "sol.3d";
        readFile();
        translateX = 0.0f;
        translateY = 0.0f;
        translateZ = 0.0f;
        angle = 0.0f;
        rotateX = 0.0f;
        rotateY = 0.0f;
        rotateZ = 0.0f;
        scaleX = 1.0f;
        scaleY = 1.0f;
        scaleZ = 1.0f;
    }

    Astro(string file, float tX, float tY, float tZ, float a, float rX, float rY, float rZ, float sX, float sY, float sZ,){
        filename = file;
        readFile();
        translateX = tX;
        translateY = tY;
        translateZ = tZ;
        angle = a;
        rotateX = rX;
        rotateY = rY;
        rotateZ = rZ;
        scaleX = sX;
        scaleY = sY;
        scaleZ = sZ;
    }

    string getFilename(){ return filename; }
    list <float> getPoints() {
        list <float> res;
        for(float p : points){
            res.push_back(p);
        }
        return res;
    }
    float getTranslateX(){ return translateX; }
    float getTranslateY(){ return translateY; }
    float getTranslateZ(){ return translateZ; }
    float getAngle(){ return angle; }
    float getRotateX(){ return rotateX; }
    float getRotateY(){ return rotateY; }
    float getRotateZ(){ return rotateZ; }
    float getScaleX(){ return scaleX; }
    float getScaleY(){ return scaleY; }
    float getScaleZ(){ return scaleZ; }

    void readFile() {

#ifndef ASTRO_H
#define ASTRO_H

#include <list>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <list>
#include <vector>
#include <GL/glew.h>



class Astro{
private:
    std::string filename;
    std::vector<float> points;
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
    bool anel;
    float time;
    std::list <Astro> luas;
    GLuint *buffer = (GLuint*) malloc(16 *sizeof(GLuint));

public:
    Astro();
    Astro(std::string file, float tX, float tY, float tZ, float a, float rX, float rY, float rZ, float sX, float sY, float sZ, float r, float g, float b);
    std::string getFilename();
    std::vector<float> getPoints();
    float getTranslateX();
    float getTranslateY();
    float getTranslateZ();
    float getAngle();
    float getRotateX();
    float getRotateY();
    float getRotateZ();
    float getScaleX();
    float getScaleY();
    float getScaleZ();
    float getRed();
    float getGreen();
    float getBlue();
    void readFile();

    void setFilename(const std::string &filename);

    void setColor(float red, float green, float blue);

    void setTranslate(float red, float green, float blue);

    void setRotate(float angle, float x, float y, float z);

    void setScale(float x, float y, float z);

    void add(Astro astro);

    std::list<Astro> getLuas();

    void makeVBO();

    void draw();

    bool getAnel();

    void setAnel(bool anel);

    void setTime(float d);
};

#endif


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

class Objeto{
private:
    std::string filename;
    std::string texture;
    int size;
    int td;
    int tw;
    float diffR;
    float diffG;
    float diffB;
    std::vector<float*> translate;
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
    std::list <Objeto> luas;
    GLuint buffers[3];
    void normalize2(float *a);
    void cross2(float *a, float *b, float *res);
    std::vector<float> computeNormal(std::vector<float> points);

public:
    Objeto();
    Objeto(std::string file, float tX, float tY, float tZ, float a, float rX, float rY, float rZ, float sX, float sY, float sZ, float r, float g, float b);
    std::string getFilename();
    std::vector<float> getPoints();
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
    float getTranslateX();
    float getTranslateY();
    float getTranslateZ();

    void setFilename(const std::string &filename);

    void setTranslate(float x, float y, float z);

    void setColor(float red, float green, float blue);

    void setRotate(float angle, float x, float y, float z);

    void setScale(float x, float y, float z);

    void add(Objeto astro);

    std::list<Objeto> getLuas();

    void draw();

    bool getAnel();

    void setAnel(bool anel);

    void setTime(float d);

    float getTime();

    void setPointsTranslate(std::vector<float*> translate);

    std::vector<float *> getTranslate();

    void makeVBO(std::vector<float> points);
};

#endif


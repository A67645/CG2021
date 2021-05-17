#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <GL/glew.h>

#include "Objeto.h"

Objeto::Objeto() {
    size = 0;
    filename = "";
    texture = "";
    diffR = 0.0f;
    diffG = 0.0f;
    diffB = 0.0f;
    rotateAngle = 0.0f;
    translateX = 0.0f;
    translateY = 0.0f;
    translateZ = 0.0f;
    rotateX = 0.0f;
    rotateY = 0.0f;
    rotateZ = 0.0f;
    scaleX = 1.0f;
    scaleY = 1.0f;
    scaleZ = 1.0f;
    red = 0.0f;
    green = 0.0f;
    blue = 0.0f;
    anel = false;
    time = 0.1;
    positions =  (GLuint*) malloc(sizeof(GLuint));
    normals =  (GLuint*) malloc(sizeof(GLuint));
    texCoords =  (GLuint*) malloc(sizeof(GLuint));
}

std::string Objeto::getFilename() { return filename; }

std::vector<float *> Objeto::getTranslate() { return translate; }

float Objeto::getAngle() { return rotateAngle; }

float Objeto::getRotateX() { return rotateX; }

float Objeto::getRotateY() { return rotateY; }

float Objeto::getRotateZ() { return rotateZ; }

float Objeto::getScaleX() { return scaleX; }

float Objeto::getScaleY() { return scaleY; }

float Objeto::getScaleZ() { return scaleZ; }

float Objeto::getRed() { return red; }

float Objeto::getGreen() { return green; }

float Objeto::getBlue() { return blue; }

bool Objeto::getAnel() { return anel; }

float Objeto::getTranslateX(){ return translateX; }
float Objeto::getTranslateY(){ return translateY; }
float Objeto::getTranslateZ(){ return translateZ; }

std::list<Objeto> Objeto::getLuas() { return luas; }

float Objeto::getTime() { return Objeto::time; }

void Objeto::setFilename(const std::string &filename) {
    Objeto::filename = filename;
}

void Objeto::setColor(float red, float green, float blue) {
    Objeto::red = red;
    Objeto::green = green;
    Objeto::blue = blue;
}

void Objeto::setRotate(float angle, float x, float y, float z) {
    Objeto::rotateAngle = angle;
    Objeto::rotateX = x;
    Objeto::rotateY = y;
    Objeto::rotateZ = z;
}

void Objeto::setScale(float x, float y, float z) {
    Objeto::scaleX = x;
    Objeto::scaleY = y;
    Objeto::scaleZ = z;
}

void Objeto::setAnel(bool anel) {
    Objeto::anel = anel;
}

void Objeto::setTime(float time) {
    Objeto::time = time;
}

void Objeto::setTranslate(float x, float y, float z) {
    Objeto::translateX = x;
    Objeto::translateY = y;
    Objeto::translateZ = z;
}

void Objeto::setPointsTranslate(std::vector<float *> translate) {
    Objeto::translate = translate;
}

void cross2(float *a, float *b, float *res) {
    res[0] = a[1]*b[2] - a[2]*b[1];
    res[1] = a[2]*b[0] - a[0]*b[2];
    res[2] = a[0]*b[1] - a[1]*b[0];
}

void normalize2(float *a) {

    float l = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
    a[0] = a[0] / l;
    a[1] = a[1] / l;
    a[2] = a[2] / l;
}

std::vector<float> computeNormal(std::vector<float> points){
    std::vector<float> vertexNormal;

    for(int i = 0; i < points.size(); i+=3*3){
        float p1[3] = {points.at(3*i), points.at(3*i+1), points.at(3*i+2)};
        float p2[3] = {points.at(3*(i+1)), points.at(3*(i+1)+1), points.at(3*(i+1)+2)};
        float p3[3] = {points.at(3*(i+2)), points.at(3*(i+2)+1), points.at(3*(i+2)+2)};

        float u[3] = {p2[0]-p1[0], p2[1]-p1[1], p2[2]-p1[2]};
        float v[3] = {p3[0]-p1[0], p3[1]-p1[1], p3[2]-p1[2]};

        float normal[3];

        cross2(u,v,normal);
        normalize2(normal);

        for(int j = 0; j < 3; j++){
            vertexNormal.push_back(normal[0]);
            vertexNormal.push_back(normal[1]);
            vertexNormal.push_back(normal[2]);
        }
    }

    return vertexNormal;
}

void Objeto::readFile() {
    std::ifstream infile(filename);
    float x, y, z;

    std::vector<float> points;

    if (!infile) {
        std::cout << "Ocorreu um erro na leitura do ficheiro." << std::endl;
        return;
    }

    while (infile >> x >> y >> z) {
        points.push_back(x);
        points.push_back(y);
        points.push_back(z);
    }

    makeVBO(points);

    size = points.size();

    points.clear();
}

void Objeto::add(Objeto astro) {
    luas.push_back(astro);
}

void Objeto::makeVBO(std::vector<float> points) {
    glGenBuffers(1, positions);
    glBindBuffer(GL_ARRAY_BUFFER, positions[0]);
    glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(float), points.data(), GL_STATIC_DRAW);
}

void Objeto::draw() {
    glBindBuffer(GL_ARRAY_BUFFER, positions[0]);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, size);
} //glgeterror()

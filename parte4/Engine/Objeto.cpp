#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <vector>
#include <GL/glew.h>
#include <IL/il.h>
#include <sstream>

#include "Objeto.h"

Objeto::Objeto() {
    sizeP = 0;
    sizeN = 0;
    sizeT = 0;
    filename = "";
    texfilename = "";
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

void Objeto::setTexfilename(const std::string &file){
  Objeto::texfilename = file;
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

void Objeto::readFile() {
    std::ifstream infile(filename);
    std::string x, y, z;

    std::vector<float> points;
    std::vector<float> normal;
    std::vector<float> textura;

    if (!infile) {
        std::cout << "Ocorreu um erro na leitura do ficheiro." << std::endl;
        return;
    }

    loadTexture();

    std::string buffer;
    while (true) {
        getline(infile, buffer);
        std::stringstream ss(buffer);
        ss >> x >> y >> z;
        if(x == "cucu")
            break;
        points.push_back(std::atof(x.data()));
        points.push_back(std::atof(y.data()));
        points.push_back(std::atof(z.data()));
    }

    while (true) {
        getline(infile, buffer);
        std::stringstream ss(buffer);
        ss >> x >> y >> z;
        if(x == "cucu")
            break;
        normal.push_back(std::atof(x.data()));
        normal.push_back(std::atof(y.data()));
        normal.push_back(std::atof(z.data()));
    }

    while (true) {
        getline(infile, buffer);
        std::stringstream ss(buffer);
        ss >> x >> y >> z;
        if(x == "cucu")
            break;
        textura.push_back(std::atof(x.data()));
        textura.push_back(std::atof(y.data()));
        textura.push_back(std::atof(z.data()));
    }

/*
    while (infile >> x >> y >> z) {
        points.push_back(x);
        points.push_back(y);
        points.push_back(z);         //TODO - separador de pontos
    }
    while (infile >> x >> y >> z) {
        normal.push_back(x);
        normal.push_back(y);
        normal.push_back(z);
    }
    while (infile >> x >> y >> z) {
        textura.push_back(x);
        textura.push_back(y);
        textura.push_back(z);
    }
*/
    glGenBuffers(3, buffers);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(float), points.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
    glBufferData(GL_ARRAY_BUFFER, normal.size() * sizeof(float), normal.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
    glBufferData(GL_ARRAY_BUFFER, textura.size() * sizeof(float), textura.data(), GL_STATIC_DRAW);


    sizeP = points.size();
    sizeN = normal.size();
    sizeT = textura.size();

    points.clear(); normal.clear(); textura.clear();
}

void Objeto::add(Objeto astro) {
    luas.push_back(astro);
}


void Objeto::draw() {
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
    glNormalPointer(GL_FLOAT,0,0);

    glBindBuffer(GL_ARRAY_BUFFER,buffers[2]);
    glTexCoordPointer(2,GL_FLOAT,0,0);
    //glBindTexture(GL_TEXTURE_2D,texID);
    glDrawArrays(GL_TRIANGLES, 0, sizeP);
    //glBindTexture(GL_TEXTURE_2D,0);

}

void Objeto::loadTexture() {

    unsigned int t,tw,th;
    unsigned char *texData;

    ilInit();
    ilEnable(IL_ORIGIN_SET);
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
    ilGenImages(1,&t);
    ilBindImage(t);
    ilLoadImage((ILstring)texfilename.c_str());
    tw = ilGetInteger(IL_IMAGE_WIDTH);
    th = ilGetInteger(IL_IMAGE_HEIGHT);
    ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    texData = ilGetData();

    glGenTextures(1,&texID);

    glBindTexture(GL_TEXTURE_2D,texID);
    glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_WRAP_S,		GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_WRAP_T,		GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_MAG_FILTER,   	GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);
}

//glgeterror()
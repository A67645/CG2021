#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include "tinyxml2.h"
#include "Astro.h"
#include <list>

using namespace std;
using namespace tinyxml2;

float cx=0.0f;
float cy=0.0f;
float cz=0.0f;
float angle = 0.0f;
float angle2 = 0.0f;
float size = 1.0f;

list< Astro > lista;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if (h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

void draw(){
    float x,y,z;
    glPolygonMode(GL_FRONT, GL_LINE);

    glBegin(GL_TRIANGLES);
    for(auto itLista = lista.begin(); itLista != lista.end(); itLista++){
        glColor3f(itLista->getRed(),itLista->getGreen(),itLista->getBlue());
        list <float> points = itLista->getPoints();
        for(auto itPoints = points.begin(); itPoints != points.end(); itPoints++) {
            x = *(itPoints++);
            y = *(itPoints++);
            z = *itPoints;
            glVertex3f(x, y, z);
        }
    }
    glEnd();
}


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(10.0f,10.0f,10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

		glBegin(GL_LINES);
			// X axis in red
			glColor3f(1.0f, 0.0f, 0.0f);
				glVertex3f(-100.0f, 0.0f, 0.0f);
				glVertex3f(100.0f, 0.0f, 0.0f);
			// Y Axis in Green
			glColor3f(0.0f, 1.0f, 0.0f);
				glVertex3f(0.0f, -100.0f, 0.0f);
				glVertex3f(0.0f, 100.0f, 0.0f);
			// Z Axis in Blue
			glColor3f(0.0f, 0.0f, 1.0f);
				glVertex3f(0.0f, 0.0f, -100.0f);
				glVertex3f(0.0f, 0.0f, 100.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
		glEnd();
		

	// put the geometric transformations here
    glTranslatef(cx, cy, cz);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glRotatef(angle2, 0.0f, 0.0f, 1.0f);

    glScalef(size, size, size);

	// put drawing instructions here
    draw();

	// End of frame
	glutSwapBuffers();
}

void readGroup(XMLElement* group){
    float tx=0, ty=0, tz=0, a=0, rx=0, ry=0, rz=0, sx=0, sy=0, sz=0, r=0, g=0, b=0;
    XMLElement *colour = group->FirstChildElement("colour");
    if (colour != nullptr) {
        r = atof(colour->Attribute("R"));
        g = atof(colour->Attribute("G"));
        b = atof(colour->Attribute("B"));
        printf("colour-%f %f %f\n",r,g,b);
    }
    XMLElement *translate = group->FirstChildElement("translate");
    if (translate != nullptr) {
        tx = atof(translate->Attribute("X"));
        ty = atof(translate->Attribute("Y"));
        tz = atof(translate->Attribute("Z"));
        printf("translate-%f %f %f\n",tx,ty,tz);
    }
    XMLElement *rotate = group->FirstChildElement("rotate");
    if (rotate != nullptr) {
        a = atof(rotate->Attribute("angle"));
        rx = atof(rotate->Attribute("axisX"));
        ry = atof(rotate->Attribute("axisY"));
        rz = atof(rotate->Attribute("axisZ"));
        printf("rotate-%f %f %f\n",rx,ry,rz);
    }
    XMLElement *scale = group->FirstChildElement("scale");
    if (scale != nullptr) {
        sx = atof(scale->Attribute("X"));
        sy = atof(scale->Attribute("Y"));
        sz = atof(scale->Attribute("Z"));
        printf("scale-%f %f %f\n",sx,sy,sz);
    }
    XMLElement *models = group->FirstChildElement("models");
    for (XMLElement *model = models->FirstChildElement("model");
        model != nullptr; model = model->NextSiblingElement("model")) {
        string file3d = model->Attribute("file");
        Astro astro = Astro(file3d, tx, ty, tz, a, rx, ry, rz, sx, sy, sz, r, g, b);
        lista.push_back(astro);
    }
    XMLElement *childGroup = group->FirstChildElement("group");
    if(childGroup!=nullptr){readGroup(childGroup);}
}

bool readXML(string file) {
	XMLDocument doc;
	XMLElement* firstElem;
	printf("%s\n",file.c_str());
	if (!doc.LoadFile(file.c_str())) {
		firstElem = doc.FirstChildElement("scene");
		for (XMLElement* group = firstElem->FirstChildElement("group"); group != nullptr; group = group->NextSiblingElement("group")) {
		    readGroup(group);
		}
		return true;
	}
	else {
		cout << "Ocorreu um erro na leitura do ficheiro XML." << endl;
	    return false;
	}

}

// write function to process keyboard events
void keyFunction(unsigned char key, int xx, int yy) {
    switch (key) {
        case 'x':	cx -= 0.2f; break;

        case 'X':	cx += 0.2f; break;

        case 'y':	cy -= 0.2f; break;

        case 'Y':	cy += 0.2f; break;

        case 'z':	cz -= 0.2f; break;

        case 'Z':	cz += 0.2f; break;

        case 'r':	angle -= 10.0f; break;

        case 'R':	angle += 10.0f; break;

        case 'T':	angle2 += 10.0f; break;

        case 't':	angle2 -= 10.0f; break;

        case '+':	size += 0.05f; break;

        case '-':	size -= 0.05f; break;
    }

    if (size > 0)
        glFrontFace(GL_CCW);
    else
        glFrontFace(GL_CW);

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    if(argc>2){cout << "Too many arguments! Expected 1 argument!" << endl; return -1;}
    if(argc<2){cout << "Not enough arguments! Expected 1 argument!" << endl; return -1;}

    string path = "../";
    string file = argv[1];

    if(!readXML(path + file + ".xml")){
        cout << "Ficheiro nao lido." << endl;
        return -1;
    }

	// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("CG@DI-UM");

	// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

    glutKeyboardFunc(keyFunction);

	//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}

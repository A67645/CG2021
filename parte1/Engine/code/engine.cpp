#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

float cx=0.0f;
float cy=0.0f;
float cz=0.0f;
float angle = 0.0f;
float angle2 = 0.0f;
float size = 1.0f;

void readXML(string file);

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
    readXML("C:/Computacao Grafica/Projeto/Engine/code/configuration.xml");

	// End of frame
	glutSwapBuffers();
}


// write function to process keyboard events


void readFile(string file) {

	ifstream infile(file);
	float x, y, z;
	glPolygonMode(GL_FRONT, GL_LINE);

	if (!infile) {
		cout << "Ocorreu um erro na leitura do ficheiro." << endl;
		return;
	}

	glBegin(GL_TRIANGLES);

	glColor3f(0.8f, 0.5f, 0.8f);
		while (infile >> x >> y >> z) {
			glVertex3f(x, y, z);
		}

	glEnd();
}

void readXML(string file) {
	XMLDocument doc;
	XMLElement* firstElem;
	if (!doc.LoadFile(file.c_str())) {
		firstElem = doc.FirstChildElement("scene");
		for (XMLElement* model = firstElem->FirstChildElement("model"); model != NULL; model = model->NextSiblingElement("model")) {
		    string file3d = model->Attribute("file");
			readFile(file3d);
		}
	}
	else {
		cout << "Ocorreu um erro na leitura do ficheiro XML." << endl;
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
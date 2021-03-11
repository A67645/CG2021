#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include "tinyxml2.h"

using namespace std;



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
	gluLookAt(5.0f,5.0f,5.0f,
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


	// put drawing instructions here
	

	// End of frame
	glutSwapBuffers();
}


// write function to process keyboard events


void readFile(string file) {

	ifstream infile(file);
	float x, y, z;
	glPolygonMode(GL_FRONT | GL_FILL);

	if (!file) {
		cout << "Ocorreu um erro na leitura do ficheiro." << endl;
		return -1;
	}

	glBegin(GL_TRIANGLES);

	glColor3f(0.33f, 0.42f, 0.18f);
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
		for (XMLElement* model = firstElem->FirstChildElement("model"); model != NULL; nexElem = model->FirstChildElem("model") {
			string 3dfile = model->Attribute("file");
			readFile(3dfile);
		}
	}
	else {
		cout << "Ocorreu um erro na leitura do ficheiro XML." << endl;
	}

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


	// put here the registration of the keyboard callbacks
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);

	//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	readXML(configuration);

	// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}

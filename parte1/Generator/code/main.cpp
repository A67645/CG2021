#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

void drawPlane(float size, char* fileName) {
	float halfSize = size / 2;

	ofstream file(fileName);
    if (file.is_open()) {

		file << halfSize	<< 0.0 << halfSize	<< "\n";
		file << halfSize	<< 0.0 << -halfSize << "\n";
		file << -halfSize	<< 0.0 << halfSize	<< "\n";

		file << halfSize	<< 0.0 << -halfSize << "\n";
		file << -halfSize	<< 0.0 << -halfSize << "\n";
		file << -halfSize	<< 0.0 << halfSize	<< "\n";

		file << halfSize	<< 0.0 << halfSize	<< "\n";
		file << -halfSize	<< 0.0 << halfSize	<< "\n";
		file << halfSize	<< 0.0 << -halfSize << "\n";

		file << halfSize	<< 0.0 << -halfSize << "\n";
		file << -halfSize	<< 0.0 << halfSize	<< "\n";
		file << -halfSize	<< 0.0 << -halfSize << "\n";
    }
    file.close();
}

void drawBox(float x, float y, float z, int n, char* fileName) {
	float xx = x / n;
	float yy = y / n;
	float zz = z / n;

	ofstream file(fileName);
	if (file.is_open()) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				//Frente:
				file << "" << i * xx		<< " " << j * yy		<< " " << z << "\n";
				file << "" << i * xx + xx	<< " " << j * yy		<< " " << z << "\n";
				file << "" << i * xx + xx	<< " " << j * yy + yy	<< " " << z << "\n";

				file << "" << i * xx		<< " " << j * yy		<< " " << z << "\n";
				file << "" << i * xx + xx	<< " " << j * yy + yy	<< " " << z << "\n";
				file << "" << i * xx		<< " " << j * yy + yy	<< " " << z << "\n";

				//Tras:
				file << "" << i * xx		<< " " << j * yy		<< " " << 0 << "\n";
				file << "" << i * xx + xx	<< " " << j * yy + yy	<< " " << 0 << "\n";
				file << "" << i * xx + xx	<< " " << j * yy		<< " " << 0 << "\n";

				file << "" << i * xx		<< " " << j * y			<< " " << 0 << "\n";
				file << "" << i * xx		<< " " << j * yy + yy	<< " " << 0 << "\n";
				file << "" << i * xx + xx	<< " " << j * yy + yy	<< " " << 0 << "\n";

				//Cima:
				file << "" << i * xx		<< " " << y << " " << j * zz		<< "\n";
				file << "" << i * xx		<< " " << y << " " << j * zz + zz	<< "\n";
				file << "" << i * xx + xx	<< " " << y << " " << j * zz		<< "\n";

				file << "" << i * xx		<< " " << y << " " << j * zz + zz	<< "\n";
				file << "" << i * xx + xx	<< " " << y << " " << j * zz + zz	<< "\n";
				file << "" << i * xx + xx	<< " " << y << " " << j * zz		<< "\n";

				//Baixo:
				file << "" << i * xx		<< " " << 0 << " " << j * zz		<< "\n";
				file << "" << i * xx + xx	<< " " << 0 << " " << j * zz		<< "\n";
				file << "" << i * xx		<< " " << 0 << " " << j * zz + zz	<< "\n";

				file << "" << i * xx + xx	<< " " << 0 << " " << j * zz		<< "\n";
				file << "" << i * xx		<< " " << 0 << " " << j * zz + zz	<< "\n";
				file << "" << i * xx + xx	<< " " << 0 << " " << j * zz + zz	<< "\n";
				
				//Direita:
				file << "" << x << " " << j * yy		<< " " << i * zz		<< "\n";
				file << "" << x << " " << j * yy + yy	<< " " << i * zz		<< "\n";
				file << "" << x << " " << j * yy		<< " " << i * zz + zz	<< "\n";

				file << "" << x << " " << j * yy + yy	<< " " << i * zz		<< "\n";
				file << "" << x << " " << j * yy + yy	<< " " << i * zz + zz	<< "\n";
				file << "" << x << " " << j * yy		<< " " << i * zz + zz	<< "\n";

				//Esquerda:
				file << "" << 0 << " " << j * yy		<< " " << i * zz		<< "\n";
				file << "" << 0 << " " << j * yy		<< " " << i * zz + zz	<< "\n";
				file << "" << 0 << " " << j * yy + yy	<< " " << i * zz		<< "\n";

				file << "" << 0 << " " << j * yy		<< " " << i * zz + zz	<< "\n";
				file << "" << 0 << " " << j * yy + yy	<< " " << i * zz + zz	<< "\n";
				file << "" << 0 << " " << j * yy + yy	<< " " << i * zz		<< "\n";

			}
		}
	}
}

void drawSphere(float radius, int slices, int stacks, char* fileName) {
	float phi = 0, deslocP = M_PI / stacks;
	float theta = M_PI/2, deslocT = 2 * M_PI / slices;

	float ax, ay, az;
	float bx, by, bz;
	float cx, cy, cz;
	float dx, dy, dz;

	ofstream file(fileName);
	if (file.is_open()) {
		for (int i = 0; i < slices; i++) {
			for (int j = 0; j < stacks; j++) {
				phi = j * deslocP;

				//inferior direito
				ax = radius * sin(theta) * sin(phi);
				ay = radius * cos(phi);
				az = radius * cos(theta) * sin(phi);

				//inferior esquerdo
				bx = radius * sin(theta + deslocT) * sin(phi);
				by = radius * cos(phi);
				bz = radius * cos(theta + deslocT) * sin(phi);

				//superior direito
				cx = radius * sin(theta) * sin(phi + deslocP);
				cy = radius * cos(phi + deslocP);
				cz = radius * cos(theta) * sin(phi + deslocP);

				//superior esquerdo
				dx = radius * sin(theta + deslocT) * sin(phi + deslocP);
				dy = radius * cos(phi + deslocP);
				dz = radius * cos(theta + deslocT) * sin(phi + deslocP);

				file << "" << ax << " " << ay << " " << az << "\n";
				file << "" << dx << " " << dy << " " << dz << "\n";
				file << "" << bx << " " << by << " " << bz << "\n";

				file << "" << ax << " " << ay << " " << az << "\n";
				file << "" << cx << " " << cy << " " << cz << "\n";
				file << "" << dx << " " << dy << " " << dz << "\n";

			}
			theta -= deslocT;
		}
	}
}

void drawCone(float radius, float height, int slices, int stacks, char* fileName) {
	float alfa = 0, deslocA = 2*M_PI / slices;
	float hStack = height / stacks;
	float rStack = radius / stacks;

	float ax, ay, az;
	float bx, by, bz;
	float cx, cy, cz;
	float dx, dy, dz;

	ofstream file(fileName);
	if (file.is_open()) {
		for (int i = 0; i < slices; i++) {
			float base = 0; //com a base do cone com centro na origem, se quisermos centrar o cone na origem, é só alterar para "-height/2" 
			float rInferior = radius - rStack*j;
			float rSuperior = radius - rStack*(j+1);

			//inferior esquerdo
			ax = rInferior * sin(alfa);
			ay = base;
			az = rInferior * cos(alfa);

			//inferior direito
			bx = rInferior * sin(alfa + deslocA);
			by = base;
			bz = rInferior * cos(alfa + deslocA);

			//superior direito
			cx = rSuperior * sin(alfa + deslocA);
			cy = base + hStack;
			cz = rSuperior * cos(alfa + deslocA);

			//superior esquerdo
			dx = rSuperior * sin(alfa);
			dy = base + hStack;
			dz = rSuperior * cos(alfa);

			//base
			file << "" << "0" << " " << base << " " << "0" << "\n";
			file << "" << bx << " " << by << " " << bz << "\n";
			file << "" << ax << " " << ay << " " << az << "\n";

			for (int j = 0; j < stacks; j++) {

				file << "" << ax << " " << ay << " " << az << "\n";
				file << "" << bx << " " << by << " " << bz << "\n";
				file << "" << cx << " " << cy << " " << cz << "\n";

				file << "" << ax << " " << ay << " " << az << "\n";
				file << "" << cx << " " << cy << " " << cz << "\n";
				file << "" << dx << " " << dy << " " << dz << "\n";
				
				base += hStack;
			}
			alfa += deslocA;
		}
	}
}

int main(int argc, char **argv) {

	if (argv[1] == "plane" && argc == 4)
		drawPlane(atof(argv[2]), argv[3]);

	else if (argv[1] == "box" && argc == 6)
		drawBox(atof(argv[2]), atof(argv[3]), atof(argv[4]), 1, argv[5]);
	else if (argv[1] == "box" && argc == 7)
		drawBox(atof(argv[2]), atof(argv[3]), atof(argv[4]), atoi(argv[5]), argv[6]);

	else if (argv[1] == "sphere" && argc == 6)
		drawSphere(atof(argv[2]), atoi(argv[3]), atoi(argv[4]), argv[5]);

	else if (argv[1] == "cone" && argc == 7)
		drawCone(atof(argv[2]), atof(argv[3]), atoi(argv[4]), atoi(argv[5]), argv[6]);

	else printf("Invalid input format\n");

	return 1;
}

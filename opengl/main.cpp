#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <GLUT/glut.h>
#else
	#ifdef WIN32
		#include <GL/glut.h>
	#else
		#ifdef __linux__
			#include <GL/gl.h>
			#include <GL/glut.h>
		#else
			#error "Unknown platform!"
	#endif //UNIX
	#endif //WIN32
#endif //APPLE

#include "color.h"

const int width = 320;
const int height = 320;

Color buffer[width*height];

typedef unsigned int uint32;

void doStuff(Color* image) {

	Color R(1.f, 0.f, 0.f);
	Color G(0.f, 1.f, 0.f);
	Color B(0.f, 0.f, 1.f);
	Color C(0.f, 1.f, 1.f);


	for (int y = 0; y < height; y++) {
		const float k = y / float(height-1);

		Color P = R*k + C*(1-k);
		Color Q = B*k + G*(1-k);

		for (int x = 0; x < width; x++) {
			const float k = x / float(width-1);
			image[y*width + x] = P*k + Q*(1-k);
		}
	}
}

void display() {

	doStuff(buffer);

	glDrawPixels(width, height, GL_RGB, GL_FLOAT ,(float*)buffer);
	glutSwapBuffers();

	//glutPostRedisplay();
	glFlush();
}


int main(int argc, char ** argv) {

	glutInit(&argc, argv);                 // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(width, height);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();

	return 0;
}

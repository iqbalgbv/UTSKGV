// CobaBab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <gl/glut.h>

float sumbu_x = 0;
float sumbu_y = 0;
int nos;
bool done = false;
bool done2 = false;
void write(float x, float y, float z, void* font, const char* string) {
	const char* c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}
void userdraw()
{
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex2f(-1.0, 1.0);
	glVertex2f(1.0, 1.0);
	glColor3f(0.5, 1, 0.5);
	glVertex2f(1.0, -1.0);
	glVertex2f(-1.0, -1.0);
	glEnd();
}

void tampil() {
	glBegin(GL_POLYGON);
	glVertex2f(-0.4, -0.32);
	glVertex2f(-0.8, 0.4);
	glVertex2f(0.32, 0.4);
	glVertex2f(0.32, 0.32);
	glEnd();
}

void mobil() {
	//badan truk
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(-0.9, 0.2);
	glVertex2f(-0.4, 0.2);
	glVertex2f(-0.4, 0.7);
	glVertex2f(-0.9, 0.7);
	glEnd();
	glBegin(GL_POLYGON); //pintu kotak
	glColor3f(0, 1, 1);
	glVertex2f(-0.4, 0.4);
	glVertex2f(-0.2, 0.4);
	glVertex2f(-0.2, 0.2);
	glVertex2f(-0.4, 0.2);
	glEnd();
	glBegin(GL_POLYGON); //ban 1
	glColor3f(1, 0, 0);
	glVertex2f(-0.8, 0.3);
	glVertex2f(-0.7, 0.3);
	glVertex2f(-0.7, 0.2);
	glVertex2f(-0.8, 0.2);
	glEnd();
	glBegin(GL_POLYGON); //ban 1
	glColor3f(1, 0, 0);
	glVertex2f(-0.6, 0.3);
	glVertex2f(-0.5, 0.3);
	glVertex2f(-0.5, 0.2);
	glVertex2f(-0.6, 0.2);
	glEnd();
	if (nos == 1) {
		glBegin(GL_POLYGON); //nos
		glColor3f(1, 1, 0.5);
		glVertex2f(-1.0, 0.4);
		glVertex2f(-0.8, 0.4);
		glVertex2f(-1.0, 0.2);
		glVertex2f(-0.8, 0.2);
		glEnd();
	}
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 13) exit(0);
	else if (key == 'a') sumbu_x -= 0.01;
	else if (key == 'd') sumbu_x += 0.01;
	else if (key == 'w') sumbu_y += 0.01;
	else if (key == 'x') sumbu_y -= 0.01;
	else if (key == 'n') {
		write(-0.8, -0.5, 0, GLUT_BITMAP_HELVETICA_18, "Bawa mobil sampai ujung jalan");
		glutSwapBuffers();
	}
}
void mouse(int button, int state, int x,
	int y) {
	if (button == GLUT_LEFT_BUTTON) {
		//klik kiri
		nos = 1;
		sumbu_x += 0.03;
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	userdraw();
	tampil();
	glPushMatrix();
	glTranslatef(sumbu_x, sumbu_y, 0);
	mobil();
	if(done) write(-1.4, -0.5, 0, GLUT_BITMAP_HELVETICA_18, "Sukses");
	if (done2) write(-1.4, -0.5, 0, GLUT_BITMAP_HELVETICA_18, "Gagal");
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}
void update(int value) {
	if (sumbu_x > 1.8) done = true;
	if (sumbu_y > 1.0 || sumbu_y < -1.0) done2 = true;
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}


int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 800);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("KGV2_UTS_118_Iqbal");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutTimerFunc(1000, update, 0);
	glutMainLoop();
	return EXIT_SUCCESS;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tis for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

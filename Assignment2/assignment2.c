#include <stdio.h>
#include <stdlib.h>
#include <glut.h>

/// <summary>
/// T is the value of the angle of the teapot.
/// </summary>
GLfloat T = 0;
/// <summary>
/// P is the pan angle of the camera.
/// </summary>
GLfloat P = 0;
/// <summary>
/// R is the roll angle.
/// </summary>
GLfloat R = 0;
/// <summary>
/// Y is the yaw angle.
/// </summary>
GLfloat Y = 0;
/// <summary>
/// Pi is the pitch angle.
/// </summary>
GLfloat Pi = 0;
/// <summary>
/// Zin mentions the zoom in distance.
/// </summary>
GLfloat Zin = 5;
/// <summary>
/// Zout mentions the zoom out distance.
/// </summary>
GLfloat Zout = 20;

int value;
/// <summary>
/// Zvalue is a flag variable to keep track of the variable Z
/// </summary>
int Zvalue = 0;
/// <summary>
/// Pvalue, similar to Zvalue, is a flag variable used to keep track of the variable P
/// </summary>
int Pvalue = 0;

/// <summary>
/// myInit is a user-defined function to add various initialisation functions before creating the scene
/// </summary>
void myInit() {
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 2, 20);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

/// <summary>
/// Spin function to compute the angle of rotation of the teapot
/// </summary>
void spin() {
	T += 3;
	if (T > 360)
		T = 0;
	glutPostRedisplay();
}

/// <summary>
/// Function which gives the value of Z which is used in translation of the camera 
/// </summary>
void zoomin() {
	if (Zvalue == 0)
		Zin -= 0.5;
	else
		Zin += 0;

	if (Zin < 2) {
		Zvalue = 1;
	}

	//teapot rotation angle computation
	T += 3;
	if (T > 360)
		T = 0;
	glutPostRedisplay();
}

/// <summary>
/// Zoom out is for the camera to zoom out of the scene.
/// </summary>
void zoomout() {
	if (Zvalue == 0)
		Zout -= 0.5;

	if (Zout < 3) {
		Zvalue = 1;
	}

	/*if (Zout < 20)
		Zout -= 0.5;
	else
		Zout += 0;*/

	//teapot rotation angle computation
	T += 3;
	if (T > 360)
		T = 0;
	glutPostRedisplay();
}

/// <summary>
/// Panning movement of the camera is implemented with this function
/// </summary>
void pan() {
	if (Pvalue == 0) {
		P += 0.3;
	}
	else {
		P -= 0.3;
	}

	if (P > 35) {
		Pvalue = 1;
	}
	else if (P < -35) {
		Pvalue = 0;
	}
	//teapot rotation angle computation
	T += 3;
	if (T > 360)
		T = 0;
	glutPostRedisplay();
}

/// <summary>
/// Roll function of the camera to roll the camera 360 degrees and R defines the value of rotation
/// </summary>
void roll() {
	R += 1;
	if (R == 360) {
		R += 0;
	}
	//teapot rotation angle computation
	T += 3;
	if (T > 360)
		T = 0;
	glutPostRedisplay();
}

/// <summary>
/// This user defined function computes the variables required to determine the yaw movement.
/// </summary>
void yaw() {
	Y += 1;
	if (Y == 360)
		Y = 0;
	//teapot rotation angle computation
	T += 3;
	if (T > 360)
		T = 0;
	glutPostRedisplay();
}

/// <summary>
/// Pitch function to calculate the pitch angle
/// </summary>
void pitch() {
	Pi += 5;
	if (Pi == 360) {
		Pi = 0;
	}
	//teapot rotation angle computation
	T += 3;
	if (T > 360)
		T = 0;
	glutPostRedisplay();
}

/// <summary>
/// Draw function is defined to construct the scene, whether it is 2D or 3D.
/// </summary>
void Draw() {
	//pos is the position of the light in the scene
	GLfloat pos[] = { 0, 1, 0, 1 };
	//color contains the RGBA values of the color being emitted by the light source
	GLfloat color[] = { 1, 1, 1, 1 };

	//All the required color values mentioned below
	GLfloat teapot_color[] = { 0, 0, 1, 1 };
	GLfloat ground_color[] = { 1, 1, 1, 1 };
	GLfloat pink_color[] = { 1 , 0, 1, 1 };
	GLfloat cyan_color[] = { 0, 1, 1, 1 };
	GLfloat red_color[] = { 1, 0, 0, 1 };
	GLfloat black_color[] = { 0, 0, 0, 1 };
	GLfloat green_color[] = {0, 1, 0, 1};

	//glClear clears the buffer bits
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity function loads the current matrix with an identity matrix
	glLoadIdentity();
	//glLightfv is used to define the position of the light source and the color, type of light being emitted by the light source
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, color);

	//glPush Attrib push and pop the server attribute stack
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		switch (value)
		{
			case 1:
				glTranslatef(0, 1, Zin);
				gluLookAt(1.5, 1, 5, 0, 0, 0, 0, 1, 0);
				break;
			case 2:
				glTranslatef(0, 1, Zout);
				gluLookAt(1.5, 1, 20, 0, 0, 0, 0, 1, 0);
				break;
			case 3:
				glRotatef(P, 0, 1, 0);
				gluLookAt(1.5, 1, 5, 0, 0, 0, 0, 1, 0);
				break;
			case 4:
				glRotatef(R, 0, 0, 1);
				gluLookAt(1.5, 1, 5, 0, 0, 0, 0, 1, 0);
				break;
			case 5:
				glRotatef(Y, 0, 1, 0);
				gluLookAt(1.5, 1, 5, 0, 0, 0, 0, 1, 0);
				break;
			case 6:
				glRotatef(Pi, 1, 0, 0);
				gluLookAt(1.5, 1, 5, 0, 0, 0, 0, 1, 0);
				break;
			default:
				gluLookAt(1.5, 1, 5, 0, 0, 0, 0, 1, 0);
				break;
		}
		//gluLookAt specifies the position of the camera eye, up axis and center of perception
		//gluLookAt(0, 1, 5, 0, 0, 0, 0, 1, 0);
	glPopAttrib();

	//floor
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ground_color);
		glPushMatrix();
			glTranslatef(0, -1, 0);
			glScalef(3, 0.03, 3);
			glutSolidCube(1);
		glPopMatrix();
	glPopAttrib();

	//side_wall
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, teapot_color);
		glPushMatrix();
			glTranslatef(-1.5, 0.25, 0);
			glScalef(0.03, 2.5, 3);
			glutSolidCube(1);
		glPopMatrix();
	glPopAttrib();

	//back wall
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, green_color);
		glPushMatrix();
			glTranslatef(0, 0.25, -1);
			glScalef(3, 2.5, 0.03);
			glutSolidCube(1);
		glPopMatrix();
	glPopAttrib();

	//table top
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, black_color);
		glPushMatrix();
			glTranslatef(0, -0.3, 0);
			glScalef(1, 0.05, 1);
			glutSolidCube(0.7);
		glPopMatrix();
	glPopAttrib();
	
	//next 4 are the legs of the table
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red_color);
		glPushMatrix();
			glTranslatef(-0.35f, -0.65f, -0.35f);
			glScalef(0.05f, 1, 0.05f);
			glutSolidCube(0.7f);
		glPopMatrix();
	glPopAttrib();

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cyan_color);
		glPushMatrix();
			glTranslatef(0.35, -0.65, -0.35);
			glScalef(0.05, 1, 0.05);
			glutSolidCube(0.7);
		glPopMatrix();
	glPopAttrib();

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, pink_color);
		glPushMatrix();
			glTranslatef(-0.35, -0.65, 0.35);
			glScalef(0.05, 1, 0.05);
			glutSolidCube(0.7);
		glPopMatrix();
	glPopAttrib();

	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, teapot_color);
		glPushMatrix();
			glTranslatef(0.35, -0.65, 0.35);
			glScalef(0.05, 1, 0.05);
			glutSolidCube(0.7);
		glPopMatrix();
	glPopAttrib();

	glRotatef(T, 0, 1, 0);
	//teapot
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, teapot_color);
		glPushMatrix();
			glTranslatef(0, -0.12, 0);
			glRotatef(45, 0 , 1, 0);
			glutSolidTeapot(0.2);
		glPopMatrix();
	glPopAttrib();
	

	glutSwapBuffers();
}


/// <summary>
/// Main function which has all the initialisations and calls to other functions which creates the scene.
/// </summary>
/// <param name="argc">Number of arguments passed to the program</param>
/// <param name="argv">Called as argument vector, it is a one dimensional array of strings</param>
/// <returns></returns>
int main(int argc, char** argv) {
	printf("1- Zoom in, 2- Zoom out, 3- Pan, 4- Roll, 5- Yaw, 6- Pitch, 0- Still shot: ");
	scanf_s("%d", &value);

	glutInit(&argc, argv);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("Teapot");

	myInit();
	glutDisplayFunc(Draw);
	switch (value) {
		case 1:
			glutIdleFunc(zoomin);
			break;
		case 2:
			glutIdleFunc(zoomout);
			break;
		case 3:
			glutIdleFunc(pan);
			break;
		case 4:
			glutIdleFunc(roll);
			break;
		case 5:
			glutIdleFunc(yaw);
			break;
		case 6:
			glutIdleFunc(pitch);
			break;
		default:
			glutIdleFunc(spin);
			break;
	}

	glutMainLoop();

	return 0;
}

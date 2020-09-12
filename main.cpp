#include "GL/gl.h"
#include "GL/glut.h"
#include <iostream>

#include "constants.h"
#include "helper.h"
#include "game.h"





void init(){
	glClearColor(0,0,0,1);
	initGrid(COLUMNS, ROWS);
}


int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500,500);
	glutCreateWindow("SNAKE");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutTimerFunc(0,timer_callback,0);
	glutSpecialFunc(keyboard_callback);
	init();
	glutMainLoop();
	return 0;

}




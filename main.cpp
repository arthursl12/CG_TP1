#include "GL/gl.h"
#include "GL/glut.h"
#include <iostream>
#include <memory>
#include <ctime>
#include <cstdlib>


#include "constants.h"
#include "helper.h"
#include "game.h"
#include "level.h"

Level lev;

void init(){
	glClearColor(0,0,0,1);
	// std::shared_ptr<Tile> t1 = std::make_shared<Tile>(2,2,2,4);
	// lev.objects.push_back(t1);
	// std::shared_ptr<Tile> t2 = std::make_shared<Tile>(6.5,2,2,4);
	// lev.objects.push_back(t2);
	// initGrid(COLUMNS, ROWS);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WINDOW_W,WINDOW_H);
	
	glutCreateWindow("Breakout - OpenGL");
	std::cout << glutGet(GLUT_WINDOW_WIDTH) << "," << glutGet(GLUT_WINDOW_HEIGHT) << std::endl;
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutTimerFunc(0,timer_callback,0);
	glutKeyboardFunc(keyboard_callback);
	glutMouseFunc(mouse_callback);
	glutPassiveMotionFunc(motion_callback);
	glutMotionFunc(motion_callback);
	init();
	glutMainLoop();
	return 0;

}




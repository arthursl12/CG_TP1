#include "GL/gl.h"
#include "GL/glut.h"
#include <iostream>
#include <memory>


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




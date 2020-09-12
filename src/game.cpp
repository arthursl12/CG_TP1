#include <GL/glut.h>
#include <ctime>
#include "game.h"



short sDirection = RIGHT;

void drawFood(){
	// if (food){
	// 	random(foodX,foodY);
	// }
	// food=false;
	glColor3f(1,0,0);
	glRectf(30,35,35,40);
}

#include "GL/gl.h"
#include "GL/glut.h"
#include "GL/freeglut.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "game.h"
#include "level.h"
#include "gObject.h"
#include "tile.h"
#include "helper.h"

extern Level lev;

void drawText(float x, float y, std::string text) {
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

void display_callback(){
	glClear(GL_COLOR_BUFFER_BIT);
	// drawGrid();
	// drawSnake();
	std::vector<std::shared_ptr<Tile>>::iterator it1;
	std::cout << lev.tileMap.size() << std::endl;
	for (it1 = lev.tileMap.begin(); it1 != lev.tileMap.end(); it1++) { 
		(*it1)->draw();
    }
	std::vector<std::shared_ptr<GameObject>>::iterator it;
	for (it = lev.objects.begin(); it != lev.objects.end(); it++) { 
		(*it)->draw();
    }

	drawFood();
    drawText(5,5,"HELLO");
	glutSwapBuffers();
	// if (gameOver){
	// 	std::cout << "GAME OVER " << "Your Score: " << score << std::endl;
	// 	exit(0);
	// }
	
}

void reshape_callback(int w, int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,COLUMNS,0,ROWS,-1,1);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard_callback(int key, int, int){
	switch(key){
		case GLUT_KEY_UP:
			if(sDirection != DOWN)
				sDirection = UP;
			break;
		case GLUT_KEY_DOWN:
			if(sDirection != UP)
				sDirection = DOWN;
			break;
		case GLUT_KEY_RIGHT:
			if(sDirection != LEFT)
				sDirection = RIGHT;
			break;
		case GLUT_KEY_LEFT:
			if(sDirection != RIGHT)
				sDirection = LEFT;
			break;
	}
}

void timer_callback(int){
	glutPostRedisplay();
	glutTimerFunc(1000/FPS,timer_callback,0);
}
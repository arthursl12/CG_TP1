#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

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
	lev.draw();
	lev.update();
	glutSwapBuffers();
}

void reshape_callback(int w, int h){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	float deltaW = w - WINDOW_W;
	float deltaH = h - WINDOW_H;
	glViewport(deltaW/2, deltaH/2, WINDOW_W, WINDOW_H);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,WINDOW_W,0,WINDOW_H,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, w, h);
}

void keyboard_callback(unsigned char key, int, int){
	switch(key){
		case 'q':
			exit(0);
			break;
		case 'r':{
			lev = Level(lev);
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glutPostRedisplay();
			break;
		}
		case 'p':{
			if (DBG){
				lev.debugComplete();
			}
		}
	}
}

void motion_callback(int x, int y){
	lev.setMousePos(x, y);
}

void mouse_callback(int button, int state, int x, int y){
	if (button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN){
		if (!lev.isCompleted()){
			lev.changePauseState();
		}else{
			lev = Level(lev);
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glutPostRedisplay();
		}
	}else if (button == GLUT_LEFT_BUTTON and state == GLUT_DOWN){
		lev.changeDisplayInfoState();
	}
}

void timer_callback(int){
	if (!lev.getIsPaused()){
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glutPostRedisplay();
	}

	glutTimerFunc(1000/FPS,timer_callback,0);
}
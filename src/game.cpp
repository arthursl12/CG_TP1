#include <GL/glut.h>
#include <ctime>
#include "game.h"


int gridX;
int gridY;
int snake_length = 5;
int foodX, foodY;
short sDirection = RIGHT;
int posX[60]={20,20,20,20,20}, posY[60]={20,19,18,17,16};
extern bool gameOver;
bool food=true;


void initGrid(int x, int y){
	gridX = x;
	gridY = y;
}

void drawGrid(){
	for (int x = 0; x < gridX; x++){
		for (int y = 0; y < gridY; y++){
			unit(x,y);
		}
	}
	

}

void unit(int x, int y){

	if (x == 0 || y == 0 || x == gridX-1 || y == gridY-1){
		glLineWidth(3);
		glColor3f(1,0,0);
	}else{
		glLineWidth(1);
		glColor3f(1,1,1);
	}

	glBegin(GL_LINE_LOOP);
		glVertex2f(x,y);
		glVertex2f(x+1,y);
		glVertex2f(x+1,y+1);
		glVertex2f(x,y+1);
	glEnd();
}

void drawFood(){

	if (food){
		random(foodX,foodY);
	}
	food=false;
	glColor3f(1,0,0);
	glRectf(foodX,foodY,foodX+1,foodY+1);
}

void drawSnake(){
	for (int i = snake_length-1; i > 0; i--){
		posX[i] = posX[i-1];
		posY[i] = posY[i-1];
	}
	if (sDirection == UP)
		posY[0]++;
	else if (sDirection == DOWN)
		posY[0]--;
	else if (sDirection == RIGHT)
		posX[0]++;
	else if (sDirection == LEFT)
		posX[0]--;
	for (int i = 0; i < snake_length; i++){
		if (i == 0){
			glColor3f(0,1,0);
		}else{
			glColor3f(0,0,1);
		}
		glRectd(posX[i], posY[i], posX[i]+1, posY[i]+1);
	}
	if(posX[0] == 0 || posX[0] == gridX-1 || posY[0] == 0 || posY[0] == gridY-1){
		gameOver = true;
	}
	if(posX[0] == foodX && posY[0] == foodY){
		food = true;
	}
}

void random(int &x, int &y){
	int _maxX = gridX - 2;
	int _maxY = gridY - 2;
	int _minX = 1;
	int _minY = 1;
	srand(time(NULL));
	x = _minX + rand() % (_maxX-_minX);
	y = _minY + rand() % (_maxY-_minY);
}

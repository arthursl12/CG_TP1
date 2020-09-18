#include <GL/glut.h>
#include <iostream>
#include "constants.h"
#include "speedbar.h"

SpeedBar::SpeedBar(float _x, float _y){
    this->x = _x;
    this->y = _y;
    this->height = PADDLE_HEIGHT+5;
    this->width = 3;
    this->speed = 0;
}

void SpeedBar::draw(){

    float deltaY = (height - PADDLE_HEIGHT)/2 + 1;
    float relPosX = mouseX - WINDOW_W/2;
    if (speed + relPosX > 200)
        speed = 200;
    else if (speed + relPosX < -200)
        speed = -200;
    else
        speed = speed + relPosX;
    // TODO: calcular ratio da velocidade
    glColor3f(1,1,1);
    glRectf(x, y+deltaY, x+speed, y+PADDLE_HEIGHT);

    glColor3f(1,1,0);
    glRectf(x, y, x+width, y+height);


}

void SpeedBar::setMousePos(int _x, int _y){
    this->mouseX = _x;
    this->mouseY = _y;
}
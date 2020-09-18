#include <GL/glut.h>
#include <iostream>
#include "constants.h"
#include "speedbar.h"

SpeedBar::SpeedBar(float _x, float _y){
    this->x = _x;
    this->y = _y;
    this->height = PADDLE_HEIGHT+5;
    this->width = 3;
}

void SpeedBar::draw(){
    // std::cout << this->x << ", " << this->y << std::endl;
    glColor3f(1,1,0);
    glRectf(x, y, x+width, y+height);
}
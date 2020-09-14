#include <GL/glut.h>
#include <iostream>
#include "constants.h"
#include "ball.h"

Ball::Ball(float _x, float _y){
    this->x = _x;
    this->y = _y;
    this->size = BALL_SIZE;
}

void Ball::draw(){
    // std::cout << this->x << ", " << this->y << std::endl;
    glColor3f(1,0,1);
    glRectf(x, y, x+size, y+size);
}
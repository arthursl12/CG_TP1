#include <GL/glut.h>
#include <iostream>
#include "constants.h"
#include "paddle.h"

Paddle::Paddle(float _x, float _y){
    this->x = _x;
    this->y = _y;
    this->height = PADDLE_HEIGHT;
    this->width = PADDLE_WIDTH;
    this->speed = 0;
}

void Paddle::draw(){
    // std::cout << this->x << ", " << this->y << std::endl;
    glColor3f(0.9,0.9,0.9);
    glRectf(x+speed, y, x+width, y+height);
}

void Paddle::setSpeed(float v){
    // std::cout << this->x << ", " << this->y << std::endl;
    if (v > PADDLE_MAX_SPEED){
        this->speed = PADDLE_MAX_SPEED;
    }else if (v < -PADDLE_MAX_SPEED){
        this->speed = -PADDLE_MAX_SPEED;
    }else{
        this->speed = v;
    }
}

#include <GL/glut.h>
#include <iostream>
#include "constants.h"
#include "paddle.h"

Paddle::Paddle(float _x, float _y){
    this->x = _x;
    this->y = _y;
    this->height = PADDLE_HEIGHT;
    this->width = PADDLE_WIDTH;
    this->nome = "paddle";
    this->speed = 0;
}

void Paddle::draw(){
    // std::cout << this->x << ", " << this->y << std::endl;~
    float newX = x + speed;
    if (newX <= 0){
        newX = 0;
    }else if (newX + width >= WINDOW_W){
        newX = WINDOW_W - width;
    }
    this->x = newX;
    glColor3f(0.9,0.9,0.9);
    glRectf(x, y, x+width, y+height);

    if (DBG){
        glColor3f(1,0,0);
        glRectf(x, y-5, x+2, y+10);

        glColor3f(1,0,0);
        glRectf(x-5, y, x+10, y+2);
    }

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

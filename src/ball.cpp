#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "constants.h"
#include "ball.h"

Ball::Ball(float _x, float _y){
    this->x = _x;
    this->y = _y;
    this->size = BALL_SIZE;
    this->speedX = 0;
    this->speedY = 0;
    this->firstMove = true;
}

void Ball::draw(){
    // std::cout << this->x << ", " << this->y << std::endl;
    float newX = x + speedX;
    float newY = y + speedY;

    // Checagem dos limites em X
    if (newX <= 0){
        newX = 0;
        speedX = -speedX;
    }else if (newX >= WINDOW_W){
        newX = WINDOW_W - BALL_SIZE;
        speedX = -speedX;
    }

    // Checagem dos limites em Y
    if (newY >= WINDOW_H){
        newY = WINDOW_H - BALL_SIZE;
        speedY = -speedY;
    }else if (newY < PADDLE_Y){
        // Lose a life or game over: trigger event
        std::cout << "Perde vida" << std::endl;
    }
    std::cout << "SX: " << speedX << ", SY: " << speedY << std::endl;
    x = newX;
    y = newY;
    glColor3f(1,0,1);
    glRectf(x, y, x+size, y+size);
}

void Ball::randomSpeed(){
    if (firstMove){
        firstMove = false;
        //Velocidade em X aleatória
        speedX = rand()%(BALL_MAX_X_SPEED/2)+3;
        speedX *= pow(-1, rand()%2);

        //Velocidade em Y aleatória
        speedY = rand()%(BALL_MAX_Y_SPEED/2)+4;
    }
}
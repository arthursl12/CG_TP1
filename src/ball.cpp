#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "constants.h"
#include "ball.h"

Ball::Ball(float _x, float _y){
    this->x = _x;
    this->y = _y;
    this->height = size;
    this->width = size;
    this->nome = "ball";

    this->size = BALL_SIZE;
    this->speedX = 0;
    this->speedY = 0;
    this->firstMove = true;
}

void Ball::draw(){
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
        // std::cout << "Perde vida" << std::endl;
    }

    x = newX;
    y = newY;
    glColor3f(1,0,1);
    glRectf(x, y, x+size, y+size);

    if (DBG){
        glColor3f(1,0,0);
        glRectf(x, y-5, x+2, y+10);

        glColor3f(1,0,0);
        glRectf(x-5, y, x+10, y+2);
    }

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

void Ball::handleCollision(GameObject& obj){
    // Já sabemos que houve colisão
    // Temos que descobrir em que lado a bola colidiu

}
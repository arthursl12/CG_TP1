#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "constants.h"
#include "ball.h"

Ball::Ball(float _x, float _y){
    this->x = _x;
    this->y = _y;
    this->height = BALL_SIZE;
    this->width = BALL_SIZE;
    this->nome = "ball";

    this->size = BALL_SIZE;
    this->speedX = 0;
    this->speedY = 0;
    this->firstMove = true;
    this->outOfBounds = false;
}

bool Ball::isOutOfBounds(){
    return this->outOfBounds;
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
        outOfBounds = true;
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
        speedX = std::rand()%(BALL_MAX_X_SPEED/2)+3;
        speedX *= pow(-1, rand()%2);

        //Velocidade em Y aleatória
        speedY = std::rand()%(BALL_MAX_Y_SPEED/2)+4;
    }
}

void Ball::handleCollision(GameObject& obj){
    if (obj.nome == "paddle"){
        Paddle& paddle = dynamic_cast<Paddle&>(obj);  

        speedY = -speedY;
        y = paddle.y + paddle.height + 1;     //Offset para evitar colisão infinita
        // Se colidirmos no lado esquerdo enquanto indo para esquerda
        if (x < paddle.x + (paddle.width / 2) && paddle.speed < 0 && !paddle.isStuck()){
            float ratio = (paddle.x + paddle.width / 2 - x)/BALL_MAX_X_SPEED;
            float newspeedX = -(BALL_MAX_X_SPEED/2) + -(ratio);
            if (newspeedX > BALL_MAX_X_SPEED){
                speedX = BALL_MAX_X_SPEED;
            }else{
                speedX = newspeedX;
            }
        }

        // Se colidirmos no lado direito enquanto indo para a direita
        else if (x > paddle.x + (paddle.width / 2) && paddle.speed > 0 && !paddle.isStuck()){
            float ratio = abs((paddle.x + paddle.width / 2 - x)/BALL_MAX_X_SPEED);
            float newspeedX = (BALL_MAX_X_SPEED/2) + (ratio);
            if (newspeedX > BALL_MAX_X_SPEED){
                speedX = BALL_MAX_X_SPEED;
            }else{
                speedX = newspeedX;
            }
        }
    }else if (obj.nome == "tile"){
        Tile& tile = dynamic_cast<Tile&>(obj);
       
        if (DBG){
            std::cout << "x,y: " << x << ", " << y << std::endl;
            std::cout << "xy+: " << x+width << ", " << y+height << std::endl;
            std::cout << "til: " << tile.x << ", " << tile.y << std::endl;
            std::cout << "ti+: " << tile.x+tile.width << ", " << tile.y+tile.height << std::endl;
        }

        // Lado Esquerdo; verifica se estamos indo para direita
        if (x + width - 5 <= tile.x && (y > tile.y - height || y < tile.y + tile.height)  && speedX > 0){
            // Inverte velocidadeX e reposiciona bola fora do tile
            speedX = -speedX;
            x = tile.x - width - 1;
        }
        // lado Direito: verifica se estamos indo para esquerda
        else if(x + 5 >= tile.x + tile.width && (y < tile.y - height || y < tile.y + tile.height) && speedX < 0){
            speedX = -speedX;
            x = tile.x + tile.width + 1;
        }
        // Acima
        else if(y + 6 > tile.y + tile.height){
            speedY = -speedY;
            y = tile.y + tile.height + 1;

        }
        // Abaixo, última possibilidade
        else{
            speedY = -speedY;
            y = tile.y - height - 1;
        }

        if (abs(speedY) < BALL_MAX_Y_SPEED){
            speedY = speedY * 1.01;
        }
    }

        

}
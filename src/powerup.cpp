#include <GL/glut.h>
#include "powerup.h"

PowerUp::PowerUp(float _x, float _y){
    this->width = POWERUP_SIZE;
    this->height = POWERUP_SIZE;
    this->x = _x;
    this->y = _y;
    this->dx = (std::rand()%2 + 1 == 1) ? 0.1 : -0.1;
    this->dy = -0.1;
    this->inPlay = false;
}

void PowerUp::update(){
    if (inPlay){
        x += dx;
        y += dy;

        int rand = std::rand()%2;
        if (rand != 0){ 
            int rand2 = std::rand()%10 + 1;
            std::cout << "rand2: " << rand2 << std::endl;
            if (rand2 >= 6 && abs(dy) < POWERUP_MAX_DY){
                dy *= (1 + POWERUP_ACC*rand);
            }else if (rand2 >=4 && abs(dx) < POWERUP_MAX_DX){
                dx *= (1 + POWERUP_ACC*rand);
            }
        }

        // Ricochetear nas paredes
        if (x <= 0){
            x = 0;
            dx = -dx;
        }
        if (x >= WINDOW_W - width) {
            x = WINDOW_W - width;
            dx = dx;
        }
        if (y >= WINDOW_H - height){
            y = WINDOW_H - height;
            dy = -dy;
        }

        // Se cair, despawna
        if (y < 0){
            this->reset();
        }
    }
}

bool PowerUp::isInPlay(){
    return this->inPlay;
}

void PowerUp::spawnAt(float _x, float _y){
    this->x = _x;
    this->y = _y;
    this->dx = (std::rand()%2 + 1 == 1) ? 0.1 : -0.1;
    this->dy = -0.1;
    this->inPlay = true;
}

void PowerUp::reset(){
    this->x = -200;
    this->y = -200;
    this->dx = 0;
    this->dy = 0;
    this->inPlay = false;
}

void VidaPowerUp::draw(){
    glColor3f(1,0.5,1);
    glRectf(x, y, x+width, y+height);
}

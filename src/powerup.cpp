#include <GL/glut.h>
#include "powerup.h"

PowerUp::PowerUp(float _x, float _y){
    this->width = POWERUP_SIZE;
    this->height = POWERUP_SIZE;
    this->x = _x;
    this->y = _y;
    this->dx = (std::rand()%2 + 1 == 1) ? 0.3 : -0.3;
    this->dy = -0.3;
    this->inPlay = false;
}

void PowerUp::update(){
    if (inPlay){
        x += dx;
        y += dy;

        int rand = std::rand()%2;
        if (rand != 0){ 
            int rand2 = std::rand()%10 + 1;
            if (rand2 >= 6 && abs(dy) < POWERUP_MAX_DY){
                dy *= (1 + POWERUP_ACC*rand);
            }else if (rand2 >=4 && abs(dx) < POWERUP_MAX_DX){
                dx *= (1 + POWERUP_ACC*rand);
            }
        }

        // Ricochetear nas paredes
        if (x <= 0){
            x = 1;
            dx = -dx;
        }
        if (x >= WINDOW_W - width) {
            x = WINDOW_W - width - 1;
            dx = -dx;
        }
        if (y >= WINDOW_H - height){
            y = WINDOW_H - height - 1;
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
    this->dx = (std::rand()%2 + 1 == 1) ? 0.3 : -0.3;
    this->dy = -0.3;
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

    glColor3f(1,0,0);
    float oX = x + width/2;
    float oY = y + 5;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(oX, oY);
        glVertex2f(oX + 10, oY + 10);
        glVertex2f(oX + 10, oY + 16);
        glVertex2f(oX +  7, oY + 20);
        glVertex2f(oX     , oY + 14);
        glVertex2f(oX -  7, oY + 20);
        glVertex2f(oX - 10, oY + 16);
        glVertex2f(oX - 10, oY + 10);
    glEnd();
}

void PaddleMaiorPowerUp::draw(){
    glColor3f(0,0.8,0.9);
    glRectf(x, y, x+width, y+height);

    float oX = x + width/2;
    float oY = y + 5;
    glColor3f(1,1,1);
    glRectf(oX - 10, oY +  4, oX +  4, oY +  8);

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(oX - 10, oY +  4);
        glVertex2f(oX +  4, oY +  4);
        glVertex2f(oX +  4, oY +  8);
        glVertex2f(oX - 10, oY +  8);
    glEnd();
    
    glColor3f(0,0.5,0);
    glRectf(oX + 04, oY + 07, oX + 06,  oY + 17);
    
    glColor3f(0,0.5,0);
    glRectf(oX, oY + 11, oX + 10,  oY + 13);
}

void PaddleMenorPowerUp::draw(){
    glColor3f(0,0.8,0.9);
    glRectf(x, y, x+width, y+height);

    float oX = x + width/2;
    float oY = y + 5;
    glColor3f(1,1,1);
    glRectf(oX - 10, oY +  4, oX +  4, oY +  8);
    
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(oX - 10, oY +  4);
        glVertex2f(oX +  4, oY +  4);
        glVertex2f(oX +  4, oY +  8);
        glVertex2f(oX - 10, oY +  8);
    glEnd();
    
    glColor3f(0.9,0,0);
    glRectf(oX, oY + 11, oX + 10,  oY + 13);
}

void DuasPowerUp::draw(){
    glColor3f(0,0.8,0.9);
    glRectf(x, y, x+width, y+height);

    float oX = x + width/2;
    float oY = y + 5;
    glColor3f(1,1,1);
    glRectf(oX - 8, oY +  2, oX +  2, oY +  12);

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(oX - 8, oY +  2);
        glVertex2f(oX + 2, oY +  2);
        glVertex2f(oX + 2, oY + 12);
        glVertex2f(oX - 8, oY + 12);
    glEnd();

    glColor3f(1,1,1);
    glRectf(oX - 2, oY +  8, oX +  8, oY +  18);

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(oX - 2, oY +  8);
        glVertex2f(oX + 8, oY +  8);
        glVertex2f(oX + 8, oY + 18);
        glVertex2f(oX - 2, oY + 18);
    glEnd();
}


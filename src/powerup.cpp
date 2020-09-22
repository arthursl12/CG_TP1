#include <GL/glut.h>
#include "powerup.h"

PowerUp::PowerUp(float _x, float _y){
    this->width = POWERUP_SIZE;
    this->height = POWERUP_SIZE;
    this->x = _x;
    this->y = _y;
    this->inPlay = false;
}

void VidaPowerUp::draw(){
    glColor3f(1,0.5,1);
    glRectf(x, y, x+width, y+height);
}

#include <GL/glut.h>
#include <iostream>
#include "constants.h"
#include "speedbar.h"

SpeedBar::SpeedBar(float _x, float _y){
    this->x = _x;
    this->y = _y;
    this->markHeight = PADDLE_HEIGHT+5;
    this->markWidth = 3;
    this->barHeight = PADDLE_HEIGHT;
    this->barWidth = 0;
    this->speed = 0;
}

void SpeedBar::draw(){
    float deltaY = (markHeight - PADDLE_HEIGHT)/2 + 1;
    // std::cout << "Speed: " << speed << ", W: " << barWidth << std::endl;
    glColor3f(1,1,1);
    glRectf(x, y+deltaY, x+barWidth, y+PADDLE_HEIGHT);

    glColor3f(1,1,0);
    glRectf(x, y, x+markWidth, y+markHeight);
    glColor3f(1,1,0);
    float xMarkInicio = x - MAX_WIDTH_SPEED_BAR;
    glRectf(xMarkInicio, y, xMarkInicio+markWidth, y+markHeight);
    glColor3f(1,1,0);
    float xMarkFim = x + MAX_WIDTH_SPEED_BAR;
    glRectf(xMarkFim, y, xMarkFim+markWidth, y+markHeight);


}

void SpeedBar::setSpeed(float v){
    
    float meio = WINDOW_W/2;
    float newWidth = (v/PADDLE_MAX_SPEED) * MAX_WIDTH_SPEED_BAR;
    if (newWidth <= MAX_WIDTH_SPEED_BAR && newWidth >= -MAX_WIDTH_SPEED_BAR){
        this->speed = v;
        this->barWidth = newWidth;
    }else if (newWidth > MAX_WIDTH_SPEED_BAR){
        this->speed = PADDLE_MAX_SPEED;
        this->barWidth = MAX_WIDTH_SPEED_BAR;
    }else if (newWidth < -MAX_WIDTH_SPEED_BAR){
        this->speed = -PADDLE_MAX_SPEED;
        this->barWidth = -MAX_WIDTH_SPEED_BAR;
    }
    
}
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include "texto.h"

Texto::Texto(float _x, float _y, std::string _str){
    this->x = _x;
    this->y = _y;
    this->str = _str;
}

void Texto::draw(){
    // std::cout << this->x << ", " << this->y << std::endl;
    glColor3f(1,1,1);
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)str.c_str());
}

void Texto::updateString(std::string _str){
    this->str = _str;
}
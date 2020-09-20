#include <GL/glut.h>
#include <iostream>
#include "tile.h"
#include "constants.h"

Tile::Tile(float _x, float _y, float _height, float _width){
    this->x = _x;
    this->y = _y;
    this->height = _height;
    this->width = _width;
    this->nome = "tile";
}

void Tile::draw(){
    // std::cout << this->x << ", " << this->y << std::endl;
    glColor3f(1,1,0);
    glRectf(x, y, x+width, y+height);

    if (DBG){
        glColor3f(1,0,0);
        glRectf(x, y-5, x+2, y+10);

        glColor3f(1,0,0);
        glRectf(x-5, y, x+10, y+2);
    }
}

bool Tile::operator== (Tile &outro){
    if (this->x != outro.x)
        return false;
    if (this->y != outro.y)
        return false;
    return true; 
}
#include <GL/glut.h>
#include "tile.h"

Tile::Tile(float _x, float _y, float _height, float _width){
    this->x = _x;
    this->y = _y;
    this->height = _height;
    this->width = _width;
}

void Tile::draw(){
    glColor3f(1,1,0);
    glRectf(x, y, x+width, y+height);
}
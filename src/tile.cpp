#include <GL/glut.h>
#include <iostream>
#include <tuple>
#include "tile.h"
#include "constants.h"

Tile::Tile(float _x, float _y, float _height, float _width, Cores cor){
    criaPaleta();
    this->x = _x;
    this->y = _y;
    this->height = _height;
    this->width = _width;
    this->nome = "tile";
    this->corRGB = paleta[cor];
}

void Tile::draw(){
    // std::cout << this->x << ", " << this->y << std::endl;
    glColor3f(std::get<0>(corRGB),std::get<1>(corRGB),std::get<2>(corRGB));
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

void Tile::criaPaleta(){
    paleta[Vermelho] = std::make_tuple(1,0,0);
    paleta[Laranja] = std::make_tuple(0.9,0.5,0.11);
    paleta[Amarelo] = std::make_tuple(1,1,0);
    paleta[Verde] = std::make_tuple(0.5,0.8,0);
    paleta[Azul] = std::make_tuple(0,0,1);
    paleta[Violeta] = std::make_tuple(0.4,0,0.7);
    paleta[Special] = std::make_tuple(0.9,0.3,0.9);
}
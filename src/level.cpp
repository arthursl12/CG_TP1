#include <iostream>
#include <GL/glut.h>
#include "level.h"
#include "paddle.h"
#include "ball.h"
#include "texto.h"
#include "speedbar.h"

void Level::createObjects(){
    // Cria o conjunto de tiles
    float TILE_WIDTH = (WINDOW_W - (T_COL*TILE_H_SPACE))/T_COL;
    float TILE_HEIGHT = TILE_WIDTH/2;
    float MAP_X = TILE_H_SPACE - 4;
    // std::cout << TILE_WIDTH << std::endl;
    float curX = MAP_X;
    float curY = WINDOW_H - MAP_OFFSET;
    for (int i = 0; i < T_ROW; i++){
        for (int j = 0; j < T_COL; j++){
            std::shared_ptr<Tile> t = \
                std::make_shared<Tile>(curX, curY,TILE_HEIGHT,TILE_WIDTH);
            this->tileMap.push_back(t);
            curX += TILE_H_SPACE;
            curX += TILE_WIDTH;
        }
        curY += TILE_HEIGHT+TILE_V_SPACE;
        curX = MAP_X;
    }

    // Cria o paddle
    std::shared_ptr<Paddle> pad = \
                std::make_shared<Paddle>(WINDOW_W/2 - PADDLE_WIDTH/2, 55);
    this->objects.push_back(pad);

    // Cria a bola
    std::shared_ptr<Ball> ball = \
                std::make_shared<Ball>(WINDOW_W/2 - BALL_SIZE/2, WINDOW_W/4+40);
    this->objects.push_back(ball);
}

void Level::createTextos(){
    // Cria placar
    std::string plStr = "Placar: ";
    int l1 = plStr.size();
    std::shared_ptr<Texto> placarLabel = \
                std::make_shared<Texto>(WINDOW_W/6, WINDOW_H-50, plStr);
    this->textos.push_back(placarLabel);
    std::shared_ptr<Texto> placar = \
                std::make_shared<Texto>(WINDOW_W/6 + l1*10, WINDOW_H-50, "100");
    this->textos.push_back(placar);

    // Cria conta-vidas
    std::string vdStr = "Vidas: ";
    int l2 = vdStr.size();
    std::shared_ptr<Texto> vidasLabel = \
                std::make_shared<Texto>(3*WINDOW_W/4, WINDOW_H-50, vdStr);
    this->textos.push_back(vidasLabel);
    std::shared_ptr<Texto> vidas = \
                std::make_shared<Texto>(3*WINDOW_W/4 + l2*10, WINDOW_H-50, "3");
    this->textos.push_back(vidas);
}

Level::Level(){
    this->createObjects();
    this->createTextos();
    // Cria a barra de velocidade
    this->speedbar = \
                std::make_shared<SpeedBar>(WINDOW_W/2, 12.5);
    this->objects.push_back(this->speedbar);
}

void Level::setMousePos(int _x, int _y){
    this->mouseX = _x;
    this->mouseY = _y;
    this->speedbar->setMousePos(_x, _y);
}
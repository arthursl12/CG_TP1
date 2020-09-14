#include <iostream>
#include <GL/glut.h>
#include "level.h"
#include "paddle.h"

Level::Level(){
    // Carrega o conjunto de tiles
    float TILE_WIDTH = (WINDOW_W - (T_COL*TILE_H_SPACE))/T_COL;
    float TILE_HEIGHT = TILE_WIDTH/2;
    float MAP_X = TILE_H_SPACE - 4;
    // std::cout << TILE_WIDTH << std::endl;
    float curX = MAP_X;
    float curY = MAP_Y;
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

    // Carrega o paddle
    std::shared_ptr<Paddle> pad = \
                std::make_shared<Paddle>(WINDOW_W/2 - PADDLE_WIDTH/2, 15);
    this->objects.push_back(pad);
}
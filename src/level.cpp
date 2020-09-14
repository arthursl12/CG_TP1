#include "level.h"
#include <iostream>
#include <GL/glut.h>

Level::Level(){
    float TILE_WIDTH = (WINDOW_W - (T_COL*TILE_H_SPACE))/T_COL;
    float TILE_HEIGHT = TILE_WIDTH/2;
    float MAP_X = TILE_H_SPACE - 3;
    std::cout << TILE_WIDTH << std::endl;
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
}
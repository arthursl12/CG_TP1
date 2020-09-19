#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <memory>
#include "tile.h"
#include "constants.h"
#include "paddle.h"
#include "speedbar.h"



class Level{
    public:
        std::vector<std::shared_ptr<Tile>> tileMap;
        std::vector<std::shared_ptr<GameObject>> objects;
        std::vector<std::shared_ptr<GameObject>> textos;

        Level();
        void setMousePos(int _x, int _y);
        bool getIsPaused();
        void changePauseState();
    private:
        int mouseX;
        int mouseY;
        bool isPaused;
        std::shared_ptr<SpeedBar> speedbar;
        std::shared_ptr<Paddle> paddle;

        void createObjects();
        void createTextos();
    
};

#endif /* LEVEL_H */
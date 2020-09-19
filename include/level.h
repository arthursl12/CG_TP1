#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <memory>
#include "tile.h"
#include "constants.h"
#include "paddle.h"
#include "ball.h"
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
        void ballCollides(GameObject& obj);
    private:
        int mouseX;
        int mouseY;
        bool isPaused;
        bool gameStarted;
        std::shared_ptr<SpeedBar> speedbar;
        std::shared_ptr<Paddle> paddle;
        std::shared_ptr<Ball> ball;

        void createObjects();
        void createTextos();
    
};

#endif /* LEVEL_H */
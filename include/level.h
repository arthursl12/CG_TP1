#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <memory>
#include <map>
#include "tile.h"
#include "constants.h"
#include "paddle.h"
#include "ball.h"
#include "speedbar.h"
#include "placar.h"
#include "vidas.h"


class Level{
    public:
        Level();
        void draw();
        void update();

        void setMousePos(int _x, int _y);
        bool getIsPaused();
        void changePauseState();
        bool ballCollides(GameObject& obj);
        void changeDisplayInfoState();
    private:
        int mouseX;
        int mouseY;
        bool isPaused;
        bool gameStarted;
        bool displayInfo;
        bool displayInfoPause;
        bool gameOver;
        bool levelComplete;
        int score;



        std::shared_ptr<SpeedBar> speedbar;
        std::shared_ptr<Paddle> paddle;
        std::shared_ptr<Ball> ball;
        std::shared_ptr<Placar> placar;
        std::shared_ptr<Vidas> vidas;
        std::vector<std::shared_ptr<Tile>> tileMap;
        std::vector<std::shared_ptr<GameObject>> objects;
        std::map<std::string, std::shared_ptr<TextoLabel>> textos;

        void createObjects();
        void createTextos();
        void createTiles();
        void removeTile(GameObject& tile);
};

#endif /* LEVEL_H */
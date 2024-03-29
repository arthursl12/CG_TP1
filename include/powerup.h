#ifndef POWERUP_H
#define POWERUP_H

#include "gObject.h"
#include "constants.h"
#include <map>
#include <iostream>

enum Efeito {Vida, PaddleMaior, PaddleMenor, Duas, Chave};

class PowerUp : public GameObject{
    friend class Level;
    public:
        PowerUp(float _x, float _y);
        void draw() = 0;
        void update();
        void spawnAt(float _x, float _y);
        bool isInPlay();
        void reset();
        
    private:
        bool inPlay;
        float dx;
        float dy;
};

class VidaPowerUp : public PowerUp {
    public:
        VidaPowerUp(float _x, float _y) : PowerUp(_x, _y) {
            this->nome = "PUvida";
        };
        void draw();
    private:
};

class PaddleMaiorPowerUp : public PowerUp {
    public:
        PaddleMaiorPowerUp(float _x, float _y) : PowerUp(_x, _y) {
            this->nome = "PUmaior";
        };
        void draw();
    private:
};

class PaddleMenorPowerUp : public PowerUp {
    public:
        PaddleMenorPowerUp(float _x, float _y) : PowerUp(_x, _y) {
            this->nome = "PUmenor";
        };
        void draw();
    private:
};

class DuasPowerUp : public PowerUp {
    public:
        DuasPowerUp(float _x, float _y) : PowerUp(_x, _y) {
            this->nome = "PUduas";
        };
        void draw();
    private:
};


#endif
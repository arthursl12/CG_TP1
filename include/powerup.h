#ifndef POWERUP_H
#define POWERUP_H

#include "gObject.h"
#include "constants.h"
#include <map>
#include <iostream>

enum Efeito {Vida, PaddleMaior, PaddleMenor, Duas, Chave};

class PowerUp : public GameObject{
    public:
        PowerUp(float _x, float _y);
        void draw() = 0;
    private:
        bool inPlay;

};

class VidaPowerUp : public PowerUp {
    public:
        VidaPowerUp(float _x, float _y) : PowerUp(_x, _y) {};
        void draw();
    private:
};

class TripleStrategy {
   static double especific(double data) {
      return 3 * data;
   }
};

#endif
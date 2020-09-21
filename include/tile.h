#ifndef TILE_H
#define TILE_H

#include "gObject.h"
#include "constants.h"
#include <memory>
#include <map>

class Tile: public GameObject{
    public:
        Tile(float _x, float _y, float _height, float _width, Cores cor);
        void draw();
        bool operator== (Tile &outro);
    private:
        std::tuple<float,float,float> corRGB;
        std::map<Cores, std::tuple<float,float,float>> paleta;
        void criaPaleta();
};

#endif /* TILE_H */
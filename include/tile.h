#ifndef TILE_H
#define TILE_H

#include "gObject.h"

class Tile: public GameObject{
    public:
        Tile(float _x, float _y, float _height, float _width);
        void draw();
    private:
        float height;
        float width;
};

#endif /* TILE_H */
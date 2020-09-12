#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "tile.h"

class Level{
    public:
        std::vector<Tile> tileMap;
        std::vector<GameObject*> objects;
};

#endif /* LEVEL_H */
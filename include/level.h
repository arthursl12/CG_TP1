#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <memory>
#include "tile.h"

class Level{
    public:
        std::vector<Tile> tileMap;
        std::vector<std::shared_ptr<GameObject>> objects;
};

#endif /* LEVEL_H */
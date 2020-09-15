#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <memory>
#include "tile.h"
#include "constants.h"



class Level{
    public:
        std::vector<std::shared_ptr<Tile>> tileMap;
        std::vector<std::shared_ptr<GameObject>> objects;
        std::vector<std::shared_ptr<GameObject>> textos;

        Level();
};

#endif /* LEVEL_H */
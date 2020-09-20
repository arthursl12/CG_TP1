#ifndef PLACAR_H
#define PLACAR_H

#include "gObject.h"
#include "texto.h"

class Placar : public GameObject{
    public:
        Placar();
        void addScore(int _score);
        void draw();
    private:
        int score;
        std::string labelStr;
        std::shared_ptr<Texto> label;
        std::shared_ptr<Texto> textScore;
};

#endif
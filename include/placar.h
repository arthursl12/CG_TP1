#ifndef PLACAR_H
#define PLACAR_H

#include "gObject.h"
#include "textolabel.h"

class Placar : public GameObject{
    public:
        Placar(int _score);
        void addScore(int _score);
        void draw();
        int getPlacar();
    private:
        int score;
        std::shared_ptr<TextoLabel> display;
};

#endif
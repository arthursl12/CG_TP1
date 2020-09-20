#ifndef PLACAR_H
#define PLACAR_H

#include "gObject.h"
#include "textolabel.h"

class Placar : public GameObject{
    public:
        Placar();
        void addScore(int _score);
        void draw();
    private:
        int score;
        std::shared_ptr<TextoLabel> display;
};

#endif
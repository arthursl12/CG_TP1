#ifndef VIDAS_H
#define VIDAS_H

#include "gObject.h"
#include "textolabel.h"
#include <memory>

class Vidas : public GameObject{
    public:
        Vidas();
        void addVida(int qtd);
        void draw();
        bool isLastVida();
    private:
        int vidas;
        bool lastLife;
        std::shared_ptr<TextoLabel> display;
};

#endif
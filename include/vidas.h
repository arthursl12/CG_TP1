#ifndef VIDAS_H
#define VIDAS_H

#include "gObject.h"
#include "textolabel.h"
#include <memory>

class Vidas : public GameObject{
    public:
        Vidas(int _vidas);
        void addVida(int qtd);
        void draw();
        bool isLastVida();
        int getVidas();
    private:
        int vidas;
        bool lastLife;
        std::shared_ptr<TextoLabel> display;
};

#endif
#ifndef VIDAS_H
#define VIDAS_H

#include "gObject.h"
#include "texto.h"
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
        std::string labelStr;
        std::shared_ptr<Texto> label;
        std::shared_ptr<Texto> textScore;
};

#endif
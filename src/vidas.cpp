#include <memory>
#include "vidas.h"
#include "constants.h"

Vidas::Vidas(){
    this->labelStr = "Vidas: ";
    this->vidas = 3;
    this->lastLife = false;
    int l1 = labelStr.size();
    this->label = std::make_shared<Texto>(3*WINDOW_W/4, WINDOW_H-50, labelStr);
    this->textScore = std::make_shared<Texto>(3*WINDOW_W/4 + l1*10, WINDOW_H-50, \
                                              std::to_string(vidas));
}

void Vidas::addVida(int qtd){
    int l1 = labelStr.size();
    this->vidas += qtd;
    this->textScore = std::make_shared<Texto>(3*WINDOW_W/4 + l1*10, WINDOW_H-50, \
                                              std::to_string(vidas));
    if (vidas == 1){
        lastLife = true;
    }
}

void Vidas::draw(){
    textScore->draw();
    label->draw();
}

bool Vidas::isLastVida(){
    return this->lastLife;
}
#include <memory>
#include "vidas.h"
#include "constants.h"

Vidas::Vidas(){
    this->vidas = 3;
    this->lastLife = false;
    this->display = std::make_shared<TextoLabel>\
                (3*WINDOW_W/4, WINDOW_H-50, "Vidas", std::to_string(vidas));
}

void Vidas::addVida(int qtd){
    this->vidas += qtd;
    this->display->updateText(std::to_string(vidas));
    if (vidas == 1){
        lastLife = true;
    }
}

void Vidas::draw(){
    display->draw();
}

bool Vidas::isLastVida(){
    return this->lastLife;
}
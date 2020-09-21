#include <memory>
#include "placar.h"
#include "constants.h"

Placar::Placar(int _score = 0){
    this->score = _score;
    this->display = std::make_shared<TextoLabel> \
            (WINDOW_W/6, WINDOW_H-50, "Placar", std::to_string(score));
}

void Placar::addScore(int _score){
    score += _score;
    display->updateText(std::to_string(score));
}

void Placar::draw(){
    display->draw();
}

int Placar::getPlacar(){
    return this->score;
}
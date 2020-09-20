#include <memory>
#include "placar.h"
#include "constants.h"

Placar::Placar(){
    this->labelStr = "Placar: ";
    this->score = 0;
    int l1 = labelStr.size();
    this->label = std::make_shared<Texto>(WINDOW_W/6, WINDOW_H-50, labelStr);
    this->textScore = std::make_shared<Texto>(WINDOW_W/6 + l1*10, WINDOW_H-50, \
                                              std::to_string(score));
}

void Placar::addScore(int _score){
    int l1 = labelStr.size();
    this->score += _score;
    this->textScore = std::make_shared<Texto>(WINDOW_W/6 + l1*10, WINDOW_H-50, \
                                              std::to_string(score));
}

void Placar::draw(){
    textScore->draw();
    label->draw();
}
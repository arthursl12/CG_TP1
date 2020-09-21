#include "gObject.h"
#include <iostream>

bool GameObject::collides(GameObject& obj){
    // Colisão AABB simples
    // Checa a não-colisão, é mais fácil: são menos casos

    // Checa se os intervalos de x não se interceptam
    if (x > obj.x + obj.width || obj.x > x + width){
        return false;
    }

    // Checa se os intervalos de y não se interceptam
    if (y > obj.y + obj.height || obj.y > y + height){
        return false;
    }

    // Se as condições acima não valem, então eles estão colidindo
    return true;
}

std::string GameObject::getNome(){
    return this->nome;
}
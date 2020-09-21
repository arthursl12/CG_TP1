#include "gObject.h"
#include <iostream>

bool GameObject::collides(GameObject& obj){
    // Colisão AABB simples
    // Checa a não-colisão, é mais fácil: são menos casos
    // if (obj.nome == "tile"){
    //     std::cout << "Tile: " << obj.x << ", " << obj.y;
    // }
    // Checa se os intervalos de x não se interceptam
    if (x > obj.x + obj.width || obj.x > x + width){
        // if (obj.nome == "tile"){
        //      std::cout << "C1" << "x: " << x << "; obj.x: " << obj.x << "; obj.w: " << obj.width << std::endl;
        // }
        return false;
    }

    // Checa se os intervalos de y não se interceptam
    if (y > obj.y + obj.height || obj.y > y + height){
        // if (obj.nome == "tile"){
        //     std::cout << "C2" << std::endl;
        // }
        return false;
    }

    // Se as condições acima não valem, então eles estão colidindo
    std::cout << "Col: " << this->nome << " e " << obj.nome << std::endl;
    return true;
}

std::string GameObject::getNome(){
    return this->nome;
}
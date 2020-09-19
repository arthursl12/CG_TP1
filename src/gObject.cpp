#include "gObject.h"
#include <iostream>

bool GameObject::collides(GameObject& obj){
    // Colisão AABB simples
    // Checa a não-colisão, é mais fácil: são menos casos

    if (obj.nome == "ball")
        return false;
    
    // Checa se os intervalos de x não se interceptam
    if (x > obj.x + obj.width || obj.x > x + width)
        // std::cout << "Colide1" << "Obj: " << std::endl;
        return false;

    // Checa se os intervalos de y não se interceptam
    if (y > obj.y + obj.height || obj.y > y + height)
        // std::cout << "Colide2" << "Obj: " << std::endl;
        return false;

    // Se as condições acima não valem, então eles estão colidindo
    std::cout << "Colide4" << "Obj: " << obj.nome << std::endl;
    return true;
}
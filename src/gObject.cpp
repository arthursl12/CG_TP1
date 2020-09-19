#include "gObject.h"

bool GameObject::collides(GameObject& obj){
    // Colisão AABB simples
    if (
        x >= obj.x &&
        x < obj.x + obj.width &&
        y >= obj.y &&
        y <= obj.y + obj.height
    )
        return true;
    else
        return false;
}
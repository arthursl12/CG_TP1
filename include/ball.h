#ifndef BALL_H
#define BALL_H

#include "gObject.h"
#include "paddle.h"
#include "tile.h"
#include <bits/stdc++.h> 

class Ball: public GameObject{
    public:
        Ball(float _x, float _y);
        void draw();
        void randomSpeed();
        void handleCollision(GameObject& obj);
    private:
        float size;
        float speedX;
        float speedY;
        bool firstMove;
};


#endif /* BALL_H */

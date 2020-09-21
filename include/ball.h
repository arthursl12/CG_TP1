#ifndef BALL_H
#define BALL_H

#include "gObject.h"
#include "paddle.h"
#include "tile.h"
#include <bits/stdc++.h> 

class Ball: public GameObject{
    friend class Level;
    public:
        Ball(float _x, float _y);
        void draw();
        void randomSpeed();
        void handleCollision(GameObject& obj);
        bool isOutOfBounds();
    protected:
        float size;
        float speedX;
        float speedY;
        bool firstMove;
        bool outOfBounds;
};


#endif /* BALL_H */

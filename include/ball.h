#ifndef BALL_H
#define BALL_H

#include "gObject.h"

class Ball: public GameObject{
    public:
        Ball(float _x, float _y);
        void draw();
        void randomSpeed();
    private:
        float size;
        float speedX;
        float speedY;
        bool firstMove;
};


#endif /* BALL_H */

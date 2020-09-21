#ifndef PADDLE_H
#define PADDLE_H

#include "gObject.h"

class Paddle: public GameObject{
    friend class Level;
    friend class Ball; 
    public:
        Paddle(float _x, float _y);
        void draw();
        void setSpeed(float v);
    private:
        float speed;
};


#endif /* PADDLE_H */

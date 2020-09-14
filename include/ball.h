#ifndef BALL_H
#define BALL_H

#include "gObject.h"

class Ball: public GameObject{
    public:
        Ball(float _x, float _y);
        void draw();
    private:
        float size;
};


#endif /* BALL_H */

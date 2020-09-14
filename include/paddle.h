#ifndef PADDLE_H
#define PADDLE_H

#include "gObject.h"

class Paddle: public GameObject{
    public:
        Paddle(float _x, float _y);
        void draw();
    private:
        float height;
        float width;
};


#endif /* PADDLE_H */

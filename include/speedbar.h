#ifndef SPEEDBAR_H
#define SPEEDBAR_H

#include "gObject.h"

class SpeedBar: public GameObject{
    public:
        SpeedBar(float _x, float _y);
        void draw();
    private:
        float height;
        float width;


};


#endif /* SPEEDBAR */

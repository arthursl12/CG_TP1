#ifndef SPEEDBAR_H
#define SPEEDBAR_H

#include "gObject.h"

class SpeedBar: public GameObject{
    public:
        SpeedBar(float _x, float _y);
        void draw();
        void setSpeed(float v);
    private:
        float markHeight;
        float markWidth;
        float barHeight;
        float barWidth;
        float speed;
        int mouseX;
        int mouseY;


};


#endif /* SPEEDBAR */

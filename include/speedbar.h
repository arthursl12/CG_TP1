#ifndef SPEEDBAR_H
#define SPEEDBAR_H

#include "gObject.h"

class SpeedBar: public GameObject{
    public:
        SpeedBar(float _x, float _y);
        void draw();
        void setMousePos(int _x, int _y);
    private:
        float height;
        float width;
        float speed;
        int mouseX;
        int mouseY;


};


#endif /* SPEEDBAR */

#ifndef TEXTO_H
#define TEXTO_H

#include <string>
#include "gObject.h"

class Texto: public GameObject{
    public:
        Texto(float _x, float _y, std::string _str);
        void draw();
        void updateString(std::string _str);
    private:
        std::string str;
};

#endif /* TEXTO_H */
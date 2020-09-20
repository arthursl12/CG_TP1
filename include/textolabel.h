#ifndef TEXTOLABEL_H
#define TEXTOLABEL_H

#include "gObject.h"
#include "texto.h"
#include <memory>

class TextoLabel : public GameObject{
    public:
        TextoLabel(float _x, float _y, std::string _label, std::string _str);
        void draw();
        void updateText(std::string _str);
    private:
        std::string labelStr;
        std::shared_ptr<Texto> label;
        std::string textStr;
        std::shared_ptr<Texto> text;
};

#endif
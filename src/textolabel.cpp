#include "textolabel.h"

TextoLabel::TextoLabel(float _x, float _y, std::string _label, std::string _str){
    this->labelStr = _label + ": ";
    this->textStr = _str;
    this->text = std::make_shared<Texto>(_x + labelStr.size()*10, _y, textStr);
    this->label = std::make_shared<Texto>(_x, _y, labelStr);
}

void TextoLabel::draw(){
    text->draw();
    label->draw();
}
void TextoLabel::updateText(std::string _str){
    textStr = _str;
    text->updateString(_str);
}
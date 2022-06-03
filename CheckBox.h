//
// Created by Lyubo on 5/22/2022.
//

#ifndef HW2_CHECKBOX_H
#define HW2_CHECKBOX_H

#include "Control.h"

class CheckBox : public Control {
public:
    CheckBox();

    CheckBox(const int x, const int y, const String &text, const bool ifChecked) {
        size = Size(text.get_length() + 4, 1);
        type = ControlType::INPUTCONTROL;
        setPosition(x, y);
        this->text = text;
        if (ifChecked) {
            status = "Checked";
        } else {
            status = "Unchecked";
        }
    }

    CheckBox &operator=(const CheckBox &other) {

        this->size = other.size;
        this->type = other.type;
        setPosition(other.position[0], other.position[1]);
        this->status = other.status;
        this->text = other.text;
        return *this;
    }

    void printDescription() const override {
        std::cout << text << std::endl;
    }
    String getText()const{
        return text;
    }
    void visualisation()const override{
        if(status == "Checked"){
            std::cout<<"[X]";}
        else{
            std::cout<<"[ ]";
        }
        std::cout << text<<std::endl;
    }
};

CheckBox::CheckBox() {

}

#endif //HW2_CHECKBOX_H

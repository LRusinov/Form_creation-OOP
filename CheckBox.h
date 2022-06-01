//
// Created by Lyubo on 5/22/2022.
//

#ifndef HW2_CHECKBOX_H
#define HW2_CHECKBOX_H

#include "Control.h"

class CheckBox : private Control {
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
        this->text = text;
    }

    void printDescription() const override {
        std::cout << text << std::endl;
    }
    String getText()const{
        return text;
    }
};

#endif //HW2_CHECKBOX_H
//
// Created by Lyubo on 5/22/2022.
//

#ifndef HW2_LABEL_H
#define HW2_LABEL_H

#include "Control.h"

class Label : private Control {
private:
    Label(const int x, const int y, const String &content) {
        size = Size(content.get_length(), 1);
        type = ControlType::OUTPUTCONTROL;
        setPosition(x, y);
        text = content;
        status = text;
    }
    void printDescription()const override{
        std::cout<<text<<std::endl;
    }
};

#endif //HW2_LABEL_H

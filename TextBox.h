//
// Created by Lyubo on 5/22/2022.
//

#ifndef HW2_TEXTBOX_H
#define HW2_TEXTBOX_H

#include "Control.h"

class TextBox : public Control {
private:
public:
    TextBox(const int x, const int y, const String &string, const int h, const int w) {
        this->size = Size(w, h);
        this->type = ControlType::IOCTONROL;
        this->text = string;
        setPosition(x, y);
    }

    void printDescription() const override {
        std::cout << text << std::endl;
    }

    void setStatus() {
        int counter = 0;
        while (counter < size.width * size.height) {
            for (int i = 0; i <size.width; ++i) {
                for (int j = 0; j < size.height ; ++j) {
                    status.pushBack(text[counter]);
                    counter++;
                }
            }
        }
    }

};

#endif //HW2_TEXTBOX_H

//
// Created by Lyubo on 5/22/2022.
//

#ifndef HW2_RADIOBUTTON_H
#define HW2_RADIOBUTTON_H

#include "CheckBox.h"
#include "Vector.h"
#include "Control.h"

class RadioBox : public Control {
private:
    Vector<CheckBox> options;
    int selected;
public:
    RadioBox(const int x, const int y, const String &string, const int selected) {
        type = ControlType::INPUTCONTROL;
        this->text = string;
        this->selected = selected;
        setPosition(x, y);
        size_t sizeOfStr = string.get_length();
        int optionsCounter = 0;
        int maxLen = 0;
        String option;
        for (size_t i = 0; i < sizeOfStr; ++i) {
            if (string[i] != ';') {
                option.pushBack(string[i]);
            } else {
                if (option.get_length() > maxLen) {
                    maxLen = option.get_length();
                }
                optionsCounter++;
                bool flag = false;
                if (optionsCounter == selected + 1) {
                    flag = true;
                }

                CheckBox newCheckBox(x + optionsCounter, option.get_length(), option, flag);

                flag = false;
                options.pushBack(newCheckBox);
                option = "";
            }
        }
        optionsCounter++;
        size = Size(maxLen, optionsCounter);
        status = options[selected].getText();

    }

    void printDescription() const override {
        options[selected].printDescription();
    }

    void visualisation() const override {
        for (int i = 0; i < options.get_size(); ++i) {
            options[i].visualisation();

            if (i + 1 != options.get_size()) {
                std::cout << std::endl;
            }
    }
}

};

#endif //HW2_RADIOBUTTON_H

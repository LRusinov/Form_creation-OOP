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
        setPosition(x,y);
        size_t sizeOfStr = string.get_length();
        int optionsCounter = 0;
        int maxLen=0;
        String* option = new String();
        for (size_t i = 0; i < sizeOfStr; ++i) {
            if(string[i]!=';'){
                option->pushBack(string[i]);
            }
            else {
                if(option->get_length()>maxLen){
                    maxLen=option->get_length();
                }
                optionsCounter++;
                CheckBox newCheckBox(x+optionsCounter,option->get_length(),*option, false);
                options.pushBack( newCheckBox);
                delete option;
                option = new String();
            }
        }
        delete option;
        optionsCounter++;
        size=Size(maxLen,optionsCounter);
        status = options[selected].getText();
    }
    void printDescription()const override{
        options[selected].printDescription();
    }
};

#endif //HW2_RADIOBUTTON_H

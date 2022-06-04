#include "RadioButton.h"

RadioBox::RadioBox(const int x, const int y, const String &string, const int selected) {
    try {
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
    catch (char *exc) {
        std::cout << exc;
    }
}

void RadioBox::printDescription() const {
    options[selected].printDescription();
}

void RadioBox::visualisation() const {
    for (int i = 0; i < options.get_size(); ++i) {
        options[i].visualisation();

        if (i + 1 != options.get_size()) {
            std::cout << std::endl;
        }
    }
}

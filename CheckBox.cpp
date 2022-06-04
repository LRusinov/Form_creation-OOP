//
// Created by Lyubo on 6/4/2022.
//
#include "CheckBox.h"


CheckBox::CheckBox(const int x, const int y, const String &text, const bool ifChecked) {
    try {
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
    catch (char *exc) {
        std::cout << exc;
    }
}

String CheckBox::getText() const {
    return text;
}

void CheckBox::printDescription() const {
    std::cout << text << std::endl;
}

CheckBox &CheckBox::operator=(const CheckBox &other) {
    this->size = other.size;
    this->type = other.type;
    setPosition(other.position[0], other.position[1]);
    this->status = other.status;
    this->text = other.text;
    return *this;
}

void CheckBox::visualisation() const {
    if (status == "Checked") {
        std::cout << "[X] ";
    } else {
        std::cout << "[ ] ";
    }
    std::cout << text;
}



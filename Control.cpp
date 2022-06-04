
#include "Control.h"
#include<cmath>

int Control::nextID = 0;

Control::Control() {
    position[0] = 0;
    position[1] = 0;
    type = ControlType::DEFAULT;
}

void Control::setSize(const Size &size) {
    if (size.width < 1 || size.height < 1) {
        this->size.width = 0;
        this->size.height = 0;
        throw "Invalid size";
    } else {
        this->size.width = size.width;
        this->size.height = size.height;
    }
}

void Control::setText(const String &text) {
    this->text = text;
}

void Control::setPosition(const int coord1, const int coord2) {
    if (coord1 < 0 || coord2 < 0) {
        throw "Invalid Coords";
    } else {
        position[0] = coord1;
        position[1] = coord2;
    }
}

int Control::getID() const {
    return id;
}

String Control::getStatus() const {
    return status;
}

String Control::idToString() const {
    String numInString;
    int digitsCount = 0;
    int num = id;
    while (num != 0) {
        digitsCount++;
        num /= 10;
    }
    num = id;
    for (int i = digitsCount - 1; i >= 0; i--) {
        numInString.pushBack(char((num / pow(10, i)) + 48));
        num %= int(pow(10, i));
    }

    return numInString;
}

int Control::getPosition(int n) const {
    if (n == 0) {
        return position[0];
    } else {
        return position[1];
    }
}

int Control::getWidth() const {
    return size.width;
}


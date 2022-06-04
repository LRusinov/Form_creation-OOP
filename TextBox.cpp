#include "TextBox.h"


TextBox::TextBox(const int x, const int y, const String &string, const int h, const int w) {

    try {
        this->size = Size(w, h);
        this->type = ControlType::IOCTONROL;
        this->text = string;
        setPosition(x, y);
        setStatus();
    }

    catch (const char *exc) {
        std::cout << exc;
    }
}

void TextBox::printDescription() const {
    std::cout << text << std::endl;
}

void TextBox::setStatus() {

    int counter = 0;
    while (counter < size.width * size.height) {
        for (int i = 0; i < size.height; ++i) {
            for (int j = 0; j < size.width; ++j) {
                status.pushBack(text[counter]);
                counter++;
            }
            status.pushBack('\n');
        }
    }
}

void TextBox::visualisation() const {
    std::cout << status;
}

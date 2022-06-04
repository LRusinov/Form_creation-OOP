#include "Label.h"

Label::Label(const int x, const int y, const String &content) {
    try {
        size = Size(content.get_length(), 1);
        type = ControlType::OUTPUTCONTROL;
        setPosition(x, y);
        text = content;
        status = text;
    }
    catch (const char *exc) {
        std::cout << exc;
    }
}

void Label::printDescription() const {
    std::cout << text << std::endl;
}

void Label::visualisation() const {
    std::cout << text;
}

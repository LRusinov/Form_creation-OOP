#include "ListBox.h"

ListBox::ListBox(const int x, const int y, const Vector<String> &ls, const int selected) {
    try {
        this->selected = selected;
        size = Size(ls[selected].get_length(), 1);
        for (int i = 0; i < list.get_size(); i++) {
            text.Concat(ls[i]);
        }
        type = ControlType::INPUTCONTROL;
        setPosition(x, y);
        list = ls;
        status = list[selected];
    }
    catch (const char *exc) {
        std::cout << exc;
    }
}

void ListBox::printDescription() const {
    size_t listSize = list.get_size();
    for (int i = 0; i < listSize; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

void ListBox::visualisation() const {
    std::cout << list[selected];
}

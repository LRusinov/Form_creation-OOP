
#ifndef HW2_LISTBOX_H
#define HW2_LISTBOX_H

#include "Vector.h"
#include "String.h"
#include "Control.h"

class ListBox : public Control {
private:
    Vector<String> list;
    int selected;
public:
    ListBox(const int x, const int y, const Vector<String> &ls, const int selected) {
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

    void printDescription() const override {
        size_t listSize = list.get_size();
        for (int i = 0; i < listSize; ++i) {
            std::cout << list[i] << " ";
        }
        std::cout << std::endl;
    }

    void visualisation() const override {
        std::cout << list[selected];
    }
};

#endif //HW2_LISTBOX_H

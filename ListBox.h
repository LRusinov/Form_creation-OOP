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
    ListBox(int x, int y, const Vector<String> &ls, int selected) ;

    void printDescription() const override ;

    void visualisation() const override ;
};

#endif //HW2_LISTBOX_H

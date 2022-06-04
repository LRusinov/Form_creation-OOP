#ifndef HW2_FORM_H
#define HW2_FORM_H

#include "String.h"
#include "Control.h"
#include "Vector.h"

class Form {
private:
    Vector<Control *> controls;
    String name;

public:
    Form(const String &name);

    void preview();

    void addControl(Control *newControl);

    Control* operator[](int index)const;

    String getStatus()const;

    void changeText(int n,const String& newText);
};

#endif //HW2_FORM_H

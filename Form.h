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

    void preview();//printing the form

    void addControl(Control *newControl);//adding control and also keeps the vector sorted

    Control* operator[](int index)const;

    String getStatus()const;

    void changeText(int n,const String& newText);//changing the text of output control by given ID
};

#endif //HW2_FORM_H

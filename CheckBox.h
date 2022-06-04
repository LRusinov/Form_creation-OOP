#ifndef HW2_CHECKBOX_H
#define HW2_CHECKBOX_H

#include "Control.h"

class CheckBox : public Control {
public:
    CheckBox()=default;

    CheckBox(int x, int y, const String &text, bool ifChecked) ;

    CheckBox &operator=(const CheckBox &other) ;

    void printDescription() const override ;

    String getText()const;

    void visualisation()const override;
};

#endif //HW2_CHECKBOX_H

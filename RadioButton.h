//
// Created by Lyubo on 5/22/2022.
//

#ifndef HW2_RADIOBUTTON_H
#define HW2_RADIOBUTTON_H

#include "CheckBox.h"
#include "Vector.h"
#include "Control.h"

class RadioBox : public Control {
private:
    Vector<CheckBox> options;
    int selected;
public:
    RadioBox(const int x, const int y, const String &string, const int selected) ;

    void printDescription() const override ;

    void visualisation() const override;

};

#endif //HW2_RADIOBUTTON_H

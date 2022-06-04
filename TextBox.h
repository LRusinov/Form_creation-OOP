//
// Created by Lyubo on 5/22/2022.
//

#ifndef HW2_TEXTBOX_H
#define HW2_TEXTBOX_H

#include "Control.h"

class TextBox : public Control {
private:
public:
    TextBox(int x, int y, const String &string, int h, int w);

    void printDescription() const override;

    void setStatus();

    void visualisation() const override;

};

#endif //HW2_TEXTBOX_H

//
// Created by Lyubo on 5/22/2022.
//

#ifndef HW2_TEXTBOX_H
#define HW2_TEXTBOX_H

#include "Control.h"

class TextBox : public Control {
private:
public:
    TextBox(const int x, const int y, const String &string, const int h, const int w);

    void printDescription() const override;

    void setStatus();

    void visualisation() const override;

    String getText();
};

#endif //HW2_TEXTBOX_H

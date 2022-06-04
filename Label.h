//
// Created by Lyubo on 5/22/2022.
//

#ifndef HW2_LABEL_H
#define HW2_LABEL_H

#include "Control.h"

class Label : public Control {
public:
    Label(int x, int y, const String &content);

    void printDescription() const override ;

    void visualisation() const override;
};

#endif //HW2_LABEL_H


#include "Form.h"

void Form::addControl(Control *newControl) {
    if (controls.get_size() == 0) {
        controls.pushBack(newControl);
        return;
    }
    for (int i = 0; i < controls.get_size(); ++i) {
        if (controls[i]->getPosition(0) > newControl->getPosition(0)) {
            controls.insert(i, newControl);
            return;
        } else if (controls[i]->getPosition(0) == newControl->getPosition(0)) {
            if (controls[i]->getPosition(1) > newControl->getPosition(1)) {
                controls.insert(i, newControl);
                return;
            }
        }
    }
    controls.pushBack(newControl);
}

void Form::preview() {
    int counter = 0;
    for (int i = 0; i < controls.get_size(); ++i) {
        controls[i]->visualisation();
    }
}

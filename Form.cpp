
#include "Form.h"

void Form::addControl(Control *newControl) {
    for (int i = 0; i < controls.get_size(); ++i) {
        if (controls[i]->getPosition()[0] > newControl->getPosition()[0]) {
            controls.insert(i, newControl);
            break;
        } else if (controls[i]->getPosition()[0] == newControl->getPosition()[0]){
            if (controls[i]->getPosition()[1] > newControl->getPosition()[1]) {
                controls.insert(i, newControl);
                break;
            }
        }
    }
    controls.pushBack(newControl);
}

void Form::preview() {
    int counter = 0;
    for (int i = 0; i < controls.get_size(); ++i) {
        std::cout<<controls[i]->getStatus();
    }
}

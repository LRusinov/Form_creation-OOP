
#include "Form.h"


Form::Form(const String &name) {
    this->name = name;
}


void Form::addControl(Control *newControl) {
    int controlsNum = controls.get_size();

    if (controlsNum == 0) {
        controls.pushBack(newControl);
        return;
    }

    for (int i = 0; i < controlsNum; ++i) {
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
    std::cout << name << std::endl;

    int controlsNum = controls.get_size();
    int x0, x1;
    int y0, y1;
    if (controlsNum > 0) {
        controls[0]->visualisation();
        if (1 != controlsNum && controls[0]->getPosition(0) != controls[1]->getPosition(0)) {
            std::cout << std::endl;
        }

        for (int i = 1; i < controlsNum; ++i) {

            x0 = controls[i]->getPosition(0);
            y0 = controls[i - 1]->getPosition(0);
            x1 = controls[i]->getPosition(1);
            y1 = controls[i - 1]->getPosition(1);

            if (x0 == y0) {
                if (x1 - controls[i - 1]->getWidth() - y1 > 1) {
                    int x = x1 - controls[i - 1]->getWidth() - y1;
                    while (x != 1) {
                        std::cout << " ";
                        x--;
                    }
                }
            } else if (x0 - controls[i - 1]->getHeight() > 1) {
                int x = x0 - controls[i - 1]->getHeight();
                while (x != 1) {
                    std::cout << std::endl;
                    x--;
                }
            }

            controls[i]->visualisation();
            if (i + 1 != controlsNum && x0 != controls[i + 1]->getPosition(0)) {
                std::cout << std::endl;
            }
        }
    } else {
        std::cout << "No controls to show!\n";
    }
}

Control *Form::operator[](int index) const {
    return controls[index];
}

String Form::getStatus() const {
    String result;

    int sizeOfControls = controls.get_size();

    for (int i = 0; i < sizeOfControls; ++i) {
        result.Concat(controls[i]->idToString());
        result.Concat(" ");
        result.Concat(controls[i]->getStatus());
        result.pushBack('\n');
    }
    return result;
}

void Form::changeText(int n, const String &newText) {
    int sizeOfControls = controls.get_size();
    for (int i = 0; i < sizeOfControls; ++i) {
        if (controls[i]->getId() == n) {
            if (controls[i]->getType() == ControlType::OUTPUTCONTROL ||
                controls[i]->getType() == ControlType::IOCTONROL) {
                controls[i]->setText(newText);
            } else {
                std::cout << "It is not output control!";
            }
            return;
        }
    }
    std::cout << "No id found";
}




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
    controls[0]->visualisation();
    if(controls[0]->getPosition(0)!=controls[1]->getPosition(0)){
        std::cout<<std::endl;
    }
    for (int i = 1; i < controls.get_size(); ++i) {
        if(controls[i]->getPosition(0)==controls[i-1]->getPosition(0)){
            if(controls[i]->getPosition(1)-controls[i-1]->getPosition(1)>1){
                int x = controls[i]->getPosition(1)-controls[i-1]->getPosition(1);
                while (x!=1){
                    std::cout<<" ";
                    x--;
                }
            }
        }
        else if(controls[i]->getPosition(0)-controls[i-1]->getPosition(0)>1) {
            int x = controls[i]->getPosition(0)-controls[i-1]->getPosition(0);
            while (x!=1){
                std::cout<<std::endl;
                x--;
            }
        }
        controls[i]->visualisation();
        if(i+1!=controls.get_size()&&controls[i]->getPosition(0)!=controls[i+1]->getPosition(0)){
            std::cout<<std::endl;
        }
    }
}

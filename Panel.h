
#ifndef HW2_PANEL_H
#define HW2_PANEL_H

#include "Vector.h"
#include "Control.h"

class Panel : public Control {
private:
    Vector<Control *> collection;
public:
    Panel(const int x, const int y, const String &string) {
        text = string;
        type = ControlType::IOCTONROL;
        size = Size(0, 0);
        setPosition(x, y);
    }

    ~Panel() {
        size_t controlsNum = collection.get_size();
        for (size_t i = 0; i < controlsNum; ++i) {
            delete collection[i];
        }
    }

    void printDescription() const override {
        std::cout << text;
    }

    void setStatus() {
        int controlsNum = collection.get_size();
        for (int i = 0; i < controlsNum; ++i) {
            status.Concat(collection[i]->idToString());
            status.pushBack(' ');
            status.Concat(collection[i]->getStatus());
            if (i != controlsNum - 1) {
                status.pushBack('|');
            }
        }
    }
    void visualisation()const override{
        for (int i = 0; i <collection.get_size() ; ++i) {
            collection[i]->visualisation();
        }
    }
};

#endif //HW2_PANEL_H

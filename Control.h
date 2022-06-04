#ifndef HW2_CONTROL_H
#define HW2_CONTROL_H

#include "String.h"

enum class ControlType {
    DEFAULT,
    INPUTCONTROL,
    OUTPUTCONTROL,
    IOCTONROL

};

struct Size {
    int width;
    int height;

    Size() {
        width = 0;
        height = 0;
    }

    Size(int width, int height) {
        this->width = width;
        this->height = height;
    }
};

class Control {
protected:
    static int nextID;

public:
    int getPosition(int n) const;

protected:
    const int id = ++nextID;
    int position[2]{};
    Size size;
    String text;
    ControlType type;
    String status;

public:
    Control();

    ~Control() = default;

    void setPosition(int coord1, int coord2);

    int getWidth() const;

    int getHeight() const;

    virtual void printDescription() const = 0;

    String getStatus() const;

    String idToString() const;

    virtual void visualisation() const = 0;

};

#endif //HW2_CONTROL_H

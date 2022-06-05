#ifndef HW2_CONTROL_H
#define HW2_CONTROL_H

#include "String.h"

enum class ControlType {
    DEFAULT,
    INPUTCONTROL,
    OUTPUTCONTROL,
    IOCTONROL

};

struct Size {  //structure used for setting the size of control
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
    static int nextID; //counter for the next id

protected:
    const int id = ++nextID;//generating id
    int position[2]{};
    Size size;
    String text;
    ControlType type;
    String status;

public:
    //C-tors
    Control();

    ~Control() = default;

    //Getters and setters
    void setPosition(int coord1, int coord2);

    int getWidth() const;

    int getHeight() const;

    int getPosition(int n) const;

    int getId()const;

    ControlType getType() const;

    void setText(const String &newText);

    String getStatus() const;

    //Other functions
    virtual void printDescription() const = 0;

    const String idToString() const; //converting int to String

    virtual void visualisation() const = 0;

};

#endif //HW2_CONTROL_H

//
// Created by Lyubo on 5/22/2022.
//

#ifndef HW2_CONTROL_H
#define HW2_CONTROL_H

#include "String.h"

enum class ControlType {
    DEFAULT,
    INPUTCONTROL,
    OUTPUTCONTROL,
    IOCTONROL

};
struct Size{
    int width;
    int height;
    Size(){
        width=0;
        height = 0;
    }
    Size(int width,int height){
        this->width=width;
        this->height=height;
    }
};
class Control {
protected:
    static int nextID;
public:
    const int *getPosition() const;

protected:
    const int id = ++nextID;
    int position[2];
    Size size;
    String text;
    ControlType type;
    String status;

public:
    Control();

    void setSize(const Size& size);

    void setText(const String &text);

    void setPosition(const int coord1, const int coord2);

    virtual void printDescription() const =  0;
    const int getID()const;
    String getStatus()const;
    String idToString()const;
    virtual void visualisation()const =0;
};

#endif //HW2_CONTROL_H

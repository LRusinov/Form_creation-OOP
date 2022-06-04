
#ifndef HW2_PANEL_H
#define HW2_PANEL_H

#include "Vector.h"
#include "Control.h"

class Panel : public Control {
private:
    Vector<Control *> collection;
public:
    Panel(const int x, const int y, const String &string) ;

    void add(Control *newControl);

    void printDescription() const override ;

    void setStatus() ;

    void visualisation() const override;
};

#endif //HW2_PANEL_H

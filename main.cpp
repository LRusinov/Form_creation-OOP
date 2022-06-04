#include <iostream>
#include "String.h"
#include "Vector.h"
#include <cmath>
#include "Panel.h"
#include "Control.h"
#include "CheckBox.h"
#include "Form.h"
#include "Label.h"
#include "ListBox.h"
#include "RadioButton.h"
#include "TextBox.h"

int main() {
    Vector<String> vec;
    vec.pushBack("ab");
    vec.pushBack("bb");

    CheckBox cBox(0, 0, "abv", true);

    Label lbl(1, 0, "label text: ");

    ListBox lBox(0, 9, vec, 1);

    RadioBox rButton(1, 11, "a;b;c;", 1);

    TextBox tBox(6, 0, "1234 67sdfsdfsd89", 3, 4);


    Form f("Name");
    Panel p(0,0,"Name");
    p.add(&cBox);
    p.add(&lbl);
    p.add(&lBox);
    p.add(&rButton);
    p.add(&tBox);
    f.addControl(&p);
    f.preview();
    return 0;
}

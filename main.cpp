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

    ListBox lBox(0, 2, vec, 1);

    RadioBox rButton(6, 0, "a;b;c;", 1);

    TextBox tBox(10, 0, "1234 67sdfsdfsd89", 3, 4);


    Form f;
    f.addControl(&cBox);
    f.addControl(&lbl);
    f.addControl(&lBox);
    f.addControl(&rButton);
    f.addControl(&tBox);
    f.preview();
    return 0;
}

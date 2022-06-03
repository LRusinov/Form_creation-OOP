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

    CheckBox cBox(0,0,"abv",true);
    cBox.visualisation();

    Label lbl(1,0,"label text: ");
    lbl.visualisation();

    ListBox lBox(2,0,vec,1);
    lBox.visualisation();

    RadioBox rButton(6,0,"a;b;c;",1);
    rButton.visualisation();

    TextBox tBox(10,0,"1234 67sdfsdfsd89",3,4);
    tBox.visualisation();
    return 0;
}

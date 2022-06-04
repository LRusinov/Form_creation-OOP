#include "String.h"
#include "Vector.h"
#include "Panel.h"
#include "CheckBox.h"
#include "Form.h"
#include "Label.h"
#include "ListBox.h"
#include "RadioButton.h"
#include "TextBox.h"

int main() {
    Vector<String> vec;
    vec.pushBack("List Option 1");
    vec.pushBack("List Option 2");

    CheckBox cBox(0, 0, "Check box ", true);

    Label lbl(2, 0, "Please chose one of the options: ");

    ListBox lBox(1, 0, vec, 1);

    RadioBox rButton(2, 11, "Radio button a;Radio button b;Radio button c;", 1);

    TextBox tBox(6, 0, "The text box will visualize 12 symbols!", 3, 4);
    TextBox tBox2(6, 0, "Tbox after panel", 4, 6);



    Form f("Form name");
    Panel p(0,0,"Panel name");
    p.add(&cBox);
    p.add(&lbl);
    p.add(&lBox);
    p.add(&rButton);
    p.add(&tBox);
    f.addControl(&p);
    f.addControl(&tBox2);
    f.preview();
    return 0;
}

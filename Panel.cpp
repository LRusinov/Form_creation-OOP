#include "Panel.h"

Panel::Panel(const int x, const int y, const String &string) {
    text = string;
    type = ControlType::IOCTONROL;
    size = Size(0, 0);
    setPosition(x, y);
}

void Panel::add(Control *newControl) {
    if (collection.get_size() == 0) {
        collection.pushBack(newControl);
        return;
    }
    for (int i = 0; i < collection.get_size(); ++i) {
        if (collection[i]->getPosition(0) > newControl->getPosition(0)) {
            collection.insert(i, newControl);
            return;
        } else if (collection[i]->getPosition(0) == newControl->getPosition(0)) {
            if (collection[i]->getPosition(1) > newControl->getPosition(1)) {
                collection.insert(i, newControl);
                return;
            }
        }
    }
    collection.pushBack(newControl);

}

void Panel::printDescription() const {
    std::cout << text;
}

void Panel::setStatus() {
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

void Panel::visualisation() const {
    std::cout << text << std::endl;

    collection[0]->visualisation();
    for (int i = 1; i < collection.get_size(); ++i) {
        if (collection[i]->getPosition(0) == collection[i - 1]->getPosition(0)) {
            if (collection[i]->getPosition(1) - collection[i - 1]->getWidth() - collection[i - 1]->getPosition(1) > 1) {
                int x = collection[i]->getPosition(1) - collection[i - 1]->getWidth() -
                        collection[i - 1]->getPosition(1);
                while (x != 1) {
                    std::cout << " ";
                    x--;
                }
            }
        } else if (collection[i]->getPosition(0) - collection[i - 1]->getPosition(0) > 1) {
            int x = collection[i]->getPosition(0) - collection[i - 1]->getPosition(0);
            while (x != 1) {
                std::cout << std::endl;
                x--;
            }
        }
        collection[i]->visualisation();
        if (i + 1 != collection.get_size() && collection[i]->getPosition(0) != collection[i + 1]->getPosition(0)) {
            std::cout << std::endl;
        }
    }
}


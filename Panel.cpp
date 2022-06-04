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

    int collectionSize = collection.get_size();
    for (int i = 0; i < collectionSize; ++i) {
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

    int collectionSize = collection.get_size();
    int x0, x1;
    int y0, y1;

    collection[0]->visualisation();
    if (1 != collectionSize && collection[0]->getPosition(0) != collection[1]->getPosition(0)) {
        std::cout << std::endl;
    }

    for (int i = 1; i < collectionSize; ++i) {

        x0 = collection[i]->getPosition(0);
        y0 = collection[i - 1]->getPosition(0);
        x1 = collection[i]->getPosition(1);
        y1 = collection[i - 1]->getPosition(1);

        if (x0 == y0) {
            if (x1 - collection[i - 1]->getWidth() - y1 > 1) {
                int x = x1 - collection[i - 1]->getWidth() - y1;
                while (x != 1) {
                    std::cout << " ";
                    x--;
                }
            }
        } else if (x0 - collection[i - 1]->getHeight() > 1) {
            int x = x0 - collection[i - 1]->getHeight();
            while (x != 1) {
                std::cout << std::endl;
                x--;
            }
        }
        collection[i]->visualisation();

        if (i + 1 != collectionSize && x0 != collection[i + 1]->getPosition(0)) {
            std::cout << std::endl;
        }
    }
}


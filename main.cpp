#include <iostream>
#include "String.h"
#include <cmath>
int main() {
    String numInString;
    int digitsCount = 0;
    int num = 342;
    while (num != 0) {
        digitsCount++;
        num /= 10;
    }
num=342;
    for (int i = digitsCount-1; i >= 0; i--) {
        numInString.pushBack(char((num / pow(10, i))+48));
        num%=int(pow(10, i));
    }
    std::cout<<numInString;
    return 0;
}

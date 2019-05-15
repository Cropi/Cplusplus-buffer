#include <iostream>
#include "buffer.h"


int main() {
    Buffer buffer;
    std::string type;

    while(42) {
        std::cin >> type;

        if (type == "exit")
            break;
        else if (type == "print")
            buffer.printAndDelBuffer();
        else if (type == "get")
            buffer.getFirst();
        else  {
            buffer.insert(type);
        }
    }

    return 0;
}

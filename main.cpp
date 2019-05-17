#include <iostream>
#include <string.h>
#include "buffer.h"


int main(int argc, char *argv[]) {
    Buffer buffer;
    std::string type;

    if(argc == 2 && strcmp(argv[1], "-h") == 0) {
        std::cout << "Commands:\n" <<
        "\tprint - print out all the elements of the buffer and erase it.\n"
        "\tget - print out the first element of the buffer.\n"
        "\texit - quit application.\n"
        "\tnumber1:number2 - insert number1 into the buffer with priority of number2.\n";
        return 0;
    }

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

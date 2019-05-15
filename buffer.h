#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> // find_if
#include <string>
#include <iomanip> // std::setw
#include <exception> // handle exceptions


class Buffer {
public:
    Buffer() {};

    void insert(std::string expression);
    void printAndDelBuffer();
    void getFirst();
private:
    std::vector<std::tuple <int, int> > data;
    void insertData(std::tuple<int, int>);
};



#endif

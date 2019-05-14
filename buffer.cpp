#include "buffer.h"

using namespace std;

void Buffer::insertData(std::tuple<int, int> newData) {
    auto it = find_if(begin(data), end(data), [newData](auto&& e) { return get<0>(e) < get<0>(newData); });
    if (it != data.end()) {
        data.insert(it, newData);
    }
    else {
        data.push_back(newData);
    }
}

void Buffer::printAndDelBuffer() {
    for(auto elem: data)
        std::cout << std::setw(3) << get<0>(elem) << std::setw(3) << " : " << std::setw(2) << get<1>(elem) << "\n";

    if (data.empty())
        std::cerr << "Nothing to print. In order to do that, please fill the buffer with data\n";

    data.clear();
}

void Buffer::getFirst() {
    try {
        auto elem = data.at(0);
        std::cout << std::setw(3) << get<0>(elem) << std::setw(3) << " : " << std::setw(2) << get<1>(elem) << endl;
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Nothing to print. In order to do that, please fill the buffer with data\n";
    }
}

void Buffer::insert(string expression) {

    int priority, data;

    try {
        std::size_t pos = expression.find(":");
        if (pos == string::npos) {
            throw invalid_argument("Invalid syntax");
        }
        priority = std::stoi(expression.substr(0, pos));
        data = std::stoi(expression.substr(pos+1));
    }
    catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid syntax.\nHint: X:Y where X and Y are integers.\n";
        return;
    }

    insertData(std::make_tuple(priority, data));
}

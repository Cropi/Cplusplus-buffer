#include "buffer.h"

using std::cout;
using std::endl;
using std::string;

void Buffer::insertData(std::tuple<int, int> newData) {
    // Returns an iterator to a tuple<int,int> after which will be the newData inserted
    // if no such pair has been found(vector is empty) -> push back
    auto it = find_if(begin(data), end(data), [newData](auto&& e) { return std::get<1>(e) < std::get<1>(newData); });
    if (it != data.end()) {
        data.insert(it, newData);
    }
    else {
        data.push_back(newData);
    }
}

/*
 * @brief Prints out the content of the buffer as well as deletes its content
 * @note If the buffer is emty a warning message is printed out.
 */
void Buffer::printAndDelBuffer() {
    if (data.empty()) {
        std::cerr << "Nothing to print. In order to do that, please fill the buffer with data\n";
        return;
    }

    cout <<
    " Index | Value | Priority\n" <<
    "-------+-------+---------\n";

    int index = 0;
    for(auto elem: data)
        cout <<
        std::setw(7) << index++ << "|" << // cout index
        std::setw(7) << std::get<0>(elem) << "|" << // cout value
        std::setw(9) << std::get<1>(elem) << endl; // cout priority

    data.clear();
}

/*
 * @brief Gets the first value of the vector according to the largest priority
 */
void Buffer::getFirst() {
    try {
        auto elem = data.at(0);
        cout << std::setw(3) << std::get<0>(elem) << std::setw(3) << " : " << std::setw(2) << std::get<1>(elem) << endl;
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Nothing to print. In order to do that, please fill the buffer with data.\n";
    }
}

/*
 * @brief Converts the string into a tuple containing priority + data
 * @param expression contains a "value:data" pair
 */
void Buffer::insert(string expression) {

    int priority, value;

    try {
        std::size_t pos = expression.find(":");
        if (pos == string::npos) {
            throw std::invalid_argument("Invalid syntax");
        }
        value = std::stoi(expression.substr(0, pos));
        priority = std::stoi(expression.substr(pos+1));
    }
    catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid syntax.\nHint: Rerun program with \"-h\" parameter\n";
        return;
    }

    insertData(std::make_tuple(value, priority));
}

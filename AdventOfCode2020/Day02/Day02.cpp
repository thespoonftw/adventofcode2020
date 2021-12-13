
#include <string>
#include <vector>
#include "../DayBase.h"
using namespace std;

class Password {
    public:
        void loadData(string entry);
        bool isValidPartOne();
        bool isValidPartTwo();
    private:
        int index1 = 0;
        int index2 = 0;
        char character = '_';
        string code;
};

void Password::loadData(string entry) {
    string delimiter = " ";
    int firstDelim = entry.find("-");
    index1 = stoi(entry.substr(0, firstDelim));
    int secondDelim = entry.find(" ");
    index2 = stoi(entry.substr(firstDelim + 1, secondDelim));
    character = entry.at(secondDelim + 1);
    int thirdDelim = entry.find(":");
    code = entry.substr(thirdDelim + 2, entry.size() - 1);
}

bool Password::isValidPartOne() {
    int counter = 0;
    for (int i = 0; i < code.size(); i++) {
        char c = code.at(i);
        if (c == character) { counter++; }
    }
    return (counter >= index1) && (counter <= index2);
}

bool Password::isValidPartTwo() {
    bool b1 = code.at(index1 - 1) == character;
    bool b2 = code.at(index2 - 1) == character;
    return b1 ^ b2;
}

int Day02::partOne() {
    int counter = 0;
    for (int i = 0; i < data.size(); i++) {
        Password password;
        password.loadData(data.at(i));
        if (password.isValidPartOne()) { counter++; }
    }
    return counter;
}

int Day02::partTwo() {
    int counter = 0;
    for (int i = 0; i < data.size(); i++) {
        Password password;
        password.loadData(data.at(i));
        if (password.isValidPartTwo()) { counter++; }
    }
    return counter;
}





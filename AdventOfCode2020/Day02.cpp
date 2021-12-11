
#include <string>
#include <vector>
#include "Day02.h"
using namespace std;

class Password {
    public:
        void LoadData(string entry);
        bool IsValidPartOne();
        bool IsValidPartTwo();
    private:
        int index1;
        int index2;
        char character;
        string code;
};

void Password::LoadData(string entry) {
    string delimiter = " ";
    int firstDelim = entry.find("-");
    index1 = stoi(entry.substr(0, firstDelim));
    int secondDelim = entry.find(" ");
    index2 = stoi(entry.substr(firstDelim + 1, secondDelim));
    character = entry.at(secondDelim + 1);
    int thirdDelim = entry.find(":");
    code = entry.substr(thirdDelim + 2, entry.size() - 1);
}

bool Password::IsValidPartOne() {
    int counter = 0;
    for (int i = 0; i < code.size(); i++) {
        char c = code.at(i);
        if (c == character) { counter++; }
    }
    return (counter >= index1) && (counter <= index2);
}

bool Password::IsValidPartTwo() {
    bool b1 = code.at(index1 - 1) == character;
    bool b2 = code.at(index2 - 1) == character;
    return b1 ^ b2;
}

int Day02::PartOne() {
    int counter = 0;
    for (int i = 0; i < data.size(); i++) {
        Password password;
        password.LoadData(data.at(i));
        if (password.IsValidPartOne()) { counter++; }
    }
    return counter;
}

int Day02::PartTwo() {
    int counter = 0;
    for (int i = 0; i < data.size(); i++) {
        Password password;
        password.LoadData(data.at(i));
        if (password.IsValidPartTwo()) { counter++; }
    }
    return counter;
}





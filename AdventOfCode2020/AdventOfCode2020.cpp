
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include "DayBase.h"
using namespace std;

vector<string> GetData(string folder);

int main() {
    string dayNumber = "01";
    Day01 day;

    vector<string> testData = GetData("\\Day" + dayNumber + "\\Input" + dayNumber + ".txt");
    vector<string> inputData = GetData("\\Day" + dayNumber + "\\Test" + dayNumber + ".txt");   
    
    cout << "Day" + dayNumber << endl;

    day.data = testData;
    cout << "Part 1 test: " + to_string(day.partOne()) << endl;

    day.data = inputData;
    cout << "Part 1 answer: " + to_string(day.partOne()) << endl;

    day.data = testData;
    cout << "Part 2 test: " + to_string(day.partTwo()) << endl;

    day.data = inputData;
    cout << "Part 2 answer: " + to_string(day.partTwo()) << endl;
}

vector<string> GetData(string folder) {
    char NPath[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, NPath);
    string directory(NPath);
    ifstream testInput(directory + folder);
    int counter = 0;
    vector<string> inputData;
    string line;

    while (getline(testInput, line)) {
        inputData.push_back(line);
    }
    testInput.close();
    return inputData;
}


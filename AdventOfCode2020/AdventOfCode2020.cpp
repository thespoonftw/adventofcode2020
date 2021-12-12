
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include "Day01.h"
#include "Day02.h"
#include "Day03.h"
using namespace std;

int main()
{
    char NPath[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, NPath);
    string directory(NPath);
    cout << "Current working directory: " << directory << endl;
    ifstream testInput(directory + "\\Input\\Input03.txt");
    //ifstream testInput(directory + "\\Test\\Test03.txt");
    int counter = 0;
    vector<string> inputData;
    string line;

    while (getline(testInput, line)) {
        inputData.push_back(line);
    }
    testInput.close();

    Day03 day;
    day.data = inputData;
    cout << std::to_string(day.PartOne()) << endl;
    cout << std::to_string(day.PartTwo()) << endl;
}

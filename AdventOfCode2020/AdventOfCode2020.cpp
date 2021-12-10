#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
using namespace std;

int main()
{
    string line;
    ifstream testInput("C:\\Users\\Tablespoon\\source\\repos\\AdventOfCode2020\\AdventOfCode2020\\Input\\Input01.txt");

    int counter = 0;

    vector<int> myVector;

    while (getline(testInput, line)) {
        int value = stoi(line);
        myVector.push_back(value);
        counter += value;
        string str = std::to_string(counter);
        cout <<  + " " + str + "\n";
    }

    int numberOfEntries = myVector.size();

    for (int i = 0; i < numberOfEntries; i++) {
        int a = myVector.at(i);

        for (int j = 0; j < numberOfEntries; j++) {
            int b = myVector.at(j);

            if (a + b == 2020) {
                cout << std::to_string(a * b) + "\n";
            }
        }
    }

    for (int i = 0; i < numberOfEntries; i++) {
        int a = myVector.at(i);

        for (int j = 0; j < numberOfEntries; j++) {
            int b = myVector.at(j);

            for (int k = 0; k < numberOfEntries; k++) {
                int c = myVector.at(k);

                if (a + b + c == 2020) {
                    cout << std::to_string(a * b * c) + "\n";
                }
            }
        }
    }

    testInput.close();
}
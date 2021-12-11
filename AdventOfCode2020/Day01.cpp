
#include <string>
#include <vector>
#include "Day01.h"
using namespace std;

class Solver {
    public:
        void LoadData(vector<string> data);
        int FindFirstPair();
        int FindFirstTriplet();
    private:
        vector<int> numbers;
        int size;        
};

void Solver::LoadData(vector<string> data) {
    size = data.size();
    for (int i = 0; i < size; i++) {
        numbers.push_back(stoi(data.at(i)));
    }
}

int Solver::FindFirstPair() {
    for (int i = 0; i < size; i++) {
        int a = numbers.at(i);

        for (int j = 0; j < size; j++) {
            int b = numbers.at(j);

            if (a + b == 2020) {
                return a * b;
            }
        }
    }
    return 0;
}

int Solver::FindFirstTriplet() {
    for (int i = 0; i < size; i++) {
        int a = numbers.at(i);

        for (int j = 0; j < size; j++) {
            int b = numbers.at(j);

            for (int k = 0; k < size; k++) {
                int c = numbers.at(k);

                if (a + b + c == 2020) {
                    return a * b * c;
                }
            }
        }
    }
    return 0;
}


int Day01::PartOne() {
    Solver solver;
    solver.LoadData(data);
    return solver.FindFirstPair();
}

int Day01::PartTwo() {
    Solver solver;
    solver.LoadData(data);
    return solver.FindFirstTriplet();
}





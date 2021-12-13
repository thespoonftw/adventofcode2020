
#include <string>
#include <vector>
#include "../DayBase.h"
using namespace std;

class Solver {
    public:
        void loadData(vector<string> data);
        int findFirstPair();
        int findFirstTriplet();
    private:
        vector<int> numbers;
        int size = 0;        
};

void Solver::loadData(vector<string> data) {
    size = data.size();
    for (int i = 0; i < size; i++) {
        numbers.push_back(stoi(data.at(i)));
    }
}

int Solver::findFirstPair() {
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

int Solver::findFirstTriplet() {
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

int Day01::partOne() {
    Solver solver;
    solver.loadData(data);
    return solver.findFirstPair();
}

int Day01::partTwo() {
    Solver solver;
    solver.loadData(data);
    return solver.findFirstTriplet();
}





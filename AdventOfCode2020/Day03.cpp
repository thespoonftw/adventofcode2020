
#include <string>
#include <vector>
#include "Day03.h"
using namespace std;

class TreeMap {
    public:
        void LoadData(vector<string> data);
        int GetNumberOfTrees(int dx, int dy);
    private:
        bool treeArray[32][512];
        int width;
        int height;
};

void TreeMap::LoadData(vector<string> data) {
    width = data.at(0).length();
    height = data.size();
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            char character = data.at(y).at(x);
            if (character == '#') {
                treeArray[x][y] = true;
            } else {
                treeArray[x][y] = false;
            }
        }
    }
}

int TreeMap::GetNumberOfTrees(int dx, int dy) {
    int x = 0;
    int y = 0;
    int counter = 0;
    for (int y = 0; y < height; y += dy) {
        if (treeArray[x][y]) { counter++; }
        x += dx;
        if (x >= width) { x -= width; }
    }
    return counter;
}

// its 1 higher than i should be and i have no clue why

int Day03::PartOne() {
    TreeMap treeMap;
    treeMap.LoadData(data);
    return treeMap.GetNumberOfTrees(3, 1);
}

int Day03::PartTwo() {
    TreeMap treeMap;
    treeMap.LoadData(data);
    int a = treeMap.GetNumberOfTrees(1, 1);
    int b = treeMap.GetNumberOfTrees(3, 1);
    int c = treeMap.GetNumberOfTrees(5, 1);
    int d = treeMap.GetNumberOfTrees(7, 1);
    int e = treeMap.GetNumberOfTrees(1, 2);
    return a * b * c * d * e;
}





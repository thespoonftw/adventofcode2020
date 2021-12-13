
#include <string>
#include <vector>
#include "../DayBase.h"
using namespace std;

class TreeMap {
    public:
        void loadData(vector<string> data);
        int getNumberOfTrees(int dx, int dy);
    private:
        bool treeArray[32][512];
        int width;
        int height;
};

void TreeMap::loadData(vector<string> data) {
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

int TreeMap::getNumberOfTrees(int dx, int dy) {
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

int Day03::partOne() {
    TreeMap treeMap;
    treeMap.loadData(data);
    return treeMap.getNumberOfTrees(3, 1);
}

int Day03::partTwo() {
    TreeMap treeMap;
    treeMap.loadData(data);
    int a = treeMap.getNumberOfTrees(1, 1);
    int b = treeMap.getNumberOfTrees(3, 1);
    int c = treeMap.getNumberOfTrees(5, 1);
    int d = treeMap.getNumberOfTrees(7, 1);
    int e = treeMap.getNumberOfTrees(1, 2);
    return a * b * c * d * e;
}





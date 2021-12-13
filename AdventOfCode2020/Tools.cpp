#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

template <typename Out>
void splitString(const string& s, char delim, Out result) {
    istringstream iss(s);
    string item;
    while (getline(iss, item, delim)) {
        *result++ = item;
    }
}

vector<string> splitString(const string& s, char delim) {
    vector<string> elems;
    splitString(s, delim, back_inserter(elems));
    return elems;
}

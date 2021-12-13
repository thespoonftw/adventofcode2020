#include <string>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

template <typename Out>
void splitString(const string& s, char delim, Out result);
vector<string> splitString(const string& s, char delim);

#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include "../DayBase.h"
//#include "Tools.h"
using namespace std;

class Passport {
    public:
        string byr;
        string iyr;
        string eyr;
        string hgt;
        string hcl;
        string ecl;
        string pid;
        string cid;
        void addLineToPassport(string line);
    private:
        
};

class Passports {
    public:
        int getNumberOfValidPassports(bool isPartOne);
        void loadData(vector<string> data);
    private:
        vector<Passport> passportVector;
        bool isValidPassportOne(Passport passport);
        bool isValidPassportTwo(Passport passport);
};


void Passports::loadData(vector<string> data) {

    Passport firstPassport;
    Passport * currentPassport = &firstPassport;

    for (int i = 0; i < data.size(); i++) {
        if (data[i].size() == 0) {
            passportVector.push_back(*currentPassport);
            Passport newPassport;
            currentPassport = &newPassport;
        
        } else {
            currentPassport->addLineToPassport(data[i]);
        }
        
    }

    passportVector.push_back(*currentPassport);
}

//vector<string> splitString(const string& s, char delim);

// this needs moving to the tools class
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

void Passport::addLineToPassport(string line) {
    vector<string> split = splitString(line, ' ');
    for (int i = 0; i < split.size(); i++) {
        string item = split.at(i);
        int colonIndex = item.find(':');
        string type = item.substr(0, colonIndex);
        string value = item.substr(colonIndex + 1, item.size());
        if (type == "byr") {
            byr = value;
        } else if (type == "iyr") {
            iyr = value;
        } else if (type == "eyr") {
            eyr = value;
        } else if (type == "hgt") {
            hgt = value;
        } else if (type == "hcl") {
            hcl = value;
        } else if (type == "ecl") {
            ecl = value;
        } else if (type == "pid") {
            pid = value;
        } else if (type == "cid") {
            cid = value;
        }
    }
}

int Passports::getNumberOfValidPassports(bool isPartOne) {
    int counter = 0;
    for (int i = 0; i < passportVector.size(); i++) {
        Passport p = passportVector.at(i);
        if ((isPartOne && isValidPassportOne(p)) || (!isPartOne && isValidPassportTwo(p))) {
            counter++; 
        }
    }
    return counter;
}


bool Passports::isValidPassportOne(Passport p) {
    return p.byr != "" && p.iyr != "" && p.eyr != "" && p.hgt != "" && p.hcl != "" && p.ecl != "" && p.pid != "";
}

bool Passports::isValidPassportTwo(Passport p) {
    try {
        if (p.byr.size() != 4) { return false; }
        int byr = stoi(p.byr);
        if (byr < 1920 || byr > 2002) { return false; }

        if (p.iyr.size() != 4) { return false; }
        int iyr = stoi(p.iyr);
        if (iyr < 2010 || iyr > 2020) { return false; }

        if (p.eyr.size() != 4) { return false; }
        int eyr = stoi(p.eyr);
        if (eyr < 2020 || eyr > 2030) { return false; }

        if (p.hgt.size() < 4) { return false; }
        string suffix = p.hgt.substr(p.hgt.size() - 2, p.hgt.size());
        if (suffix != "cm" && suffix != "in") { return false; }
        int value = stoi(p.hgt.substr(0, p.hgt.size() - 2));
        if (suffix == "cm" && (value < 150 || value > 193)) { return false; }
        if (suffix == "in" && (value < 59 || value > 76)) { return false; }

        if (p.hcl.size() != 7) { return false; }
        if (p.hcl.at(0) != '#') { return false; }

        if (p.ecl != "amb" && p.ecl != "blu" && p.ecl != "brn" && p.ecl != "gry" && p.ecl != "grn" && p.ecl != "hzl" && p.ecl != "oth") { return false; }

        if (p.pid.size() != 9) { return false; }
        for (int i = 0; i < p.pid.size(); i++) {
            char c = p.pid.at(i);
            if (c != 'a' && c != 'b' && c != 'c' && c != 'e' && c != 'f' &&
                c != '0' && c != '1' && c != '2' && c != '3' && c != '4' &&
                c != '5' && c != '6' && c != '7' && c != '8' && c != '9') {
                return false;
            }
        }
        int pid = stoi(p.pid);


    } catch (...) {
        return false;
    }
    


    return true;
}

int Day04::partOne() {
    Passports passports;
    passports.loadData(data);
    return passports.getNumberOfValidPassports(true);
}

int Day04::partTwo() {
    Passports passports;
    passports.loadData(data);
    return passports.getNumberOfValidPassports(false);
}








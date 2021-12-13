#include <vector>
#include <string>
using namespace std;

class DayBase {
	public: 
		vector<string> data;
		virtual int partOne(void) = 0;
		virtual int partTwo(void) = 0;
};

class Day01 : public DayBase {
	public:
		int partOne(void);
		int partTwo(void);
};

class Day02 : public DayBase {
	public:
		int partOne(void);
		int partTwo(void);
};

class Day03 : public DayBase {
	public:
		int partOne(void);
		int partTwo(void);
};

class Day04 : public DayBase {
	public:
		int partOne(void);
		int partTwo(void);
};

class Day05 : public DayBase {
	public:
		int partOne(void);
		int partTwo(void);
};

class Day06 : public DayBase {
	public:
		int partOne(void);
		int partTwo(void);
};

class Day07 : public DayBase {
	public:
		int partOne(void);
		int partTwo(void);
};

class Day08 : public DayBase {
	public:
		int partOne(void);
		int partTwo(void);
};

class Day09 : public DayBase {
	public:
		int partOne(void);
		int partTwo(void);
};

class Day10 : public DayBase {
	public:
		int partOne(void);
		int partTwo(void);
};
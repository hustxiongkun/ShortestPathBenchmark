#ifndef BENCHMARKSPECIFICATION_TEST_TOOLS_H_
#define BENCHMARKSPECIFICATION_TEST_TOOLS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

//check rc is right or abort
/*
#define check(rc, msg)											\
	{															\
		if(!(rc)){												\
			std::cerr << __FILE__ ":" << __LINE__ << ": error: "\
					<< msg << std::endl;						\
			abort();											\
		}else {}												\
	}*/
void check(bool rc, std::string msg);

//struct for vertex in adjList
struct adjVertex {
	int sinkVertex;
	double arcWeight;
	adjVertex(int sinkVertex, double arcWeight):
		sinkVertex(sinkVertex),arcWeight(arcWeight){}
};

//struct for samples
struct InputData {
	std::string name;
	std::string comment;
	std::string type;
	int vcnt;
	int ecnt;
	std::vector<std::vector<adjVertex > > adjList;//
	std::vector<std::vector<double> > adjMatrix;//
	int source;
	int target;
};
//struct for point
struct Point {
	double x;
	double y;
	Point(double x, double y):x(x),y(y){}
};
//delete both two sides' blank of string
std::string& trim(std::string &str);
//split string with delimiter
void split(const std::string &str, const char delimiter, std::vector<std::string>& result);
//distance of two points
double distance2D(const Point &point1, const Point &point2);
// for input sample instance
void input(const std::string& inFileName, InputData *data);
//class for time
class Timer {
public:
	void start();
	double currentTime();
	double timeUsed();
private:
	double mStart;
	double mCurrentTime;
	double mUsed;
};
#endif // !BENCHMARKSPECIFICATION_TEST_TOOLS_H_

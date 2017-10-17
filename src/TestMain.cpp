#include <cstdio>
#include <iostream>

#include "test_tools.h"
#include "test_A.h"

int main(int argc, char* argv[]) {
	using namespace std;

	InputData data;
	Timer timer;

	//input sample data
	input("../../../data/big/u1060.tsp", &data);

	//set source, target
	data.source = 0;
	data.target = 5;

	cout << data.name << endl;
	cout << data.comment << endl;
	cout << data.type << endl;

	//start test
	timer.start();
	test_A(data);
	cout << "A used time: " << timer.timeUsed() << endl;

    return 0;
}
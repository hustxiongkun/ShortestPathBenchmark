#include "test_tools.h"

#include <ctime>

const int INF = 0xFFFFFFF;

void check(bool rc, std::string msg){
	if (!rc) {
		std::cerr << __FILE__":" << __FILE__ << ": error: " << msg << std::endl;
		abort();
	}
	else {}
}

std::string& trim(std::string &str) {
	if (str == "") return str;
	str.erase(str.begin(), str.begin() + str.find_first_not_of(" \t\r"));
	str.erase(str.find_last_not_of(" \t\r") + 1);
	return str;
}

void split(const std::string &str, const char delimiter, std::vector<std::string>& result) {
	auto pos1 = 0;
	auto pos2 = 0;
	while (pos1 != (pos2 = str.find(delimiter, pos2)) && pos2 != std::string::npos) {
		std::string temp = str.substr(pos1, pos2 - pos1);
		result.push_back(trim(temp));
		pos1 = pos2 = str.find_first_not_of(delimiter, pos2);
	}
	result.push_back(trim(str.substr(pos1)));
}

double distance2D(const Point &point1, const Point &point2) {
	double dx = point2.x - point1.x;
	double dy = point2.y - point1.y;
	return sqrt(dx*dx + dy*dy);
}

void input(const std::string& inFileName, InputData *data) {
	std::ifstream fin(inFileName);
	std::string line;
	if (!fin) return;
	bool inputVertex = false;
	bool useAdjList = true;
	std::vector<Point> points;

	bool directed = false;
	int count = 0;

	while (getline(fin, line)) {
		std::vector<std::string> words;
		count++;
		if (inputVertex && line != "EOF") {
			//data
			split(trim(line), ' ', words);
			if (useAdjList) {

			}
			else {
				check(words.size() == 3, "输入格式有错" + count);
				points.push_back(Point(atof(words[1].c_str()), atof(words[2].c_str())));
			}
		}
		else {
			//specification
			split(trim(line), ':', words);
			if (words[0] == "NAME") data->name = words[1];
			if (words[0] == "COMMENT") data->comment = words[1];
			if (words[0] == "TYPE") data->type = words[1];
			if (words[0] == "DIMENSION") data->vcnt = atoi(words[1].c_str());
			if (words[0] == "EDGE_WEIGHT_TYPE" &&
				(words[1] == "EUC_2D" || words[1] == "CEIL_2D")) useAdjList = false;
			if (words[0] == "NODE_COORD_SECTION") inputVertex = true;
		}
	}
	if (useAdjList) {

	}
	else {
		int n = data->vcnt;
		check(n == points.size(), "输入点数不符合");
		data->ecnt = n*(n - 1);//WARNING: maybe overflow
		//save data as adjMatrix
		data->adjMatrix.resize(n, std::vector<double>(n));
		//save data as adjList
		data->adjList.resize(n, std::vector<adjVertex>());
		for (auto i = 0; i < n; i++) {
			data->adjMatrix[i][i] = 0;
			/*data->adjList[i][i].sinkVertex = i;
			data->adjList[i][i].arcWeight = INF;*/
			for (auto j = i + 1; j < n; j++) {
				data->adjMatrix[i][j] = distance2D(points[i], points[j]);//too slow
				data->adjList[i].push_back(adjVertex(j, data->adjMatrix[i][j]));
				if (!directed) {
					data->adjMatrix[j][i] = data->adjMatrix[i][j];
					data->adjList[j].push_back(adjVertex(i, data->adjMatrix[i][j]));
				}
			}
		}
	}
	fin.close();
}

void Timer::start() {
	mStart = clock();
}
double Timer::currentTime() {
	mCurrentTime = clock();
	return mCurrentTime;
}
double Timer::timeUsed() {
	mCurrentTime = clock();
	return (mCurrentTime - mStart) / CLOCKS_PER_SEC;
}
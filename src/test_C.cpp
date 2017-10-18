#include "test_C.h"

#include <algorithm/Graph.h>

void test_C(const InputData& data) {
	using namespace std;
	using namespace szx;

	using ID = int;
	using COORD = double;
	using Weight = double;
	using Capacity = int;

	using Network = TopologicalGraph<ID, Weight, Capacity>;
	using UNetwork = UndirectedGraph<ID, Weight, Capacity>;
	using DNetwork = DirectedGraph<ID, Weight, Capacity>;

	vector<Network::Edge> edges;
	for (ID i = 0; i < data.vcnt; i++) {
		for (ID j = 0; j < data.vcnt; j++) {
			if(i == j) continue;
			edges.push_back(Network::Edge{ i,j,data.adjMatrix[i][j] });
		}
	}
	Network::AdjList adjList(UNetwork::toAdjList<vector>(edges, data.vcnt));

	Timer timer;

	//single to single
	//support step by step
	timer.start();
	DNetwork::ShortestPath::Dijkstra dijkstra(adjList, data.source);
	Network::Path path;
	if (dijkstra.findPointToPointPath(data.target)) {
		path = dijkstra.getPath(data.target);
	}
	//dijkstra.next([&](ID) {return dijkstra.getLastNode() == data.target; });
	//cout << dijkstra.getDist(data.target) << endl;
	cout << "C single to single used time: " << timer.timeUsed() << endl;

	/*// single to all
	timer.start();
	DNetwork::ShortestPath::Dijkstra dijkstra(adjList, data.source);
	vector<Network::Path> path(data.vcnt);
	dijkstra.findSingleSourcePaths();
	for (int i = 0; i < data.vcnt; i++) {
		path[i] =  dijkstra.getPath(i);
	}
	cout << "C single to all used time: " << timer.timeUsed() << endl;

	// all to all
	timer.start();
	DNetwork::ShortestPath::Dijkstra dijkstra(adjList, data.source);
	vector<vector< Network::Path>> path(data.vcnt,vector<Network::Path>(data.vcnt));
	for (int i = 0; i < data.vcnt; i++) {
		dijkstra.reset(i);
		dijkstra.findSingleSourcePaths();
		for (int j = 0; j < data.vcnt; j++) {
			path[i][j] = dijkstra.getPath(j);
		}
	}
	cout << "C all to all used time: " << timer.timeUsed() << endl;*/
}
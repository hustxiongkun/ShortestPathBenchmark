#include "test_A.h"
#include "test_tools.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <lemon/list_graph.h>
#include <lemon/dijkstra.h>
#include <lemon/concepts/digraph.h>


void test_A(const InputData& data) {
	using namespace lemon;
	using namespace std;
	/* graph */
	typedef ListDigraph::Node Node;
	typedef ListDigraph::Arc Arc;
	typedef ListDigraph::ArcMap<double> LengthMap;

	ListDigraph G;
	vector<Node> nodes;
	for (int i = 0; i < data.vcnt; i++) {
		nodes.push_back(G.addNode());
	}
	LengthMap length(G);
	for (int i = 0; i < data.adjList.size(); i++) {
		for (int j = 0; j < data.adjList[i].size(); j++) {
			Arc a = G.addArc(nodes[i], nodes[data.adjList[i][j].sinkVertex]);
			length[a] = data.adjList[i][j].arcWeight;
		}
	}
	//set source, target
	Node source, target;
	source = nodes[data.source];
	target = nodes[data.target];

	Timer timer;
	
	//single to single
	timer.start();
	Dijkstra<ListDigraph,LengthMap> dijkstra(G, length);
	dijkstra.init();
	dijkstra.addSource(source);
	dijkstra.start(target);
	Path<ListDigraph> path = dijkstra.path(target);
	cout << "A single to single used time: " << timer.timeUsed() << endl;

	/*//single to all
	Dijkstra<ListDigraph, LengthMap> dijkstra(G, length);
	dijkstra.init();
	dijkstra.addSource(source);
	dijkstra.start();
	vector<Path<ListDigraph>> path;
	for(int i = 0; i < nodes.size(); i++){
		if(i == data.source) continue;
		path[i] = dijkstra.path(nodes[i]);
	}

	//all to all
	Dijkstra<ListDigraph, LengthMap> dijkstra(G, length);
	vector<vector<Path<ListDigraph>>> path;
	for (int i = 0; i < nodes.size(); i++) {
		dijkstra.init();
		dijkstra.addSource(nodes[i]);
		dijkstra.start();
		for(int j = 0; j < nodes.size(); j++){
			if(i == j) continue;
			path[i][j] = dijkstra.path(nodes[j]);
		}
	}*/
}

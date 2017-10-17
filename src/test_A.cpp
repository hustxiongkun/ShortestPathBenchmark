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
			Arc a = G.addArc(nodes[i], nodes[data.adjList[i][j].first]);
			length[a] = data.adjList[i][j].second;
		}
	}
	//set source, target
	Node s, t;
	s = nodes[data.source];
	t = nodes[data.target];

	Timer timer;
	
	//single to single
	Dijkstra<ListDigraph,LengthMap> dijkstra(G, length);
	dijkstra.init();
	timer.start();
	dijkstra.addSource(s);
	dijkstra.start(t);
	cout << "A single to single used time: " << timer.timeUsed() << endl;

	/*//single to all
	Dijkstra<ListDigraph, LengthMap> dijkstra(G, length);
	dijkstra.init();
	dijkstra.addSource(s);
	dijkstra.start();

	//all to all
	Dijkstra<ListDigraph, LengthMap> dijkstra(G, length);
	for (int i = 0; i < nodes.size(); i++) {
		dijkstra.init();
		dijkstra.addSource(nodes[i]);
		dijkstra.start();
	}*/
}

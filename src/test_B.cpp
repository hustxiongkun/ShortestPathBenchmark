#include "test_B.h"
#include "test_tools.h"
#include <StaticNet.h>
#include <DijkSolver.h>

using namespace Cgc;

class NodeType
{
public:
	// required for construction.
	NodeType()
		:cost(0),
		backId(0)
	{ }
	// This is required by DijkSolver.  It sets the cost and predecessor.
	void setLabel(int pathCost, NodeId prevNode)
	{
		cost = pathCost;
		backId = prevNode;
	}
	// Returns the current cost of the node. Required by DijkSolver.
	int getLabel()const
	{
		return cost;
	}

	// Returns the current predecessor of the node. Required by DijkSolver.
	NodeId getPred()const
	{
		return backId;
	}
private:
	// Storage for the cost and back pointer "label".
	int cost;
	NodeId backId;
	// Some handy friend and forward declarations.
	friend std::ostream &operator<<(std::ostream &os, const NodeType &nt);
	// This method is required for DijkSolver to compare labels.
	friend bool operator>(const NodeType &node1, const NodeType &node2);
};

// method compares two labels.  This is required for DijkSolver
bool operator>(const NodeType &node1, const NodeType &node2)
{
	return node1.cost > node2.cost;
}

// handy print.  It is used later in the network print operator<<
std::ostream &operator<<(std::ostream &os, const NodeType &nt)
{
	return os << " Cost=" << nt.cost << " and prevNode=" << nt.backId;
}

class ArcType
{
public:
	ArcType(double inCost)
		:cost(inCost)
	{ }

	ArcType() :cost(0) { }

	/* This method allows one to selectively and non-destructively
	turn on and off arcs in the graph.  If the method returns "false" then
	DijkSolver will ignore that arc.
	This version of DijkSolver requires it.
	This kind of capability is useful if one wishes to frequently
	perturb the graph and re-solve.
	Note: One can simulate a Node on/off by turning off all arcs
	leading into that node.  This is left as an exercise.
	*/
	bool valid()const
	{
		return true;
	}
	// returns the cost of the arc.
	double getCost()const
	{
		return cost;
	}
private:
	double cost;
	// useful print used later.  Not strictly required by DijkSolver.
	friend std::ostream &operator<<(std::ostream &os, const ArcType &nt);
};

// print used later.
std::ostream &operator<<(std::ostream &os, const ArcType &nt)
{
	return os << " arc cost:" << nt.cost << ' ';
}

void test_B(const InputData& data) {
	using namespace std;
	using namespace Cgc;

	typedef StaticNet<NodeType, ArcType> MyNet;
	typedef DijkSolver<MyNet, MyNet::iterator> MySolver;

	/*graph*/
	MyNet net(data.vcnt, data.ecnt);
	vector<MyNet::iterator> nodes;
	for (int i = 0; i < data.vcnt; i++) {
		nodes.push_back(net.insert(NodeType()));
	}
	for (int i = 0; i < data.adjList.size(); i++) {
		for (int j = 0; j < data.adjList[i].size(); j++) {
			net.arc_insert(nodes[i], data.adjList[i][j].arcWeight, nodes[data.adjList[i][j].sinkVertex]);
		}
	}

	//set source and target
	MyNet::iterator source = nodes[data.source];
	MyNet::iterator target = nodes[data.target];

	Timer timer;

	//single to single
	//not supported
	/*timer.start();
	MySolver solver;
	Path path;
	solver.solve(net, source);
	solver.getPath(net, target, path);
	cout << "B single to single used time: " << timer.timeUsed() << endl;*/

	//single to all
	timer.start();
	MySolver solver;
	vector<Path> path(data.vcnt);
	solver.solve(net, source);

	for (int i = 0; i < data.vcnt; i++) {
		if(i == data.source) continue;
		solver.getPath(net, nodes[i], path[i]);
	}
	cout << "B single to all used time: " << timer.timeUsed() << endl;
	
	/*//all to all
	timer.start();
	MySolver solver;
	vector<vector<Path>> path(data.vcnt, vector<Path>(data.vcnt));

	for (int i = 0; i < data.vcnt; i++) {
		solver.solve(net, nodes[i]);
		for (int j = 0; j < data.vcnt; j++) {
			if(i == j) continue;
			solver.getPath(net, nodes[j], path[i][j]);
		}
	}
	cout << "B all to all used time: " << timer.timeUsed() << endl;*/
}
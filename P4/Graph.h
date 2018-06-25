#pragma once
#include <vector>
#include "GraphNode.h"
using namespace std;


class Graph
{
private:

public:
	int numNodes;
	bool weighted;
	bool directed;
	vector<GraphNode> nodes;
	void internal_t(int k);
	void internal_b(int s);
	Graph(bool w = false, bool d = false) { weighted = w; directed = d; numNodes = 0; }
	void addNode(GraphNode node);
	vector<edge> adj(int v);
	vector<edge> edges();
	bool init(string p);
	void print();
	bool tiefensuche();
	bool breitensuche();
	double prim(int s);
	double kruskal();
};
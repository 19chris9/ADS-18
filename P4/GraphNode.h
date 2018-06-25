#pragma once
#include <vector>
using namespace std;

struct edge;

class GraphNode
{

public:
	int key;
	bool visited;
	double distance;
	vector<edge> edges;
	GraphNode() { visited = false; };
	friend class Graph;
};

struct edge {
	GraphNode *anfang;
	GraphNode *ziel;
	double weight;
	bool visited;
	bool operator<(const edge& comp) const
	{
		return weight > comp.weight;
	}
};


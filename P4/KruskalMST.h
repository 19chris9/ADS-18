#pragma once
#include <queue>
#include <vector>
#include "GraphNode.h"
#include "Graph.h"



class KruskalMST {

public:
	queue<edge> mst;
	vector<int> marked;
	KruskalMST(Graph G);
	queue<edge> edges();
	double weight; 
};

#pragma once
#include <queue>
#include <vector>
#include "GraphNode.h"
#include "Graph.h"



class PrimMST {
private:

public:
	vector<bool> marked; // MST-Knoten
	queue<edge> mst; // MST-Kanten
	priority_queue<edge> pq; // Menge der Randkanten in PQ
	PrimMST(Graph G, int s);
	void visit(Graph G, int v);
	queue<edge> edges() {
		return mst;
	}
	double weight() {
	}
};
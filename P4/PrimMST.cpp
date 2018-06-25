#include "PrimMST.h"

PrimMST::PrimMST(Graph G, int s)
{
	marked.resize(G.nodes.size());
	for (int i = 0; i < marked.size(); i++)
		marked[i] = false;
	visit(G, s);
	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();
		int v = e.anfang->key;
		int w = e.ziel->key;

		if (marked[v] && marked[w]) continue;

		mst.push(e);
		if (!marked[v]) visit(G, v);
		if (!marked[w]) visit(G, w);
	}
}

void PrimMST::visit(Graph G, int v)
{
	marked[v] = true;
	vector<edge> edges = G.adj(v);
	for (int i = 0; i < edges.size(); i++) {
		if (!marked[edges[i].ziel->key]) pq.push(edges[i]);
	}
}

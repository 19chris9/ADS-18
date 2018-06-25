#include "KruskalMST.h"

KruskalMST::KruskalMST(Graph G)
{
	weight = 0.0;
	marked.resize(G.numNodes);
	priority_queue<edge> pq;
	vector<edge> e = G.edges();
	for (int i = 0; i < e.size(); i++) pq.push(e[i]);
	for (int i = 0; i < marked.size(); i++) marked[i] = i;

	while (!pq.empty()) {
		edge f = pq.top();
		pq.pop();
		int v = f.anfang->key;
		int w = f.ziel->key;
		if (marked[v] != marked[w]) {
			mst.push(f);
			weight += f.weight;
			for (int i = 0; i < G.numNodes; i++) {
				if (marked[i] == marked[w]) {
					marked[i] = marked[v];
				}
			}
		}
	}
}

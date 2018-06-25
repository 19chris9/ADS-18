#include "Graph.h"
#include "GraphNode.h"
#include "PrimMST.h"
#include "KruskalMST.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <queue>
#include <limits>

using namespace std;

void Graph::internal_t(int k)
{
	nodes[k].visited = true;
	for (int i = 0; i < nodes[k].edges.size(); i++) {
		if (!nodes[k].edges[i].ziel->visited) {
			int temp = nodes[k].edges[i].ziel->key;
			internal_t(temp);
		}
	}
}

void Graph::internal_b(int s)
{
	queue<int> q;
	q.push(s);
	nodes[s].visited = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < nodes[v].edges.size(); i++) {
			if (!nodes[v].edges[i].ziel->visited) {
				nodes[v].edges[i].ziel->visited = true;
				q.push(nodes[v].edges[i].ziel->key);
			}
		}
	}
}

void Graph::addNode(GraphNode node)
{
	numNodes++;
	nodes.push_back(node);
}

vector<edge> Graph::adj(int v)
{
	vector<edge> e;
	for (int i = 0; i < nodes[v].edges.size(); i++)
	{
		e.push_back(nodes[v].edges[i]);
	}
	return e;
}

vector<edge> Graph::edges()
{
	for (int i = 0; i < nodes.size(); i++)
		for (int z = 0; z < nodes[i].edges.size(); z++)
			nodes[i].edges[z].visited = false;

	vector<edge> e;
	for (int i = 0; i < nodes.size(); i++)
		for (int z = 0; z < nodes[i].edges.size(); z++)
			if (!nodes[i].edges[z].visited) {
				e.push_back(nodes[i].edges[z]);
				nodes[i].edges[z].visited = true;
				for (int x = 0; x < nodes[nodes[i].edges[z].ziel->key].edges.size(); x++) {
					if (nodes[nodes[i].edges[z].ziel->key].edges[x].ziel == nodes[i].edges[z].anfang)
						nodes[nodes[i].edges[z].ziel->key].edges[x].visited = true;
				}
			}
	return e;
}

bool Graph::init(std::string path) {
	std::ifstream file;
	file.open(path, ios::in);
	if (!file) {
		std::cout << "Cannot open file." << std::endl;
		return false;
	}
	else {
		int anzKnoten;
		std::string line;
		std::getline(file, line);
		std::istringstream iss(line);
		//Erste Zeile Auslesen
		iss >> anzKnoten;
		//Alle Knoten anlegen
		for (int i = 0; i < anzKnoten; i++) {
			GraphNode temp;
			temp.key = i;
			this->addNode(temp);
		}
		//Alle Kanten anlegen
		while (std::getline(file, line)) {
			int start, end, w;
			std::istringstream iss(line);
			iss >> start;
			iss >> end;
			iss >> w;
			edge temp1, temp2;
			temp1.weight = w;
			temp1.anfang = &nodes[start];
			temp1.ziel = &nodes[end];
			nodes[start].edges.push_back(temp1);
			temp2.weight = w;
			temp2.anfang = &nodes[end];
			temp2.ziel = &nodes[start];
			nodes[end].edges.push_back(temp2);
		}
		return true;
	}
	return false;
}

void Graph::print()
{
	for (int i = 0; i < numNodes; i++) {
		cout << nodes[i].key;
		for (int z = 0; z < nodes[i].edges.size(); z++)
		{
			cout << " ";
			cout << nodes[i].edges[z].ziel->key;
		}
		cout << endl;
	}
}

bool Graph::tiefensuche()
{
	for (int i = 0; i < numNodes; i++)
		nodes[i].visited = false;
	int k = 0;
	internal_t(k);

	for (int i = 0; i < numNodes; i++)
		if (!nodes[i].visited)
			return false;
	return true;
}

bool Graph::breitensuche()
{
	for (int i = 0; i < numNodes; i++)
		nodes[i].visited = false;
	internal_b(0);
	
	for (int i = 0; i < numNodes; i++)
		if (!nodes[i].visited)
			return false;
	return true;
}



double Graph::prim(int s)
{
	double result = 0.0;
	Graph g = *this;
	PrimMST m(g, s);
	int end = m.mst.size();
	for (int i = 0; i < end; i++)
	{
		result += m.mst.front().weight;
		m.mst.pop();
	}

	return result;
}

double Graph::kruskal()
{
	double result = 0.0;
	Graph g = *this;
	KruskalMST m(g);
	result = m.weight;

	return result;
}



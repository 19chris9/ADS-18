#pragma once
#include <string>

using namespace std;


class TreeNode
{
private:
	int NodePosID, NodeID, alter, PLZ;
	string name;
	double einkommen;
	TreeNode *left;
	TreeNode *right;

public:
	TreeNode(string n, int a, double e, int p);
	string getName() { return name; }
	int getAlter() { return alter; }
	double getEinkommen() { return einkommen; }
	int getPLZ() { return PLZ; }
	void setname(string n) { name = n; }
	void setAlter(int a) { alter = a; }
	void setEinkommen(int e) { einkommen = e; }
	void setPLZ(int p) { PLZ = p; }
	void printData();
	friend class Tree;

};
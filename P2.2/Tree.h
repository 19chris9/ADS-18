#pragma once
#include "TreeNode.h"


class Tree
{
private:
	TreeNode * anker;
	void printinternal(TreeNode *node);
	void searchinternal(TreeNode *node, string n);
	TreeNode* leftmost(TreeNode *node);
	void clearleft(TreeNode *node);
public:
	Tree() { anker = nullptr; }
	void add(string n, int a, double e, int p);
	void print();
	void search(string n);
	void del(int pos);
};
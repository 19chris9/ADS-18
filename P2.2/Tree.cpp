#include "Tree.h"
#include <iostream>

void Tree::printinternal(TreeNode *node)
{
	if (node != nullptr) {
		string s;
		cout << node->NodeID;
		s = to_string(node->NodeID);
		for (int i = 3; i >= s.length(); i--)
			cout << " ";
		cout << "|";
		for (int i = 19; i >= node->name.length(); i--)
			cout << " ";
		cout << node->name;
		cout << "|"; 
		s = to_string(node->alter);
		for (int i = 6; i >= s.length(); i--)
			cout << " ";
		cout << node->alter;
		cout << "|";
		int temp = node->einkommen;
		s = to_string(temp);
		for (int i = 10; i >= s.length(); i--)
			cout << " ";
		cout << node->einkommen;
		cout << "|";
		s = to_string(node->PLZ);
		for (int i = 8; i >= s.length(); i--)
			cout << " ";
		cout << node->PLZ << "|" << node->NodePosID << endl;
		printinternal(node->left);
		printinternal(node->right);
	}
}

void Tree::searchinternal(TreeNode * node, string n)
{
	if (node != nullptr) {
		if (node->name == n)
			cout << "NodeID: " << node->NodeID << ", Name: " << node->name << ", Alter: " << node->alter << ", Einkommen: " << node->einkommen << ", PLZ: " << node->PLZ << ", PosID: " << node->NodePosID << endl;
		searchinternal(node->left, n);
		searchinternal(node->right, n);
	}
}

TreeNode* Tree::leftmost(TreeNode * node)
{
	while (node->left != nullptr)
		node = node->left;
	return node;
}

void Tree::clearleft(TreeNode * node)
{
	if (node->right == node)
		node->right = nullptr;
	else if (node->left == node)
		node->left = nullptr;
	else {
		TreeNode *orig = node;
		node = node->right;
		while (node->left != orig)
			node = node->left;
		node->left = nullptr;
	}
}

void Tree::add(string n, int a, double e, int p)
{
	static int count = 0;
	TreeNode *node = new TreeNode(n, a, e, p);
	count++;
	node->NodeID = count;

	if (anker == nullptr)
		anker = node;
	else {
		TreeNode *temp = anker;
		while (temp != nullptr)
			if (node->NodePosID < temp->NodePosID) {
				if (temp->left == nullptr) {
					temp->left = node;
					break;
				}
				temp = temp->left;
			}
			else {
				if (temp->right == nullptr) {
					temp->right = node;
					break;
				}
				temp = temp->right;
			}
				
	}
}

void Tree::print()
{
	TreeNode *temp = anker;
	cout << " ID | Name               | Alter | Einkommen |   PLZ   | Pos " << endl;
	cout << "----+--------------------+-------+-----------+---------+-----" << endl;
	printinternal(temp);
}

void Tree::search(string n)
{
	TreeNode *temp = anker;
	searchinternal(temp, n);
}

void Tree::del(int pos)
{
		if (anker == nullptr)
			cout << "Der Baum ist leer" << endl;
		else if (anker->NodePosID == pos) {
			if (anker->right == nullptr && anker->left == nullptr) {
				delete anker;
				anker = nullptr;
				cout << "Der Knoten wurde entfernt und der Baum ist nun leer" << endl;
			}
			else if (anker->left != nullptr && anker->right == nullptr) {
				TreeNode *delnode = anker;
				anker = anker->left;
				delete delnode;
				cout << "Der Knoten wurde entfernt" << endl;
			}
			else if (anker->left == nullptr && anker->right != nullptr) {
				TreeNode *delnode = anker;
				anker = anker->right;
				delete delnode;
				cout << "Der Knoten wurde entfernt" << endl;
			}
			else if (anker->left != nullptr && anker->right != nullptr) {
				TreeNode *delnode = anker;
				TreeNode *leftm = leftmost(anker->right);
				leftm->left = anker->left;
				leftm->right = anker->right;
				anker = leftm;
				delete delnode;
				clearleft(anker);
				cout << "Der Knoten wurde entfernt" << endl;
			}
		}
		else {
			TreeNode *temp = anker;
			while (temp != nullptr) {
				if (temp->left != nullptr && temp->left->NodePosID == pos) {
					TreeNode *delnode = temp->left;
					if (delnode->left == nullptr && delnode->right == nullptr) {
						temp->left = nullptr;
						delete delnode;
						cout << "Der Knoten wurde entfernt" << endl;
						break;
					}
					else if (delnode->left != nullptr && delnode->right == nullptr) {
						temp->left = delnode->left;
						delete delnode;
						cout << "Der Knoten wurde entfernt" << endl;
						break;
					}
					else if (delnode->left == nullptr && delnode->right != nullptr) {
						temp->left = delnode->right;
						delete delnode;
						cout << "Der Knoten wurde entfernt" << endl;
						break;
					}
					else if (delnode->left != nullptr && delnode->right != nullptr) {
						TreeNode* leftm = leftmost(delnode->right);
						leftm->left = delnode->left;
						leftm->right = delnode->right;
						temp->left = leftm;
						delete delnode;
						clearleft(leftm);
						cout << "Der Knoten wurde entfernt" << endl;
						break;
					}
				}
				else if (temp->right != nullptr && temp->right->NodePosID == pos) {
					TreeNode *delnode = temp->right;
					if (delnode->left == nullptr && delnode->right == nullptr) {
						temp->right = nullptr;
						delete delnode;
						cout << "Der Knoten wurde entfernt" << endl;
						break;
					}
					else if (delnode->left != nullptr && delnode->right == nullptr) {
						temp->right = delnode->left;
						delete delnode;
						cout << "Der Knoten wurde entfernt" << endl;
						break;
					}
					else if (delnode->left == nullptr && delnode->right != nullptr) {
						temp->right = delnode->right;
						delete delnode;
						cout << "Der Knoten wurde entfernt" << endl;
						break;
					}
					else if (delnode->left != nullptr && delnode->right != nullptr) {
						TreeNode* leftm = leftmost(delnode->right);
						leftm->left = delnode->left;
						leftm->right = delnode->right;
						temp->right = leftm;
						delete delnode;
						clearleft(leftm);
						cout << "Der Knoten wurde entfernt" << endl;
						break;
					}
				}



				if (temp->NodePosID > pos)
					temp = temp->left;
				else
					temp = temp->right;
				cout << "Der Knoten wurde nicht gefunden" << endl;
			}
		}
}

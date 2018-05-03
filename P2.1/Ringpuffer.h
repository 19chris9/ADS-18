#pragma once
#include "RingNode.h"


class RingPuffer
{
private:
	RingNode *anker;

public:
	RingPuffer();
	~RingPuffer();
	void addNode(string desc, string data);
	bool search(string data, RingNode &node);
	void print();

};


#include "RingNode.h"


RingNode::RingNode(string desc, string data)
{
	next = nullptr;
	description = desc;
	symbolicData = data;
	oldAge = 0;
}

RingNode::~RingNode()
{
	
}

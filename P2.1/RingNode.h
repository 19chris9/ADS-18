#pragma once
#include <string>

using namespace std;

class RingNode
{
private:
	int oldAge;
	string description;
	string symbolicData;
	RingNode *next;
public:
	RingNode(string desc, string data);
	~RingNode();
	int getAge() { return oldAge; }
	void setAge(int age) { oldAge = age; }
	string getDescription() { return description; }
	void setDescription(string desc) { description = desc; }
	string getData() { return symbolicData; }
	void setData(string data) { symbolicData = data; }
	friend class RingPuffer;
};

#include "Ringpuffer.h"
#include <iostream>

RingPuffer::RingPuffer()
{
	anker = nullptr;
}

RingPuffer::~RingPuffer()
{
}

void RingPuffer::addNode(string desc, string data)
{
	if (anker == nullptr) {
		anker = new RingNode(desc, data);
	}
	else {
		RingNode *node = new RingNode(desc, data);
		RingNode *temp = anker;
		if (anker->next == nullptr) {
			anker->oldAge++;
		}
		else {
			while (temp->next != anker) {
				temp->oldAge++;
				temp = temp->next;
			}
		}


		if (anker->next == nullptr) {
			anker->next = node;
			node->next = anker;
			anker = node;
		}
		else {
			if (anker->next->oldAge == 6) {
				RingNode *temp2 = anker->next;
				anker->next = temp2->next;
				delete temp2;
			}
			node->next = anker->next;
			anker->next = node;
			anker = node;
		}
	}
}

bool RingPuffer::search(string data, RingNode &node)
{
	if (anker != nullptr) {
		RingNode *temp = anker;
		while (temp->next != nullptr && temp->next != anker) {
			if (temp->symbolicData == data) {
				node = *temp;
				return true;
			}
			temp = temp->next;
		}
		if (anker->symbolicData == data) {
			node = *anker;
			return true;
		}
	}
	return false;
}

void RingPuffer::print()
{
	if (anker == nullptr)
		cout << "Es sind keine Daten gespeichert" << endl;
	else if (anker->next == nullptr)
		cout << "OldAge: 0, Descr: " << anker->description << ", Data: " << anker->symbolicData << endl;
	else {
		int size = anker->next->oldAge; 
		for (int i = 0; i <= size; i++) {
			RingNode *temp = anker;
			while (temp->oldAge != i)
				temp = temp->next;
			cout << "OldAge: " << temp->oldAge << ", Descr: " << temp->description << " Backup, Data: " << temp->symbolicData << endl;
			if (i != size)
				cout << "--------------------------" << endl;
		}
	}
		
}

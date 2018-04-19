#include "List.h"
List::List()
{
	head = new Node;
	tail = new Node;
	_size = 0;
	temp = false;
	head->next = tail;
	tail->prev = head;
}
List::~List()
{
	Node *temp = head;
	Node *temp2;
	if (temp = tail)
		delete temp;
	else {
		while (temp != tail) {
			temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
		delete tail;
	}
}
void List::InsertFront(int key)
{
	Node *temp = new Node(key);
	temp->prev = head;
	temp->next = head->next;
	head->next->prev = temp;
	head->next = temp;
	_size++;
}
void List::InsertBack(int key)
{
	Node *temp = new Node(key);
	temp->prev = tail->prev;
	temp->next = tail;
	tail->prev->next = temp;
	tail->prev = temp;
	_size++;
}
bool List::getFront(int & key)
{
	if (_size == 0)
		return false;
	else {
		key = head->next->key;
		Node *temp = head->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		_size--;
		return true;
	}
}
bool List::getBack(int & key)
{
	if (_size == 0)
		return false;
	else {
		key = tail->prev->key;
		Node *temp = tail->prev;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		_size--;
		return true;
	}
}
bool List::del(int key)
{
		if (_size == 0)
			return false;
		else {
			Node *temp = head->next;
			Node *temp2;
			bool found = false;
			for (int i = 0; i < _size; i++) {
				if (temp->key == key) {
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					temp2 = temp;
					temp = temp->next;
					delete temp2;
					_size--;
					found = true;
				}
				else {
					temp = temp->next;
				}
			}
			if (found)
				return true;
			else
				return false;
		}
}
bool List::search(int key)
{
	Node *temp = head->next;
	for (int i = 0; i < _size; i++) {
		if (temp->key == key) {
			return true;
		}
		else {
			temp = temp->next;
		}
	}
	return false;

}
bool List::swap(int key1, int key2)
{
	if (_size == 0)
		return false;
	else {
		Node *temp = head->next;
		Node *temp2 = head->next;
		for (int i = 0; i < _size; i++) {
			if (temp->key == key1) {
				for (int z = 0; z < _size; z++) {
					if (temp2->key == key2) {
						Node *temp3;
						temp->prev->next = temp2;
						temp2->prev->next = temp;
						temp->next->prev = temp2;
						temp2->next->prev = temp;
						temp3 = temp->prev;
						temp->prev = temp2->prev;
						temp2->prev = temp3;
						temp3 = temp->next;
						temp->next = temp2->next;
						temp2->next = temp3;
						return true;
					}
					else {
						temp2 = temp2->next;
					}
				}
				return false;
			}
			else {
				temp = temp->next;
			}
		}
		return false;
	}
}
int List::size(void)
{
	return _size;
}
bool List::test(void)
{
	Node *temp = head;
	for (int i = 0; i <= 0; i++) {
		if (temp == nullptr)
			return false;
		else
			temp = temp->next;
	}
	for (int i = 0; i <= 0; i++) {
		if (temp == nullptr)
			return false;
		else
			temp = temp->prev;
	}
	return true;
}

void List::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	_form.start = start;
	_form.zwischen = zwischen;
	_form.ende = ende;
}

List & List::operator = (const List & _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;	//  !! keine Aktion notwendig
	Node * tmp_node;
	if (_size)
	{
		Node * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventüll vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}
	tmp_node = _List.head->next;
	while (tmp_node != _List.tail)
	{
		InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List.temp) delete & _List;		// ist die übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

List & List::operator = (const List * _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;	//  !! keine Aktion notwendig
	Node * tmp_node;
	if (_size)
	{
		Node * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventüll vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}
	tmp_node = _List->head->next;
	while (tmp_node != _List->tail)
	{
		InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List->temp) delete _List;		// ist die übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

List & List::operator + (const List & List_Append)
{
	Node * tmp_node;
	List * tmp;
	if (temp) {								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List;						// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;					// Merker setzten, dass es sich um eine temporäre Liste handelt
		tmp_node = head->next;
		while (tmp_node != tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append._size) {				// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append.head->next;
		while (tmp_node != List_Append.tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append.temp) delete & List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht							// 
	return *tmp;
}

List & List::operator + (const List * List_Append)
{
	Node * tmp_node;
	List * tmp;
	if (temp) {								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List;						// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;					// Merker setzten, dass es sich um eine temporäre Liste handelt
		tmp_node = head->next;
		while (tmp_node != tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->_size) {				// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append->head->next;
		while (tmp_node != List_Append->tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->temp) delete List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht							// 
	return *tmp;
}

std::ostream & operator<<(std::ostream  & stream, List const & Liste)
{
	stream << Liste._form.start;
	for (Node * tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	if (Liste.temp) delete & Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

std::ostream & operator << (std::ostream & stream, List const * Liste)
{
	stream << Liste->_form.start;
	for (Node * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	if (Liste->temp) delete Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

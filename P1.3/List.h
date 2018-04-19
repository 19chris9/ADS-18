#pragma once
#ifndef _LIST_H
#define _LIST_H
#include "Node.h"
#include <string>
#include <iostream>

template <class T>
class List
{
	/*
	Die Klasse List dient zur Verwaltung von Knoten (Node). Mit Hilfe der Klasse List
	kann ein Stapel oder Warteschlange realisiert werden.
	*/
private:
	struct form { std::string start = "<< "; std::string zwischen = ", "; std::string ende = " >>\n"; } _form;
	Node<T> * head, *tail;			// Zeiger auf Kopf- und End-Element
	int _size;						// Länge der Kette
	bool temp;						// normalerweise false; ist true, wenn es sich um eine temoräre Liste handelt
									// die innerhalb der überladenen Operatoren angelegt wird
public:
	List();
	~List();
	void InsertFront(T key);		// Einfügen eines Knotens am Anfang
	void InsertBack(T key);		// Einfügen eines Knotesn am Ende
	bool getFront(T & key);		// Entnehmen eines Knoten am Anfang
	bool getBack(T & key);		// Entnehmen eines Knoten am Ende
	bool del(T key);				// löschen eines Knotens [key]
	bool search(T key);			// Suchen eines Knoten
	bool swap(T key1, T key2);	// Knoten in der Liste vertauschen
	int size(void);					// Größe der Lise (Anzahl der Knoten)
	bool test(void);				// Überprüfen der Zeigerstruktur der Liste
	void format(const std::string & start, const std::string & zwischen, const std::string & ende);	// Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
	List<T> & operator = (const List<T> & _List);						// Zuweisungsoperator definieren
	List<T> & operator = (const List<T> * _List);						// Zuweisungsoperator definieren
	List<T> & operator + (const List<T> & List_Append);					// Listen zusammenführen zu einer Liste
	List<T> & operator + (const List<T> * List_Append);					// Listen zusammenführen zu einer Liste
	template <typename Tf>
	friend std::ostream & operator << (std::ostream & stream, const List<Tf> & Liste);		// Ausgabeoperator überladen
	template <typename Tf>
	friend std::ostream & operator << (std::ostream & stream, const List<Tf> * Liste);		// Ausgabeoperator überladen
};

template <class T>
List<T>::List()
{
	head = new Node<T>;
	tail = new Node<T>;
	_size = 0;
	temp = false;
	head->next = tail;
	tail->prev = head;
}
template <class T>
List<T>::~List()
{
	Node<T> *temp = head;
	Node<T> *temp2;
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
template <class T>
void List<T>::InsertFront(T key)
{
	Node<T> *temp = new Node<T>(key);
	temp->prev = head;
	temp->next = head->next;
	head->next->prev = temp;
	head->next = temp;
	_size++;
}
template <class T>
void List<T>::InsertBack(T key)
{
	Node<T> *temp = new Node(key);
	temp->prev = tail->prev;
	temp->next = tail;
	tail->prev->next = temp;
	tail->prev = temp;
	_size++;
}
template <class T>
bool List<T>::getFront(T & key)
{
	if (_size == 0)
		return false;
	else {
		key = head->next->key;
		Node<T> *temp = head->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		_size--;
		return true;
	}
}
template <class T>
bool List<T>::getBack(T & key)
{
	if (_size == 0)
		return false;
	else {
		key = tail->prev->key;
		Node<T> *temp = tail->prev;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		_size--;
		return true;
	}
}
template <class T>
bool List<T>::del(T key)
{
	if (_size == 0)
		return false;
	else {
		Node<T> *temp = head->next;
		Node<T> *temp2;
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
template <class T>
bool List<T>::search(T key)
{
	Node<T> *temp = head->next;
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
template <class T>
bool List<T>::swap(T key1, T key2)
{
	if (_size == 0)
		return false;
	else {
		Node<T> *temp = head->next;
		Node<T> *temp2 = head->next;
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
template <class T>
int List<T>::size(void)
{
	return _size;
}
template <class T>
bool List<T>::test(void)
{
	Node<T> *temp = head;
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

template <class T>
void List<T>::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	_form.start = start;
	_form.zwischen = zwischen;
	_form.ende = ende;
}

template <class T>
List<T> & List<T>::operator = (const List<T> & _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;	//  !! keine Aktion notwendig
	Node<T> * tmp_node;
	if (_size)
	{
		Node<T> * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this löschen
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
	if (_List.temp) delete & _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

template <class T>
List<T> & List<T>::operator = (const List<T> * _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;	//  !! keine Aktion notwendig
	Node<T> * tmp_node;
	if (_size)
	{
		Node<T> * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this löschen
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
	if (_List->temp) delete _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

template <class T>
List<T> & List<T>::operator + (List<T> const & List_Append)
{
	Node<T> * tmp_node;
	List * tmp;
	if (temp) {								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List<T>;					// this ist keine temporäre Liste -> Kopie erzeugen
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

template <class T>
List<T> & List<T>::operator + (List<T> const * List_Append)
{
	Node<T> * tmp_node;
	List * tmp;
	if (temp) {								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List<T>;					// this ist keine temporäre Liste -> Kopie erzeugen
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


template <class Tf>
std::ostream & operator << (std::ostream  & stream, const List<Tf> & Liste)
{
	stream << Liste._form.start;
	for (Node<Tf> * tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	if (Liste.temp) delete & Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

template <class Tf>
std::ostream & operator << (std::ostream  & stream, const List<Tf> * Liste)
{
	stream << Liste->_form.start;
	for (Node<Tf> * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	if (Liste->temp) delete Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

#endif

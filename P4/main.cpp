#include "Graph.h"
#include <iostream>

using namespace std;


int main()
{
	Graph g;
	while (true)
	{
		int eingabe;
		cout << "1. Graph einlesen" << endl;
		cout << "2. Tiefensuche" << endl;
		cout << "3. Breitensuche" << endl;
		cout << "4. Prim" << endl;
		cout << "5. Kruskal" << endl;
		cout << "6. Graph ausgeben" << endl;
		cout << "7. Programm beenden" << endl;
		cin >> eingabe;
		double result;
		switch (eingabe) {
		case 1: 
			g.init("graph1.txt");
			break;
		case 2:
			if (g.tiefensuche())
				cout << "Alle Knoten sind verbunden." << endl;
			else
				cout << "Es sind nicht alle Knoten verbunden." << endl;
			break;
		case 3:
			if (g.breitensuche())
				cout << "Alle Knoten sind verbunden." << endl;
			else
				cout << "Es sind nicht alle Knoten verbunden." << endl;
			break;
		case 4:
			result = g.prim(3);
			cout << result << endl;
			break;
		case 5:
			result = g.kruskal();
			cout << result << endl;
			break;
		case 6:
			g.print();
			break;
		case 7:
			return 0;
		}
	}
}
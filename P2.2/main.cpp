#include <iostream>
#include <fstream>
#include "Tree.h"

using namespace std;



int main()
{
	Tree tree;
	while (true) {
		int eingabe;
		cout << "==================================== \nBinaerbaum \n==================================== \n1) Datensatz einfuegen, manuell\n2) Datensatz einfuegen, CSV Datei \n3) Datensatz loeschen \n4) Suchen \n5) Datenstruktur anzeigen " << endl;
		do {
			cout << "?> ";
			cin >> eingabe;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (eingabe < 1 || eingabe > 5);

		if (eingabe == 1) {
			string name;
			int alter, plz;
			double einkommen;
			cout << "+ Bitte geben Sie die den Datensatz ein\nName ?> ";
			getline(cin, name); cout << "Alter ?> "; cin >> alter; cout << "Einkommen => "; cin >> einkommen;
			cout << "PLZ ?> "; cin >> plz;
			tree.add(name, alter, einkommen, plz);
			cout << "+ Ihr Datensatz wurde eingefuegt" << endl;
		}
		if (eingabe == 2) {
			char eingabe;
			cout << "+ Moechten Sie die Daten aus der Datei 'ExportZielanalyse.csv' importieren (j/n) ?> ";
			cin >> eingabe;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (eingabe == 'j') {
				ifstream text;
				text.open("ExportZielanalyse.csv", ios::in);
				string t = "";
				int z = 0;
				string name; int alter, plz; double einkommen;
				while (getline(text, t, ';')) {
					if (z == 0) {
						name = t;
						z++;
					}
					else if (z == 1) {
						alter = stoi(t);
						z++;
					}
					else if (z == 2) {
						einkommen = stoi(t);
						z++;
						getline(text, t, '\n');
						plz = stoi(t);
						z = 0;
						tree.add(name, alter, einkommen, plz);
					}
				}
			}
		}
		if (eingabe == 3) {
			int eingabe;
			cout << "+ Bitte geben Sie den zu löschenden Datensatz an \nPosID ?> ";
			cin >> eingabe;
			tree.del(eingabe);
		}
		if (eingabe == 4) {
			string eingabe;
			cout << "+ Bitte geben Sie den zu suchenden Datensatz an \nName ?> ";
			getline(cin, eingabe);
			cout << "+ Fundstellen:" << endl;
			tree.search(eingabe);
		}
		if (eingabe == 5) {
			tree.print();
		}
	}

	system("PAUSE");
	return 0;
}


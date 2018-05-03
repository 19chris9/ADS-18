#include <iostream>
#include "RingPuffer.h"

using namespace std;

int main()
{
	RingPuffer Ring;
	while (true) {
		int eingabe;
		cout << "================================== \n RingPuffer\n==================================" << endl;
		cout << "1) Backup einfuegen\n2) Backup suchen\n3) Alle Backups ausgeben\n?> ";
		cin >> eingabe;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (eingabe == 1) {
			string desc, data;
			cout << "+Neuen Datensatz einfuegen \nBeschreibung ?> ";
			getline(cin, desc);
			cout << "Daten ?> ";
			getline(cin, data);
			Ring.addNode(desc, data);
			cout << "+Ihr Datensatz wurde hinzugefuegt." << endl;
		}
		else if (eingabe == 2) {
			string data;
			cout << "+Nach welchen Daten soll gesucht werden? \n ?> ";
			getline(cin, data);
			RingNode temp;
			if (Ring.search(data, temp))
				cout << "+ Gefunden in Backup: OldAge " << temp.getAge() << ", Beschreibung: " << temp.getDescription() << ", Daten: " << temp.getData() << endl;
			else
				cout << "+ Datensatz konnte nicht gefunden werden." << endl;
		}
		else {
			Ring.print();
			cout << endl;
			system("PAUSE");
		}
	}

	system("PAUSE");
	return 0;
}
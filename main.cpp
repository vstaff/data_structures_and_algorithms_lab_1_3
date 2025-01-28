#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <vector>

#include "Group.h";
#include "FIO.h";
#include "Item.h";
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	string line;

	ifstream in("./input.txt");

	if (!in.is_open()) {
		cout << "hasn't found the file";
		return 0;
	}

	vector<Item> items;
	unsigned int row = 0;

	while (getline(in, line)) {
		++row;

		string key1String = line.substr(0, 5);
		string key2String = line.substr(6, line.size());

		Group group = getGroup(key1String);
		FIO fio = getFIO(key2String);

		Item item(group, fio, row);
		items.push_back(item);
	}

	cout << "here is vector\n";

	for (Item item : items) {
		cout << item << endl;
	}

	Group g1 = items[0].key1;
	Group g2 = items[6].key1;

	//cout << g1 == g2;
	

	if (g1 < g2) {
		"asdf";
	}

	return 0;
}
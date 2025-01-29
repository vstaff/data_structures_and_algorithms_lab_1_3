#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <vector>

#include "Group.h";
#include "FIO.h";
#include "Item.h";

#include "sorts.h";
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	string line;

	ifstream in("input5.txt");

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

	cout << "now let's try insertion sort (first key in decreasing order, second key in increasing order)\n";
	insertionSort(items);

	for (Item item : items) {
		cout << item << endl;
	}

	return 0;
}
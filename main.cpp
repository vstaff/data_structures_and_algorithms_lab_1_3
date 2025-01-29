#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <vector>
#include <time.h>

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

	int n;
	cout << "type n: ";
	cin >> n;

	vector<Item> items;
	unsigned int row = 0;

	while (getline(in, line) && (row < n)) {
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
	
	clock_t start = clock();
	vector<Item> items_insertion_sort = insertionSort(items);
	clock_t end = clock();

	double result = (double)(end - start) / CLOCKS_PER_SEC;
	
	// запись отсортированного (с помощью сортировки простыми вставками) вектора в файл
	ofstream out;
	out.open("input5_insertion_sort_output.txt");

	if (!out.is_open()) {
		cout << "не получается открыть файл для записи\n";
		return 0;
	}

	for (Item item : items_insertion_sort) {
		out << item << endl;
	}
	out << result;
	out.close();

	cout << "now let's try shell sort (first key in decreasing order, second key in increasing order)\n";

	start = clock();
	vector<Item> items_shell_sort = shellSort(items);
	end = clock();

	result = (double)(end - start) / CLOCKS_PER_SEC;

	// запись отсортированного (с помощью сортировки шелла) вектора в файл
	out.open("input5_shell_sort_output.txt");

	if (!out.is_open()) {
		cout << "не получается открыть файл для записи\n";
		return 0;
	}

	for (Item item : items_shell_sort) {
		out << item << endl;
	}
	out << result;
	out.close();

	cout << "vector is still the same:\n";

	for (Item item : items) { cout << item << endl; }

	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <vector>
#include <time.h>

#include "Group.h"
#include "FIO.h"
#include "Item.h"

#include "util.h"

#include "sorts.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	// тестим генерацию файла случайных данных 
	srand(time(0));
	ofstream randomItems("random_items.txt");

	getRandomItems(5000, randomItems);
	randomItems.close();

	ifstream in("random_items.txt");

	if (!in.is_open()) {
		cout << "не получилось открыть файл\n";
		return 0;
	}

	string line;
	int n;
	cout << "type n: ";
	cin >> n;

	vector<Item> items;
	unsigned int row = 0;

	while (getline(in, line) && row < n) {
		++row;

		string key1String = line.substr(0, 5);
		string key2String = line.substr(6, line.size());

		Group group = getGroup(key1String);
		FIO fio = getFIO(key2String);

		Item item(group, fio, row);
		items.push_back(item);
	}

	in.close();

	cout << "now let's try insertion sort (first key in decreasing order, second key in increasing order)\n";

	clock_t start = clock();
	vector<Item> items_insertion_sort = insertionSort(items);
	clock_t end = clock();

	double result = (double)(end - start) / CLOCKS_PER_SEC;

	// запись отсортированного (с помощью сортировки простыми вставками) вектора в файл
	ofstream out;
	out.open("random_items_insertion_sort_output.txt");

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
	out.open("random_items_shell_sort_output.txt");

	if (!out.is_open()) {
		cout << "не получается открыть файл для записи\n";
		return 0;
	}

	for (Item item : items_shell_sort) {
		out << item << endl;
	}
	out << result;
	out.close();

	return 0;
}
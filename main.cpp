#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	string line;

	ifstream in("./input.txt");

	if (!in.is_open()) {
		cout << "hasn't found the file";
		return 0;
	}

	while (getline(in, line)) {
		cout << line << endl;
	}

	return 0;
}
#ifndef UTIL
#define UTIL

#include <iostream>
#include <vector>
#include <random>
#include "Group.h";
#include "FIO.h";
#include "Item.h";
#include <fstream>

int getRandomIntegerInRange(const int min, const int max) {
	if (max <= min) {
		throw "max must be greater than min!\n";
	}

	return rand() % (max - min + 1) + min;
}

void writeRandomItem(const unsigned int itemsAmount, ofstream& randomItemsFile) {
	Degree degree = N;

	int degreeChoice = getRandomIntegerInRange(0, 2);

	switch (degreeChoice) {
	case 0:
		degree = B;
		break;
	case 1:
		degree = M;
		break;
	case 2:
		degree = S;
		break;
	}

	unsigned int number[4];

	for (int i = 0; i < 4; ++i) {
		number[i] = getRandomIntegerInRange(0, 9);
	}

	Group group(degree, number);

	ifstream familii_file("familii.txt");
	ifstream imena_file("imena.txt");
	ifstream otchestva_file("otchestva.txt");

	string familii[8];
	string imena[8];
	string otchestva[8];

	for (int j = 0; j < 8; ++j) {
		string f;
		getline(familii_file, f);
		familii[j] = f;

		string i;
		getline(imena_file, i);
		imena[j] = i;

		string o;
		getline(otchestva_file, o);
		otchestva[j] = o;
	}

	string f = familii[getRandomIntegerInRange(0, 7)];
	string i = imena[getRandomIntegerInRange(0, 7)];
	string o = otchestva[getRandomIntegerInRange(0, 7)];

	FIO fio(f, i, o);

	randomItemsFile << group << ' ' << fio.stringify();
}

void getRandomItems(const unsigned int itemsAmount, ofstream& randomItemsFile) {
	for (int _ = 0; _ < itemsAmount; ++_) {
		writeRandomItem(itemsAmount, randomItemsFile);
		if (_ + 1 != itemsAmount) {
			randomItemsFile << "\n";
		}
	}
}

#endif 
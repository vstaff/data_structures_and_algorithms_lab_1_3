#ifndef SORTS
#define SORTS

#include <iostream>
#include <vector>
#include "Item.h";
using namespace std;

// ������ ���������� - �������� ��������� (�� �������� ������� �����, �� ����������� ������� �����)
template <typename T>
void insertionSort(vector<T>& v) {
	// ������ ���������� �������� � ��������������� ����� ������� 
	int lastIndexInSorted = 0;
	for (int i = 1; i < v.size(); ++i) {
		// ������� ������� � ����������������� ����� ������� (�������)
		T currentInOrigin = v.at(i);
		int oldI = i;

		for (int j = lastIndexInSorted; j > -1; --j) {
			T currentInSorted = v.at(j);

			/*if (currentInSorted < currentInOrigin) {*/
			if (v.at(j) < v.at(i)) {
				T copy = v[i];

				v[i] = v[j];
				v[j] = copy;

				--i;
			}

			/*else if (currentInOrigin == currentInSorted) {*/
			else if (v.at(i) == v.at(j)) {
				--i;
				continue;
			}

			else {
				break;
			}
		}

		i = oldI;
		lastIndexInSorted = i;
	}
}

#endif
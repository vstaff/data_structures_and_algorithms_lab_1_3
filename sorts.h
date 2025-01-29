#ifndef SORTS
#define SORTS

#include <iostream>
#include <vector>
#include "Item.h";
using namespace std;

// первая сортировка - простыми вставками (по убыванию первого ключа, по возрастанию второго ключа)
template <typename T>
vector<T> insertionSort(vector<T> v, int step=1) {
	// индекс последнего элемента в отсортированной части массива 
	int lastIndexInSorted = 0;
	for (int i = 1; i < v.size(); i += step) {
		// текущий элемент в неотсортированной части массива (вектора)
		T currentInOrigin = v.at(i);
		int oldI = i;

		for (int j = lastIndexInSorted; j > -1; j -= step) {
			T currentInSorted = v.at(j);

			/*if (currentInSorted < currentInOrigin) {*/
			if (v.at(j) < v.at(i)) {
				T copy = v[i];

				v[i] = v[j];
				v[j] = copy;

				i -= step;
			}

			/*else if (currentInOrigin == currentInSorted) {*/
			else if (v.at(i) == v.at(j)) {
				i -= step;
				continue;
			}

			else {
				break;
			}
		}

		i = oldI;
		lastIndexInSorted = i;
	}

	return v;
}

template <typename T>
vector<T> shellSort(vector<T> v) {
	int d = v.size() / 2;

	while (d > 0) {
		v = insertionSort(v, d);
		d /= 2;
	}

	return v;
}

#endif
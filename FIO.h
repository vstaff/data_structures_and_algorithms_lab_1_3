#ifndef FIO_
#define FIO_

#include <iostream>
using namespace std;

int MAX_LENGTH = -INFINITY;

void setMaxLength(string str) {
	if (str.size() > MAX_LENGTH) {
		MAX_LENGTH = str.size();
	}
}

class FIO {
public:
	string f;
	string i;
	string o;

	FIO() {
		f = "нет фамилии";
		i = "нет имени";
		o = "нет отчества";
	}

	FIO(string p_f, string p_i, string p_o) {
		f = p_f;
		i = p_i;
		o = p_o;

		setMaxLength(f + ' ' + i + ' ' + o);
	}

	friend bool operator== (const FIO& fio1, const FIO& fio2) {
		return (fio1.f + fio1.i + fio1.o) == (fio2.f + fio2.i + fio2.o);
	}

	friend bool operator!= (const FIO& fio1, const FIO& fio2) {
		return (fio1.f + fio1.i + fio1.o) != (fio2.f + fio2.i + fio2.o);
	}

	friend bool operator> (const FIO& fio1, const FIO& fio2) {
		return (fio1.f + fio1.i + fio1.o) > (fio2.f + fio2.i + fio2.o);
	}

	friend bool operator< (const FIO& fio1, const FIO& fio2) {
		return (fio1.f + fio1.i + fio1.o) < (fio2.f + fio2.i + fio2.o);
	}
};

FIO getFIO(string line) {
	int f_borders[2] = { 0, 0, };
	int i_borders[2] = { 0, 0, };
	int o_borders[2] = { 0, line.size(),};

	int k = 0;

	for (int j = 0; j < line.size(); ++j) {
		char currentSymbol = line.at(j);

		if (currentSymbol == ' ') {
			if (k == 0) {
				f_borders[1] = j;
				i_borders[0] = j + 1;
			}

			else if (k == 1) {
				i_borders[1] = j;
				o_borders[0] = j + 1;
				break;
			}

			k++;
		}
	}
	string f = line.substr(f_borders[0], f_borders[1]);
	string i = line.substr(i_borders[0], i_borders[1] - i_borders[0]);
	string o = line.substr(o_borders[0], o_borders[1] - o_borders[0]);

	return FIO(f, i, o);
}

std::ostream& operator << (std::ostream& os, const FIO& fio) {
	string fioString = fio.f + " " + fio.i + " " + fio.o;
	
	if (fioString.size() < MAX_LENGTH) {
		const int spacesAmount = MAX_LENGTH - fioString.size();
		for (int i = 0; i < spacesAmount; ++i) {
			fioString += ' ';
		}
	}

	return os << fioString;
}

#endif
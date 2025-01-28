#ifndef FIO_
#define FIO_

#include <iostream>
using namespace std;

struct FIO {
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
			}

			k++;
		}
	}

	string f = line.substr(f_borders[0], f_borders[1]);
	string i = line.substr(i_borders[0], i_borders[1]);
	string o = line.substr(o_borders[0], o_borders[1]);

	return FIO(f, i, o);
}

#endif 
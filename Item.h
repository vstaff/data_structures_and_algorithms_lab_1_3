#ifndef ITEM
#define ITEM 

#include "Group.h";
#include "FIO.h";

#include <iostream>

struct Item {
public:
	Group key1;
	FIO key2;
	unsigned int row;

	Item(Group group, FIO fio, unsigned int p_row) {
		key1 = group;
		key2 = fio;
		row = p_row;
	}
};

std::ostream& operator << (std::ostream& os, const Item& item) {
	return os << item.key1 << " " << item.key2 << " " << item.row;
}

#endif ITEM 
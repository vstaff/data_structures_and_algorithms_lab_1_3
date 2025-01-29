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

	friend bool operator== (const Item& item1, const Item& item2) {
		return item1.key1 == item2.key1 && item1.key2 == item2.key2;
	}

	friend bool operator!= (const Item& item1, const Item& item2) {
		return !(item1 == item2);
	}

	friend bool operator< (const Item& item1, const Item& item2) {
		if (item1.key1 < item2.key1) {
			return true;
		}

		if (item1.key1 > item2.key1) {
			return false;
		}

		// смотрим по второму ключу 

		return item1.key2 > item2.key2;
	}

	friend bool operator> (const Item& item1, const Item& item2) {
		return !(item1 < item2);
	}

	
};

std::ostream& operator << (std::ostream& os, const Item& item) {
	return os << item.key1 << " " << item.key2 << " " << item.row;
}

#endif ITEM 
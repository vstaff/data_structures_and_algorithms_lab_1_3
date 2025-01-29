#ifndef GROUP
#define GROUP

#include <iostream>
#include <string>


enum Degree {
    B, // bakalavriat
    M, // magistratura
    S, // specialitet
    N, // not stated 
};


class Group {
public:
    Degree degree;
    unsigned int number[4];

    Group() {
        degree = N;
        
        for (int i = 0; i < 4; ++i) {
            number[i] = 0;
        }
    };

    Group(Degree p_degree, unsigned int p_number[4]) {
        degree = p_degree;

        for (int i = 0; i < 4; ++i) {
            number[i] = p_number[i];
        }
    }

    friend bool operator== (const Group& g1, const Group& g2);
    friend bool operator!= (const Group& g1, const Group& g2); 
    friend bool operator> (const Group& g1, const Group& g2);
    friend bool operator< (const Group& g1, const Group& g2);
};

bool operator== (const Group& g1, const Group& g2) {
    if (g1.degree != g2.degree) {
        return false;
    }

    for (int i = 0; i < 4; ++i) {
        if (g1.number[i] != g2.number[i]) {
            return false;
        }
    }

    return true;
}

bool operator!= (const Group& g1, const Group& g2) {
    return !(g1 == g2);
}

bool operator> (const Group& g1, const Group& g2) {
    if (g1.degree > g2.degree) {
        return true;
    }

    for (int i = 0; i < 4; ++i) {
        if (g1.number[i] < g2.number[i]) {
            return false;
        }

        if (g1.number[i] > g2.number[i]) {
            return true;
        }
    }

    return false;
}

bool operator< (const Group& g1, const Group& g2) {
    if (g1.degree < g2.degree) {
        return true;
    }

    for (int i = 0; i < 4; ++i) {
        if (g1.number[i] > g2.number[i]) {
            return false;
        }

        if (g1.number[i] < g2.number[i]) {
            return true;
        }
    }

    return false;
}

Group getGroup(std::string line) {
    Degree degree = N;

    char lineDegree = line.at(0);

    switch (lineDegree) {
    case 'B':
        degree = B;
        break;
    case 'M':
        degree = M;
        break;
    case 'S':
        degree = S;
        break;
    }

    int unsigned number[4] = { 0, 0, 0, 0, };
    const std::string lineNumber = line.substr(1);
    for (int i = 0; i < 4; ++i) {
        // чтобы преобразовать char в int 
        const unsigned int currentDigit = lineNumber[i] - '0';
        number[i] = currentDigit;
    }

    Group key(degree, number);
    return key;
}

std::ostream& operator << (std::ostream& os, const Group& group) {
    char degree = 'N';

    switch (group.degree) {
    case B:
        degree = 'B';
        break;
    case M:
        degree = 'M';
        break;
    case S:
        degree = 'S';
        break;
    }

    std::string number = "";

    for (int i = 0; i < 4; ++i) {
        number += std::to_string(group.number[i]);
    }

    return os << degree + number;
}

#endif 
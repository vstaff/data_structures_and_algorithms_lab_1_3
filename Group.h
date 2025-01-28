#ifndef GROUP
#define GROUP

#include <iostream>


enum Degree {
    B, // bakalavriat
    M, // magistratura
    S, // specialitet
    N, // not stated 
};

int compare(Group g1, Group g2) {
    if (g1.degree == N || g2.degree == N) {
        throw "degree is not stated";
    }

    if (g1.degree != g2.degree) {
        return (g1.degree > g2.degree) ? 1 : -1;
    }

    for (int i = 0; i < 4; ++i) {
        if (g1.number[i] > g2.number[i]) {
            return 1;
        }
        else if (g1.number[i] < g2.number[i]) {
            return -1;
        }
    }

    return 0;
}


struct Group {
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

    bool operator == (const Group& group) const
    {
        return compare(this, group) == 0;
    }
    bool operator != (const Group& group) const
    {
        return compare(this, group) != 0;
    }
    bool operator > (const Group& group) const
    {
        return compare(this, group) == 1;
    }
    bool operator < (const Group& group) const
    {
        return compare(this, group) == -1;
    }
};

Group getKey(std::string line) {
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



#endif 
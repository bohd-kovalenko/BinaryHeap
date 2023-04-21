#ifndef LAB2_3_DATA_H
#define LAB2_3_DATA_H

#endif //LAB2_3_DATA_H

#include <string>

using namespace std;

struct Data {
    int quality;
    int urgency;
    string category;

    Data();

        bool operator<(const Data &rhs) const;

    bool operator>(const Data &rhs) const;

    bool operator<=(const Data &rhs) const;

    bool operator>=(const Data &rhs) const;

    bool operator==(const Data &rhs) const;

    bool operator!=(const Data &rhs) const;

};
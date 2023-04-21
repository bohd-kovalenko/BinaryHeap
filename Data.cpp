#include "Data.h"

Data::Data() {
    string a[] = {"clothing", "beverage", "home and garden",
                  "electronics", "sports and outdoor", "automotive"};
    category = a[rand() % 6];
    urgency = rand() % 11;
    quality = rand() % 11;
}

bool Data::operator==(const Data &rhs) const {
    return urgency == rhs.urgency;
}

bool Data::operator!=(const Data &rhs) const {
    return !(rhs == *this);
}

bool Data::operator<(const Data &rhs) const {
    return urgency < rhs.urgency;
}

bool Data::operator>(const Data &rhs) const {
    return rhs < *this;
}

bool Data::operator<=(const Data &rhs) const {
    return !(rhs < *this);
}

bool Data::operator>=(const Data &rhs) const {
    return !(*this < rhs);
}

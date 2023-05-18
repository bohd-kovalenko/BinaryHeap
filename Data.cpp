#include "Data.h"

Data::Data() {
    string a[] = {"clothing", "beverage", "home and garden",
                  "electronics", "sports and outdoor", "automotive"};
    category = a[rand() % 6];
    urgency = rand();
    quality = rand();
}


bool Data::operator<(const Data &rhs) const {
    if (quality < rhs.quality)
        return true;
    if (rhs.quality < quality)
        return false;
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

bool Data::operator==(const Data &rhs) const {
    return quality == rhs.quality &&
           urgency == rhs.urgency;
}

bool Data::operator!=(const Data &rhs) const {
    return !(rhs == *this);
}

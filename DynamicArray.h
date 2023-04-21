#ifndef LAB2_3_DYNAMICARRAY_H
#define LAB2_3_DYNAMICARRAY_H

#endif //LAB2_3_DYNAMICARRAY_H

#include "Data.h"
#include <stdexcept>

struct DynamicArray {
    Data *array;
    double fillIndex;
    int elementsCount;
    int capacity;

    explicit DynamicArray();

    void expandArray();

    void push_back(const Data &data);

    Data pop_back();

    Data get(int index) const;

    int size() const;

    void clear();

    void set(const Data &data, int index);
    void swap(int firstIndex, int secondIndex);

    virtual ~DynamicArray();
};
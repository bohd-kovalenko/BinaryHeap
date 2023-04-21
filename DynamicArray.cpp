#include "DynamicArray.h"

DynamicArray::DynamicArray() {
    fillIndex = 2;
    elementsCount = 0;
    capacity = 3;
    array = new Data[capacity];
}

void DynamicArray::expandArray() {
    int oldCapacity = capacity;
    capacity = (int) (capacity * fillIndex);
    Data *newArray = new Data[capacity];
    for (int i = 0; i < oldCapacity; i++) {
        newArray[i] = array[i];
    }
//    memmove(newArray, array, oldCapacity * sizeof(Data));
    delete[] array;
    array = newArray;
}

void DynamicArray::push_back(const Data &data) {
    if (elementsCount >= capacity) {
        expandArray();
    }
    array[elementsCount++] = data;
}

Data DynamicArray::pop_back() {
    if (size() > 0) {
        Data data = array[size() - 1];
        elementsCount--;
        return data;
    }
    throw out_of_range("Array has no elements");
}

Data DynamicArray::get(int index) const {
    if (index < 0 || index >= elementsCount) {
        throw out_of_range("Non-existent index was provided");
    }
    return array[index];
}

int DynamicArray::size() const {
    return elementsCount;
}

void DynamicArray::clear() {
    elementsCount = 0;
    capacity = 0;
    delete[] array;
    array = nullptr;
}

void DynamicArray::set(const Data &data, int index) {
    array[index] = data;
}

DynamicArray::~DynamicArray() {
    clear();
}

void DynamicArray::swap(int firstIndex, int secondIndex) {
    Data first = array[firstIndex],
            second = array[secondIndex];
    array[firstIndex] = second;
    array[secondIndex] = first;
}



#include <stdexcept>
#include "BinaryHeap.h"

int BinaryHeap::getParent(int index) {
    return (index - 1) / 2;
}

int BinaryHeap::getLeftChild(int index) {
    return 2 * index + 1;
}

int BinaryHeap::getRightChild(int index) {
    return 2 * index + 2;
}

void BinaryHeap::insert(const Data &data) {
    array.push_back(data);
    siftUp(array.size() - 1);
}

void BinaryHeap::removeTopElement() {
    if (array.size() == 0) throw out_of_range("No elements in binary heap");
    swap(array[0], array[array.size() - 1]);
    array.pop_back();
    siftDown(0);
}

void BinaryHeap::siftUp(int index) {
    int childIndex = index, parentIndex = getParent(index);
    if (index > 0 && array[childIndex] > array[parentIndex]) {
        swap(array[childIndex], array[parentIndex]);
        siftUp(parentIndex);
    }
}

void BinaryHeap::siftDown(int index) {
    if (getLeftChild(index) >= array.size()) return;
    int parentIndex = index, maxChildIndex;
    if (getRightChild(index) == array.size()) {
        maxChildIndex = getLeftChild(index);
    } else {
        maxChildIndex = array[getLeftChild(index)] > array[getRightChild(index)]
                        ? getLeftChild(index)
                        : getRightChild(index);
    }
    if (maxChildIndex <= array.size() && array[parentIndex] < array[maxChildIndex]) {
        swap(array[parentIndex], array[maxChildIndex]);
        siftDown(maxChildIndex);
    }
}

void BinaryHeap::upgradedSiftDown(int *array, int arraySize, int index) {
    int parentIndex = index, maxChildIndex =
            getRightChild(index) >= arraySize || array[getLeftChild(index)] > array[getRightChild(index)]
            ? getLeftChild(index) : getRightChild(index);
    if (maxChildIndex < arraySize && array[parentIndex] < array[maxChildIndex]) {
        swap(array[parentIndex], array[maxChildIndex]);
        upgradedSiftDown(array, arraySize, maxChildIndex);
    }
}

void BinaryHeap::upgradedSiftDownVector(vector<int> &array, int arraySize, int index) {
    int parentIndex = index, maxChildIndex =
            getRightChild(index) >= arraySize || array[getLeftChild(index)] > array[getRightChild(index)]
            ? getLeftChild(index)
            : getRightChild(index);
    if (maxChildIndex < arraySize && array[parentIndex] < array[maxChildIndex]) {
        swap(array[parentIndex], array[maxChildIndex]);
        upgradedSiftDownVector(array, arraySize, maxChildIndex);
    }
}


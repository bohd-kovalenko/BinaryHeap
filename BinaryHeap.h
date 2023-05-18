#ifndef LAB2_3_BINARYHEAP_H
#define LAB2_3_BINARYHEAP_H

#endif //LAB2_3_BINARYHEAP_H

#include "Data.h"
#include "vector"


struct BinaryHeap {
    vector <Data> array;

    int getParent(int index);

    int getLeftChild(int index);

    int getRightChild(int index);

    void siftUp(int index);

    void siftDown(int index);

    void insert(const Data &data);

    void removeTopElement();

    void upgradedSiftDown(int *array, int arraySize, int index);

    void upgradedSiftDownVector(vector<int> &array, int arraySize, int index);
};
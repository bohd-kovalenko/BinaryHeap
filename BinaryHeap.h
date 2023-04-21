#ifndef LAB2_3_BINARYHEAP_H
#define LAB2_3_BINARYHEAP_H

#endif //LAB2_3_BINARYHEAP_H

#include "DynamicArray.h"
#include "vector"


struct BinaryHeap {
//    DynamicArray *array;
    vector<Data> *array;
    virtual ~BinaryHeap();

    BinaryHeap();

    int getParent(int index);

    int getLeftChild(int index);

    int getRightChild(int index);

    void siftUp(int index);

    void siftDown(int index);

    void insert(const Data &data);
    void removeTopElement();
};
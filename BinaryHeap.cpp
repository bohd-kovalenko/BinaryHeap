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

//void BinaryHeap::siftUp(int index) {
//    int parentIndex = getParent(index), childIndex = index;
//    while (childIndex > 0) {
//        if (array.get(childIndex) > array.get(parentIndex)) {
//            array.swap(childIndex, parentIndex);
//        } else break;
//        childIndex = parentIndex;
//        parentIndex = getParent(parentIndex);
//    }
//}
//
//void BinaryHeap::siftDown(int index) {
//    int leftChildIndex = getLeftChild(index),
//            rightChildIndex = getRightChild(index),
//            parentIndex = index,
//            maxChildIndex;
//    while (rightChildIndex < array.size()) {
//        maxChildIndex = array.get(rightChildIndex) > array.get(leftChildIndex) ? rightChildIndex : leftChildIndex;
//        if (array.get(parentIndex) > array.get(maxChildIndex)) break;
//        else array.swap(parentIndex, maxChildIndex);
//        rightChildIndex = getRightChild(maxChildIndex);
//        leftChildIndex = getLeftChild(maxChildIndex);
//        parentIndex = maxChildIndex;
//    }
//}



void BinaryHeap::insert(const Data &data) {
    array.push_back(data);
    siftUp(array.size() - 1);
}

void BinaryHeap::removeTopElement() {
    if (array.size() == 0) throw out_of_range("No elements in binary heap");
    array.swap(0, array.size() - 1);
    array.pop_back();
    siftDown(0);
}

void BinaryHeap::siftUp(int index) {
    int childIndex = index, parentIndex = getParent(index);
    if (index > 0 && array.get(childIndex) > array.get(parentIndex)) {
        array.swap(childIndex, parentIndex);
        siftUp(parentIndex);
    }
}

void BinaryHeap::siftDown(int index) {
    if(getRightChild(index)>=array.size()) return;
    int parentIndex = index,
            maxChildIndex = array.get(getLeftChild(index)) > array.get(getRightChild(index))
                            ? getLeftChild(
                    index) : getRightChild(
                    index);
//maxChildIndex;
//    if(getRightChild(index)<=array.size()&&array.get(getLeftChild(index))>array.get(getRightChild(index))){
//
//    }
    if (maxChildIndex <= array.size() && array.get(parentIndex) < array.get(maxChildIndex)) {
        array.swap(parentIndex, maxChildIndex);
        siftDown(maxChildIndex);
    }
}


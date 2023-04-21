#include "BinaryHeap.h"

BinaryHeap::BinaryHeap() {
//    array = new DynamicArray();
    array = new vector<Data>;
}

int BinaryHeap::getParent(int index) {
    return (index - 1) / 2;
}

int BinaryHeap::getLeftChild(int index) {
    return 2 * index + 1;
}

int BinaryHeap::getRightChild(int index) {
    return 2 * index + 2;
}

void BinaryHeap::siftUp(int index) {
    int parentIndex = getParent(index), childIndex = index;
//    Data parent = array->get(parentIndex);
//    Data child = array->get(childIndex);
    Data parent = array->at(parentIndex);
    Data child = array->at(childIndex);
    while (childIndex > 0 && child > parent) {
//        array->set(child, parentIndex);
//        array->set(parent, childIndex);
        array[parentIndex] = child;
        childIndex = parentIndex;
        parentIndex = getParent(parentIndex);
        parent = array->get(parentIndex);
        child = array->get(childIndex);
    }
}

void BinaryHeap::siftDown(int index) {
    int leftChildIndex = getLeftChild(index),
            rightChildIndex = getRightChild(index),
            parentIndex = index;
    Data leftChild, rightChild;
    while (rightChildIndex < array->size()) {
        rightChild = array->get(rightChildIndex);
        leftChild = array->get(leftChildIndex);
        if (leftChild > rightChild) {
            array->swap(parentIndex, leftChildIndex);
            parentIndex = leftChildIndex;
        } else {
            array->swap(parentIndex, rightChildIndex);
            parentIndex = rightChildIndex;
        }
        rightChildIndex = getRightChild(parentIndex);
        leftChildIndex = getLeftChild(parentIndex);
    }
}


BinaryHeap::~BinaryHeap() {
    delete array;
}

void BinaryHeap::insert(const Data &data) {
    array->push_back(data);
    siftUp((array->size()) - 1);
}

void BinaryHeap::removeTopElement() {
    array->swap(0, array->size() - 1);
    array->pop_back();
    siftDown(0);
}


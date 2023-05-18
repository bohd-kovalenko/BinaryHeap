#include "HeapSort.h"
#include "BinaryHeap.h"

#include <string>

using namespace std;

void HeapSort::buildHeap(int *array, int arraySize) {
    BinaryHeap binaryHeap;
    for (int i = arraySize / 2 - 1; i >= 0; i--) {
        binaryHeap.upgradedSiftDown(array, arraySize, i);
    }
}

void HeapSort::heapSort(int *array, int arraySize) {
    BinaryHeap binaryHeap;
    buildHeap(array, arraySize);
    for (int i = arraySize - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        binaryHeap.upgradedSiftDown(array, i, 0);
    }
}
#include <queue>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "PriorityQueue.h"
#include "HeapSort.h"
#include <algorithm>
#include "FindNSmallestNum.h"

#define elementsCount 10000000

using namespace std;

template<typename T>
float testPriorityQueueSpeed(T &&priorityQueue) {
    const int iters = 100000;
    clock_t timeStart = clock();
    for (int i = 0; i < iters; i++) {
        int insertDataAmount = rand() % 6 + 5;
        for (int j = 0; j < insertDataAmount; j++) {
            priorityQueue.push(Data());
        }
        priorityQueue.top();
        priorityQueue.pop();
    }
    clock_t timeEnd = clock();
    float time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;
    return time;
}

bool testPriorityQueue() {
    srand(time(NULL));
    const int iters = 20000;
    PriorityQueue myPriorQueue;

    priority_queue<Data> stlPriorQueue;
    bool isDataEqual = true;
    for (int i = 0; i < iters; i++) {
        int insertDataAmount = rand() % 6 + 5;
        for (int j = 0; j < insertDataAmount; j++) {
            Data randData = Data();
            myPriorQueue.push(randData);
            stlPriorQueue.push(randData);
        }
        if (!(myPriorQueue.top() == stlPriorQueue.top())) {
            isDataEqual = false;
            cerr << "Comparing failed on iteration " << i << endl << endl;
            break;
        }
        int removeDataAmount = rand() % insertDataAmount;
        for (int j = 0; j < removeDataAmount; j++) {
            myPriorQueue.pop();
            stlPriorQueue.pop();
        }
    }
    int myQueueSize = myPriorQueue.size();
    int stlQueueSize = stlPriorQueue.size();
    float stlTime =
            testPriorityQueueSpeed<priority_queue<Data>>(priority_queue<Data>());
    float myTime = testPriorityQueueSpeed<PriorityQueue>(PriorityQueue());
    cout << "My PriorityQueue:" << endl;
    cout << "Time: " << myTime << ", size: " << myQueueSize << endl;
    cout << "STL priority_queue:" << endl;
    cout << "Time: " << stlTime << ", size: " << stlQueueSize << endl << endl;
    if (isDataEqual && myQueueSize == stlQueueSize) {
        cout << "The lab is completed" << endl << endl;
        return true;
    }
    cerr << ":(" << endl << endl;
    return false;
}

void testHeapSort() {
    int *heapSortArray = new int[elementsCount];
    int *stlSortArray = new int[elementsCount];
    int temp;
    HeapSort sort;
    clock_t startTime, endTime;
    for (int i = 0; i < elementsCount; i++) {
        temp = rand();
        stlSortArray[i] = temp;
        heapSortArray[i] = temp;
    }
    startTime = clock();
    sort.heapSort(heapSortArray, elementsCount);
    endTime = clock();
    cout << "Heap sort did it in " << (endTime - startTime) / CLOCKS_PER_SEC << " secs" << endl;
    startTime = clock();
    std::sort(stlSortArray, stlSortArray + elementsCount);
    endTime = clock();
    cout << "STL sort did it in " << (endTime - startTime) / CLOCKS_PER_SEC << " secs" << endl;
    bool result = std::equal(stlSortArray, stlSortArray + elementsCount, heapSortArray);
    cout << result << endl;
}

int main() {
    testPriorityQueue();
    testHeapSort();
    return 0;
}
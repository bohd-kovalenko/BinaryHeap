#ifndef LAB2_3_PRIORITYQUEUE_H
#define LAB2_3_PRIORITYQUEUE_H

#endif //LAB2_3_PRIORITYQUEUE_H

#include "BinaryHeap.h"

struct PriorityQueue {
    BinaryHeap *heap;

    virtual ~PriorityQueue();

    PriorityQueue();

    void push(const Data &data);

    Data top();

    void pop();

    int size();

    bool empty();

    void clean();
};
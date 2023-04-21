#include "PriorityQueue.h"

bool PriorityQueue::empty() {
    if (heap->array->size() == 0) return true;
    return false;
}

void PriorityQueue::clean() {
    heap->array->clear();
}

int PriorityQueue::size() {
    return heap->array->size();
}

void PriorityQueue::push(const Data &data) {
    heap->insert(data);
}

Data PriorityQueue::top() {
    return heap->array->get(0);
}

void PriorityQueue::pop() {
    heap->removeTopElement();
}

PriorityQueue::~PriorityQueue() {
    delete heap;
}

PriorityQueue::PriorityQueue() {
    heap = new BinaryHeap();
}


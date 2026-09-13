#pragma once
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "University.h"

struct PriorityNode {
    University data;
    double priorityScore;
};

class PriorityQueue {
private:
    PriorityNode* heap;
    int capacity;
    int count;

    void resize() {
        capacity *= 2;
        PriorityNode* newData = new PriorityNode[capacity];
        for (int i = 0; i < count; i++) newData[i] = heap[i];
        delete[] heap;
        heap = newData;
    }

    // Matematiksel Ýliþki: 
    // Sol Çocuk: 2*i + 1 | Sað Çocuk: 2*i + 2 | Ebeveyn: (i-1) / 2
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index].priorityScore > heap[parent].priorityScore) {
                PriorityNode temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            }
            else break;
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < count && heap[left].priorityScore > heap[largest].priorityScore)
            largest = left;
        if (right < count && heap[right].priorityScore > heap[largest].priorityScore)
            largest = right;

        if (largest != index) {
            PriorityNode temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            heapifyDown(largest);
        }
    }

public:
    PriorityQueue() {
        capacity = 30;
        count = 0;
        heap = new PriorityNode[capacity];
    }

    ~PriorityQueue() { delete[] heap; }

    void push(University uni, double score) {
        if (count == capacity) resize();
        heap[count].data = uni;        
        heap[count].priorityScore = score;
        heapifyUp(count);
        count++;
    }

    University pop() {
        if (count == 0) return University();
        University topData = heap[0].data;
        heap[0] = heap[count - 1];
        count--;
        heapifyDown(0);
        return topData;
    }

    bool isEmpty() { return count == 0; }
};

#endif
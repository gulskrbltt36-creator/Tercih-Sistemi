#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "University.h"
#include <iostream>

class DynamicArray {
private:
    University* data;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        University* newData = new University[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray() {
        capacity = 10;
        size = 0;
        data = new University[capacity];
    }

    ~DynamicArray() {
        if (data) delete[] data;
    }

    void add(const University& uni) {
        if (size == capacity) {
            resize();
        }
        data[size] = uni;
        size++;
    }

    University& get(int index) {
        return data[index];
    }

    int getSize() const { return size; }

    int binarySearchByID(int searchID) {
        int left = 0;
        int right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (data[mid].id == searchID) return mid;
            if (data[mid].id < searchID) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
 
    University& getByID(int id) {
        int idx = binarySearchByID(id);
        if (idx != -1) return data[idx];
        static University empty;
        return empty;
    }
};

#endif
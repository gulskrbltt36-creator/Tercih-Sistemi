#pragma once
#ifndef IDLIST_H
#define IDLIST_H

#include <iostream>

class IDList {
private:
    int* data;      // Veriler (Heap'te duracak)
    int capacity;   // Kapasite
    int count;      // Dolu miktar

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    IDList() {
        capacity = 5; // Küçük baþlasýn
        count = 0;
        data = new int[capacity];
    }

    // Copy Constructor (Kopyalama yaparken hata vermesin diye)
    IDList(const IDList& other) {
        capacity = other.capacity;
        count = other.count;
        data = new int[capacity];
        for (int i = 0; i < count; i++) {
            data[i] = other.data[i];
        }
    }

    ~IDList() {
        if (data != nullptr) {
            delete[] data;
        }
    }

    void add(int val) {
        if (count == capacity) {
            resize();
        }
        data[count] = val;
        count++;
    }

    int get(int index) const {
        return data[index];
    }

    int size() const {
        return count;
    }

    // Listeyi baþka bir listenin ucuna ekler (Merge)
    void append(const IDList& other) {
        for (int i = 0; i < other.size(); i++) {
            add(other.get(i));
        }
    }
};

#endif
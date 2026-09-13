#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "University.h"
#include <iostream>
#include <fstream> 

struct Node {
    University data;
    Node* next;
    Node* prev;

    Node(University uni) {
        data = uni;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int count;

    void saveToFile() {
        std::ofstream file("tercihlerim.txt");
        if (!file.is_open()) return;

        Node* temp = head;
        while (temp != nullptr) {
            file << temp->data.id << " "
             << temp->data.name << " "
            << temp->data.department << std::endl;
            temp = temp->next;
        }
        file.close();
    }

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
 
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;                 
            current = nextNode;             
        }
    }

   
    bool isEmpty() { return count == 0; }

    Node* getHead() {
        return head;
    }
   
    bool contains(int id) {
        Node* temp = head; 

        while (temp != nullptr) {
            if (temp->data.id == id) {
                return true; 
            }
            temp = temp->next; 
        }

        return false; 
    }
    
    void add(University uni) {
 
        Node* newNode = new Node(uni);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;

        saveToFile(); 
       
    }

   
    void removeAt(int index) {
        if (index < 1 || index > count) {
            std::cout << "  [HATA] Gecersiz sira numarasi!" << std::endl;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }
        if (temp == head && temp == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else if (temp == head) {
            head = head->next;
            head->prev = nullptr;
        }
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
        count--;
        saveToFile();
    }

    void insertAt(int index, University uni) {
        if (index <= 1) {
         
            Node* newNode = new Node(uni);
            if (head == nullptr) {
                head = tail = newNode;
            }
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            count++;
        }
        else if (index > count) {
            add(uni);
        }
        else {
            
            Node* newNode = new Node(uni);
            Node* temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            newNode->prev = temp->prev;
            newNode->next = temp;
            temp->prev->next = newNode;
            temp->prev = newNode;
            count++;
        }
        saveToFile();
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        tail = nullptr;
        count = 0;

        saveToFile();
    } 

    University get(int index) {
        Node* temp = head;
        for (int i = 1; i < index && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp != nullptr) return temp->data;
        return University(); 
    }

    int getCount() { return count; }

    
    
};

#endif  
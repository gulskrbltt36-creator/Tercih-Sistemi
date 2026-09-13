#pragma once

struct DeletedItem {
    int index; 
    int uniID; 
};

struct StackNode {
    DeletedItem data;
    StackNode* next;
};

class Stack {
private:
    StackNode* top; 

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        
        while (top != nullptr) {
            StackNode* temp = top; 
            top = top->next;       
            delete temp;       
        }
    }

  
    void push(int idx, int id) {
        StackNode* newNode = new StackNode();
        newNode->data = { idx, id };
        newNode->next = top; 
        top = newNode;       
    }


    DeletedItem pop() {
        if (isEmpty()) return { -1, -1 };

        StackNode* temp = top;           
        DeletedItem item = temp->data;    
        top = top->next;                  
        delete temp;                     
        return item;                  
    }

  
    bool isEmpty() {
        return top == nullptr;
    }
};
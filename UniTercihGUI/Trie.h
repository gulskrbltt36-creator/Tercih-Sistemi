#ifndef TRIE_H
#define TRIE_H

#include <string>   
#include "IDList.h"    

struct TrieNode {
    TrieNode* children[256];
    bool isEndOfWord;
    IDList universityIDs;
    

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 256; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

 
    void findSuggestions(TrieNode* node, IDList& results) {
        if (node == nullptr) return;
        if (node->isEndOfWord) {
            results.append(node->universityIDs);
        }
        for (int i = 0; i < 256; i++) {
            if (node->children[i] != nullptr) {
                findSuggestions(node->children[i], results);
            }
        }
    }

    void cleanUp(TrieNode* node) {
        if (node == nullptr) return;

        for (int i = 0; i < 256; i++) {
            if (node->children[i] != nullptr) {
                cleanUp(node->children[i]); 
            }
        }

 
        delete node;
    }

public:
    Trie() {
        root = new TrieNode();

    }

    ~Trie() {
        cleanUp(root); 
    }

    void insert(std::string text, int id) {
        TrieNode* temp = root;
        for (char c : text) {
            if (c >= 'a' && c <= 'z') c -= 32;
            int index = (unsigned char)c;

            if (temp->children[index] == nullptr) {
                temp->children[index] = new TrieNode();
            }
            temp = temp->children[index];
        }
        temp->isEndOfWord = true;
        temp->universityIDs.add(id);
    }

    IDList getSuggestions(std::string prefix) {
        IDList results;
        TrieNode* temp = root;

        for (char c : prefix) {
            if (c >= 'a' && c <= 'z') c -= 32;
            int index = (unsigned char)c;
            if (temp->children[index] == nullptr) {
                return results;
            }
            temp = temp->children[index];
        }

        findSuggestions(temp, results);
        return results;
    }
};

#endif
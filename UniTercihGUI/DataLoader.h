#ifndef DATALOADER_H
#define DATALOADER_H

#include <iostream>
#include <fstream>  
#include <string>
#include <sstream>  
#include "DynamicArray.h"
#include "Trie.h"

using namespace std;

class DataLoader {
public:
    static void loadData(string filename, DynamicArray& array, Trie& trie) {
        ifstream file(filename);

        
        if (!file.is_open()) {
            cerr << "HATA: " << filename << " dosyasi bulunamadi!" << endl;
            cerr << "Lutfen proje klasorune 'universiteler.txt' dosyasini ekleyin." << endl;
            return;
        }

        string line;
        int count = 0;

      
        while (getline(file, line)) {
            if (line.empty()) continue; 

            stringstream ss(line);
            string tempVal;

            int id, rank, quota, lastRank, city;
            double score;
            string name, dept;

            try {
                
                getline(ss, tempVal, '#');
                id = stoi(tempVal);

                getline(ss, name, '#');

                getline(ss, dept, '#');

                getline(ss, tempVal, '#');
                score = stod(tempVal);

                getline(ss, tempVal, '#');
                rank = stoi(tempVal);

                getline(ss, tempVal, '#');
                quota = stoi(tempVal);

                getline(ss, tempVal, '#');
                lastRank = stoi(tempVal);

                getline(ss, tempVal, '#');
                city = stoi(tempVal);

            
                University newUni(id, name, dept, score, rank, quota, lastRank, city);

                array.add(newUni);

                string fullName = name + " " + dept;
                trie.insert(fullName, id);

                trie.insert(dept, id);

                trie.insert(name, id);

                count++;
            }
            catch (...) {
                cerr << "Uyari: Satir okunamadi (Format hatasi olabilir): " << line << endl;
                continue;
            }
        }

        file.close();
   
    }
};

#endif
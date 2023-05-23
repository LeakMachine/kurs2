#pragma once
#include <iostream>
#include <string>
#include "list.h"
#define SIZE 20

class HashTable {
    CList<std::pair<std::string, int>> arr[SIZE];
    int hashFunction(std::pair<std::string, int> _data) {
        int key = 0;
        for (int i = 0; i < _data.first.size(); i++) {
            key += _data.first[i];
        }

        key = key % SIZE;

        key = abs(key);

        return key;
    }
public:
    void insert(std::pair<std::string, int> _data) {

        int key = hashFunction(_data);

        arr[key].push_back(_data);

    }
    bool find(std::pair<std::string, int> _data) {

        int key = hashFunction(_data);

        CList<std::pair<std::string, int>>* arrTemp = new CList<std::pair<std::string, int>>();
        arrTemp->cpy(arr[key]);
        while (!arrTemp->isEmpty()) {
            std::pair<std::string, int> tempData;
            tempData = arrTemp->pop_back();
            if (tempData.first == _data.first) {
                return true;
            }
        }
        return false;
    }
    void remove(std::pair<std::string, int> _data) {
        int key = hashFunction(_data);
        int index = 0;
        CList<std::pair<std::string, int>>* arrTemp = new CList<std::pair<std::string, int>>();
        arrTemp->cpy(arr[key]);
        while (!arrTemp->isEmpty()) {
            if (arrTemp->pop_back() == _data) {
                break;
            }
            index++;
        }
        arr[key].remove(index);
    }

    void print() {
        for (int i = 0; i < SIZE; i++) {
            CList<std::pair<std::string, int>>* arrTemp = new CList<std::pair<std::string, int>>();
            arrTemp->cpy(arr[i]);

            while (!arrTemp->isEmpty()) {
                std::pair<std::string, int> tempData;
                tempData = arrTemp->pop_back();
                std::cout << tempData.first << "   " << tempData.second << std::endl;
            }
        }
    }
};


